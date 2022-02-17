#include "commands.h"

int splitCmds(char argv[])
{
	cmdNum = 0;
	int argv_len = strlen(argv);
	int cmd_len = 0;
	for (int i = 0, j = 0; i < argv_len;)
	{
		if (argv[i] == '\"') // 双引号之间的内容一个命令或参数
		{
			do
			{
				j++;
			} while (argv[j] != '\"' && argv[j] != '\0');
			if (argv[j] == '\0')
				return ERROR_COMMAND;
			strncpy(commands[cmdNum], argv + i + 1, j - i - 1);
			commands[cmdNum][j - i - 1] = '\0';
			cmdNum++;
			j++;
			if (argv[j] != ' ' && argv[j] != '\0')
				return ERROR_COMMAND;
			while (argv[j] == ' ' && argv[j] != '\0')
				j++;
			i = j;
		}
		else if (argv[j] == ' ' || argv[j] == '\0') // 以空格分割命令和参数
		{
			strncpy(commands[cmdNum], argv + i, j - i);
			commands[cmdNum][j - i] = '\0';
			cmdNum++;
			while (argv[j] == ' ' && argv[j] != '\0')
				j++;
			i = j;
		}
		else
			j++;
	}
	return RIGHT;
}
int commandsType()
{
	for (int i = 0; i < cmdNum; i++)
	{
		//有管道符或重定向
		if (!strcmp(commands[i], CMD_PIPE) || !strcmp(commands[i], CMD_IN) || !strcmp(commands[i], CMD_OUT))
			return COMPLEX;
	}
	return SIMPLE;
}
int callSimpleCmd()
{
	if (strcmp(commands[0], CMD_CD) == 0)
		return cd();
	else if (strcmp(commands[0], CMD_PWD) == 0)
		return pwd();
	else if (strcmp(commands[0], CMD_LS) == 0)
		return call_ls();
	else if (strcmp(commands[0], CMD_CP) == 0)
		return call_cp();
	else if (strcmp(commands[0], CMD_ECHO) == 0)
		return echo();
	else if (strcmp(commands[0], CMD_CAT) == 0)
		return cat();
	else if (strcmp(commands[0], CMD_TIME) == 0)
		return time();
	else if (strcmp(commands[0], CMD_CLEAR) == 0)
		return clear();
	else if (strcmp(commands[0], CMD_VI) == 0)
		return vi();
	else if (strcmp(commands[0], CMD_GCC) == 0)
		return gcc();
	else if (strcmp(&commands[0][strlen(commands[0]) - 4], CMD_RUN) == 0)
		return run_program();
	else if (strcmp(commands[0], CMD_EXIT) == 0)
		return EXIT;
	else
		return ERROR_COMMAND;
}
int callComplexCmd()
{
	pid_t pid = fork();
	if (pid == -1)
		return ERROR_FORK;
	else if (pid == 0)
	{
		//获取标准输入输出的文件标识符
		int stdin_f = dup(STDIN_FILENO);
		int stdou_f = dup(STDOUT_FILENO);

		int result = callPipeCommand(0, cmdNum);

		//还原标准输入输出重定向
		dup2(stdin_f, STDIN_FILENO);
		dup2(stdou_f, STDOUT_FILENO);
		exit(result);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		return WEXITSTATUS(status);
	}
}

