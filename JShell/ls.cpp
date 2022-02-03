#include "ls.h"

char* targetDir = NULL;
const char* permissions[] = { "---", "r--", "-w-", "rw-", "--x", "r-x", "-wx", "rwx" };
//根据文件类型获得列表显示的字符
char fileType(mode_t mode)
{
	if (S_ISDIR(mode))
		return 'd';
	else if (S_ISCHR(mode))
		return 'c';
	else if (S_ISBLK(mode))
		return 'b';
	else if (S_ISFIFO(mode))
		return 'p';
	else if (S_ISLNK(mode))
		return 'l';
	else if (S_ISSOCK(mode))
		return 's';
	else
		return '-';
}
//获得文件权限
const char* getPermission(mode_t code)
{
	switch (code)
	{
	case 1:
		return permissions[1];
	case 2:
		return permissions[2];
	case 3:
		return permissions[3];
	case 4:
		return permissions[4];
	case 5:
		return permissions[5];
	case 6:
		return permissions[6];
	case 7:
		return permissions[7];
	default:
		return permissions[0];
	}
}
//获得文件拥有者的username
const char* getUsername(uid_t uid)
{
	struct	passwd* userInfo;
	if ((userInfo = getpwuid(uid)) == NULL)
		return "Unknown";
	return userInfo->pw_name;
}
//获得文件拥有者的groupname
const char* getGroupname(gid_t gid)
{
	struct	group* group_info;
	if ((group_info = getgrgid(gid)) == NULL)
		return "Unknown";
	return group_info->gr_name;
}

//实现ls和ls -a
//option=1为ls, option=2为ls -a
int ls(int option)
{
	DIR* target;
	struct stat statbuf;
	struct dirent* entry;
	//打开目录失败
	if ((target = opendir(targetDir)) == NULL)
		return ERROR_PATH;
	//遍历目标目录
	chdir(targetDir);
	while ((entry = readdir(target)) != NULL)
	{
		//获取文件信息
		lstat(entry->d_name, &statbuf);
		if (S_ISDIR(statbuf.st_mode)) // 打印目录
		{
			if ((!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) && option == 1) // ls
				continue;
			else // ls -a
				printf("\033[42;37m%s\033[0m  ", entry->d_name);
		}
		else // 打印文件
			printf("\033[40;32m%s\033[0m  ", entry->d_name);
	}
	printf("\n");
	chdir(curPath);
	return RIGHT;
}
//ls -l
int ls_l()
{
	DIR* target;
	struct stat statbuf;
	struct dirent* entry;
	unsigned long long int totalSize = 0;

	//获取目录下所有文件的大小总和
	//打开目录失败
	if ((target = opendir(targetDir)) == NULL)
		return ERROR_PATH;
	//遍历目标目录
	chdir(targetDir);
	while ((entry = readdir(target)) != NULL)
	{
		//获取文件信息
		lstat(entry->d_name, &statbuf);
		//计算目录总大小
		totalSize += statbuf.st_size;
	}
	printf("total %lluK\n", totalSize / 1024);
	chdir(curPath);
	closedir(target);

	//打印目录下所有文件的详情
	if ((target = opendir(targetDir)) == NULL)
		return ERROR_PATH;
	//遍历目标目录
	chdir(targetDir);
	while ((entry = readdir(target)) != NULL)
	{
		//获取文件信息
		lstat(entry->d_name, &statbuf);
		//打印文件类型
		printf("%c", fileType(statbuf.st_mode));
		//打印文件的存取权限
		unsigned int filePermission = statbuf.st_mode & 0777;
		const char* otherPermisson = getPermission(filePermission % 8);
		filePermission /= 8;
		const char* groupPermisson = getPermission(filePermission % 8);
		filePermission /= 8;
		const char* userPermission = getPermission(filePermission);
		printf("%s%s%s ", userPermission, groupPermisson, otherPermisson);
		//打印文件的硬链接个数
		printf("%d ", statbuf.st_nlink);
		//打印文件的拥有者及其群组
		printf("%-8s%-8s ", getUsername(statbuf.st_uid), getGroupname(statbuf.st_gid));
		//打印文件大小
		printf("%4ldK ", statbuf.st_size / 1024);
		//打印文件的最后一次修改时间
		char* fileTime = ctime(&statbuf.st_mtime);
		fileTime[strlen(fileTime) - 1] = '\0';
		printf("%s ", fileTime);
		//打印文件名
		if (S_ISDIR(statbuf.st_mode))
			printf("\033[42;37m%s\033[0m", entry->d_name);
		else
			printf("\033[40;32m%s\033[0m", entry->d_name);

		printf("\n");
	}
	chdir(curPath);
	return RIGHT;
}
// ls的主函数
int ls()
{
	if (cmdNum > 3)
		return ERROR_TOO_MANY_PARAMETER;
	else if (!strcmp(commands[1], "-h") || !strcmp(commands[1], "--help")) // ls -h
	{
		if (cmdNum > 2)
			return ERROR_TOO_MANY_PARAMETER;
		else
		{
			printf("\033[40;31m[Usage]\033[0m");
			printf("\033[40;32m ls [OPTION] [FILE]\033[0m\n");
			printf("List information about the FILE (the current directory by default).\n\n");
			printf("  %-15s %s", "-a, --all ", "do not ignore entries starting with .\n");
			printf("  %-15s %s", "-l", "use a long listing format\n");
			printf("  %-15s %s", "-h, --help", "display this help and exit\n");
		}
		return RIGHT;
	}
	else if (!strcmp(commands[1], "-a") || !strcmp(commands[1], "--all")) // ls -a
	{
		if (cmdNum > 3)
			return ERROR_TOO_MANY_PARAMETER;
		else if (cmdNum == 3)
			targetDir = commands[2];
		else
			targetDir = curPath;
		return ls(2);
	}
	else if (!strcmp(commands[1], "-l")) // ls -l
	{
		if (cmdNum > 3)
			return ERROR_TOO_MANY_PARAMETER;
		else if (cmdNum == 3)
			targetDir = commands[2];
		else
			targetDir = curPath;
		return ls_l();
	}
	else // ls
	{
		if (cmdNum > 2)
			return ERROR_WRONG_PARAMETER;
		else if (cmdNum == 2)
			targetDir = commands[1];
		else
			targetDir = curPath;
		return ls(1);
	}
}