#include "cp.h"

//拷贝软链接
int copylink(char path1[], char path2[])
{
	char source[PATH_MAX] = "\0";
	// 获得当前目录
	getcwd(source, PATH_MAX);
	strcat(source, "/");
	strcat(source, path1);
	// 创建软链接
	if (symlink(source, path2) == -1)
	{
		return ERROR_CP;
	}
	// 获取源文件信息
	struct stat statbuf;
	lstat(source, &statbuf);
	// 修改目标文件的时间
	struct timeval timebuf[2];
	timebuf[0].tv_sec = statbuf.st_atime;
	timebuf[0].tv_usec = 0;
	timebuf[1].tv_sec = statbuf.st_mtime;
	timebuf[1].tv_usec = 0;
	lutimes(path2, timebuf);
	return RIGHT;
}
//拷贝文件
int copyfile(char path1[], char path2[])
{
	int f1, f2, n;
	char buf[BUFSIZ]; // 设置缓冲区

	if ((f1 = open(path1, O_RDONLY)) == -1) // 打开源文件失败
	{
		close(f1);
		return ERROR_PATH;
	}
	else // 打开源文件成功
	{
		// 获取源文件的信息
		struct stat statbuf;
		lstat(path1, &statbuf);

		if ((f2 = open(path2, O_CREAT | O_RDWR | O_EXCL, statbuf.st_mode)) == -1) // 创建目标文件失败
		{
			close(f1);
			close(f2);
			return ERROR_TARGET_EXITS;
		}
		else // 创建目标文件成功
		{
			while ((n = read(f1, buf, BUFSIZ)) > 0) // 读取源文件
			{
				if (write(f2, buf, n) != n) // 写入目标文件
				{
					close(f1);
					close(f2);
					return ERROR_IO;
				}
			}
			// 修改目标文件的时间
			struct utimbuf timebuf;
			timebuf.actime = statbuf.st_atime;
			timebuf.modtime = statbuf.st_mtime;
			utime(path2, &timebuf);
		}
	}
	// 关闭文件
	close(f1);
	close(f2);
	return RIGHT;
}
//拷贝目录
int copydir(char source[], char target[])
{
	char path1[PATH_MAX] = "\0";
	char path2[PATH_MAX] = "\0";
	strcpy(path1, source);
	strcpy(path2, target);

	DIR* dp1, * dp2;
	struct stat buf;
	if ((dp1 = opendir(path1)) == NULL) // 打开源文件
	{
		closedir(dp1);
		return ERROR_PATH;
	}
	else if ((dp2 = opendir(path2)) == NULL) // 打开目标文件
	{
		lstat(path1, &buf);
		mkdir(path2, buf.st_mode);

		struct dirent* entry;
		while ((entry = readdir(dp1)) != NULL)
		{
			struct stat statbuf;
			strcat(path1, "/");
			strcat(path1, entry->d_name);
			strcat(path2, "/");
			strcat(path2, entry->d_name);
			// 获得源文件信息
			lstat(path1, &statbuf);
			if (S_ISDIR(statbuf.st_mode)) // 目录
			{
				if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				{
					// 修改目标文件夹的时间
					struct utimbuf timebuf;
					timebuf.actime = buf.st_atime;
					timebuf.modtime = buf.st_mtime;
					utime(path2, &timebuf);
				}
				else
				{
					// 递归拷贝目录
					int result = copydir(path1, path2);
					//拷贝时出错
					if (result != RIGHT)
					{
						closedir(dp1);
						closedir(dp2);
						return result;
					}
				}
			}
			else if (S_ISLNK(statbuf.st_mode)) // 软链接
			{
				int result = copylink(path1, path2);
				//拷贝时出错
				if (result != RIGHT)
				{
					closedir(dp1);
					closedir(dp2);
					return result;
				}
			}
			else // 文件
			{
				int result = copyfile(path1, path2);
				//拷贝时出错
				if (result != RIGHT)
				{
					closedir(dp1);
					closedir(dp2);
					return result;
				}
			}
			strcpy(path1, source);
			strcpy(path2, target);
		}
	}
	else
	{
		// 关闭文件夹
		closedir(dp1);
		closedir(dp2);
		return ERROR_TARGET_EXITS;
	}
	// 修改目标文件夹的时间
	struct utimbuf timebuf;
	timebuf.actime = buf.st_atime;
	timebuf.modtime = buf.st_mtime;
	utime(path2, &timebuf);
	// 关闭文件夹
	closedir(dp1);
	closedir(dp2);
	return RIGHT;
}
//cp命令的主函数
int cp()
{
	if (cmdNum > 3)
		return ERROR_TOO_MANY_PARAMETER;
	else if (cmdNum < 2)
		return ERROR_MISS_PARAMETER;
	else if (!strcmp(commands[1], "-h") || !strcmp(commands[1], "--help"))
	{
		if (cmdNum > 2)
			return ERROR_TOO_MANY_PARAMETER;
		else
		{
			printf("\033[40;31m[Usage]\033[0m");
			printf("\033[40;32m cp [SOURCE] [TARGET]\033[0m\n");
			printf("Copy SOURCE to TARGET.\n");
			printf("  cp %-23s Copy the SOURCE DIRECTORY to the TARGET DIRECTORY\n", "[DIRECTORY] [DIRECTORY]");
			printf("  cp %-23s Copy the SOURCE FILE to the TARGET DIRECTORY\n", "[FILE] [DIRECTORY]");
			printf("  cp %-23s display this help and exit\n", "-h, --help");
		}
		return RIGHT;
	}
	else
	{
		char path1[PATH_MAX] = "\0";
		char path2[PATH_MAX] = "\0";
		struct stat statbuf;
		//复制source和target
		strcpy(path1, commands[1]);
		strcpy(path2, commands[2]);

		if (stat(path1, &statbuf) == -1)
			return ERROR_PATH;
		if (S_ISDIR(statbuf.st_mode)) // source是目录文件
		{
			return copydir(path1, path2);
		}
		else // source是除了目录以外的文件
		{
			if (path2[strlen(path2) - 1] != '/')
				strcat(path2, "/");
			strcat(path2, path1);
			return copyfile(path1, path2);
		}
	}
}