int cd()
{
	if (cmdNum > 2)
		return ERROR_TOO_MANY_PARAMETER;
	else if (cmdNum < 2)
		return ERROR_MISS_PARAMETER;
	else if (!strcmp(commands[1], "-h") || !strcmp(commands[1], "--help"))
	{
		printf("\033[40;31m[Usage]\033[0m\n");
		printf("\t\033[40;32m cd [path]\033[0m");
		printf("\tswitch directory to [path].\n");
	}
	else
	{
		if (commands[1][0] == '~')
		{
			char path[PATH_MAX];
			strcpy(path, user_info->pw_dir);
			strcat(path, &commands[1][0] + 1);
			strcpy(commands[1], path);
		}
		if (chdir(commands[1]))
			return ERROR_PATH;
		getcwd(curPath, PATH_MAX);
	}
	return RIGHT;
}
int pwd()
{
	if (cmdNum > 1)
		return ERROR_TOO_MANY_PARAMETER;
	printf("%s\n", curPath);
	return RIGHT;
}
int echo()
{
	if (cmdNum > 2)
		return ERROR_TOO_MANY_PARAMETER;
	else if (cmdNum < 2)
		return ERROR_MISS_PARAMETER;
	else
	{
		printf("%s\n", commands[1]);
		return RIGHT;
	}
}
int cat()
{
	if (cmdNum > 2)
		return ERROR_TOO_MANY_PARAMETER;
	else if (cmdNum < 2)
		return ERROR_MISS_PARAMETER;
	else
	{
		FILE* fp;
		if ((fp = fopen(commands[1], "r")) == NULL)
		{
			printf("\033[40;31m[ERROR] \033[0m");
			printf(strerror(errno));
			printf("\n");
		}
		else
		{
			int c;
			while (1)
			{
				c = fgetc(fp);
				if (feof(fp))
					break;
				printf("%c", c);
			}
			fclose(fp);
		}
		return RIGHT;
	}
}
int time()
{
	if (cmdNum < 2)
		return ERROR_MISS_PARAMETER;
	else
	{
		struct timeval t_begin, t_end;
		pid_t pid;

		// 创建子进程
		if ((pid = fork()) < 0) // 子进程创建失败
		{
			return ERROR_FORK;
		}
		// 获得子进程开始时间
		gettimeofday(&t_begin, NULL);
		if (pid == 0) // 子进程创建成功
		{
			// 给子进程指定一个新的运行程序
			commands[cmdNum] = NULL;
			if (execvp(commands[1], commands + 1) < 0) // 给子进程指定新运行程序时发生错误
			{
				//printf("\033[40;31m[ERROR] \033[0m");
				//printf(strerror(errno));
				//printf("\n");
				exit(ERROR_EXEC);
			}
			exit(RIGHT);
		}
		else
		{
			// 父进程等待子进程终止
			int status;
			waitpid(pid, &status, 0);

			// 获得子进程结束时间
			gettimeofday(&t_end, NULL);

			// 计算子进程运行总时间
			long int begin = t_begin.tv_sec * 1000000 + t_begin.tv_usec;
			long int end = t_end.tv_sec * 1000000 + t_end.tv_usec;
			long int t = end - begin;
			long int sec = t / 1000000;
			long int usec = t % 1000000;

			// 输入子进程用时
			printf("The time of process: %lds, %ldμs\n", sec, usec);

			return WEXITSTATUS(status);
		}
	}
}
int clear()
{
	system("clear");
	return RIGHT;
}
int vi()
{
	pid_t pid;
	// 创建子进程
	if ((pid = fork()) < 0) // 子进程创建失败
	{
		return ERROR_FORK;
	}
	if (pid == 0) // 子进程创建成功
	{
		// 给子进程指定一个新的运行程序
		commands[cmdNum] = NULL;
		if (execvp(commands[0], commands) < 0) // 给子进程指定新运行程序时发生错误
		{
			exit(ERROR_EXEC);
		}
		exit(RIGHT);
	}
	else
	{
		// 父进程等待子进程终止
		int status;
		waitpid(pid, &status, 0);
		return WEXITSTATUS(status);
	}
}
int gcc()
{
	pid_t pid;
	// 创建子进程
	if ((pid = fork()) < 0) // 子进程创建失败
	{
		return ERROR_FORK;
	}
	if (pid == 0) // 子进程创建成功
	{
		// 给子进程指定一个新的运行程序
		commands[cmdNum] = NULL;
		if (execvp(commands[0], commands) < 0) // 给子进程指定新运行程序时发生错误
		{
			exit(ERROR_EXEC);
		}
		exit(RIGHT);
	}
	else
	{
		// 父进程等待子进程终止
		int status;
		waitpid(pid, &status, 0);
		return WEXITSTATUS(status);
	}
}
int run_program()
{
	pid_t pid;
	// 创建子进程
	if ((pid = fork()) < 0) // 子进程创建失败
	{
		return ERROR_FORK;
	}
	if (pid == 0) // 子进程创建成功
	{
		// 给子进程指定一个新的运行程序
		commands[cmdNum] = NULL;
		if (execvp(commands[0], commands) < 0) // 给子进程指定新运行程序时发生错误
		{
			exit(ERROR_EXEC);
		}
		exit(RIGHT);
	}
	else
	{
		// 父进程等待子进程终止
		int status;
		waitpid(pid, &status, 0);
		return WEXITSTATUS(status);
	}
}
int call_ls()
{
	return ls();
}
int call_cp()
{
	return cp();
}