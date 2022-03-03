#include <stdio.h>
#include <string.h>
#include "data.h"
#include "prompt.h"
#include "commands.h"

int main()
{
	char argv[BUFSIZ] = "\0";
	for (int i = 0; i < CMDSIZE; i++)
	{
		commands[i] = new char[CMDSIZE];
	}
	while (1)
	{
		//打印提示
		printPrompt();
		//清空输出缓冲区
		fflush(stdout);
		//获取输入
		fgets(argv, BUFSIZ, stdin);
		argv[strlen(argv) - 1] = '\0';
		//清空输入缓冲区
		fflush(stdin);

		if (splitCmds(argv) == ERROR_COMMAND)
		{
			printf("\033[40;31m[ERROR] \033[0m");
			printf("error command\n");
		}
		else if (cmdNum > 0)
		{
			//最后一个命令后加\0
			commands[cmdNum][0] = '\0';

			int result;
			if (commandsType() == SIMPLE)
			{
				result = callSimpleCmd();
				//退出JShell
				if (result == EXIT && !strcmp(commands[0], CMD_EXIT))
				{
					for (int i = 0; i < CMDSIZE; i++)
					{
						delete[] commands[i];
					}
					return 0;
				}
			}
			else
			{
				result = callComplexCmd();
			}
			//错误处理
			if (result != RIGHT && result != EXIT)
			{
				printf("\033[40;31m[ERROR] \033[0m");
				switch (result)
				{
				case ERROR_FORK:
					printf(strerror(errno));
					printf("\n");
					break;
				case ERROR_EXEC:
					printf(strerror(errno));
					printf("\n");
					break;
				case ERROR_COMMAND:
					printf("command not found\n");
					break;
				case ERROR_CP:
					printf("cp runtime error: ");
					printf(strerror(errno));
					printf("\n");
					break;
				case ERROR_TOO_MANY_IN:
					printf("too many redirection symbol\n");
					break;
				case ERROR_TOO_MANY_OUT:
					printf("Too many redirection symbol\n");
					break;
				case ERROR_WRONG_PARAMETER:
					printf("parameter error\n");
					break;
				case ERROR_MISS_PARAMETER:
					printf("miss parameter\n");
					break;
				case ERROR_TOO_MANY_PARAMETER:
					printf("too many parameter\n");
					break;
				case ERROR_PATH:
					printf(strerror(errno));
					printf("\n");
					break;
				case ERROR_TARGET_EXITS:
					printf(strerror(errno));
					printf("\n");
					break;
				case ERROR_IO:
					printf(strerror(errno));
					printf("\n");
					break;
				default:
					printf("Unknown error\n");
					break;
				}
			}
		}
	}
	return 0;
}