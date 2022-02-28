#include "redirect.h"

int callRedirectCommand(int left, int right)
{
	int inNum = 0, outNum = 0;
	char* inFile = NULL, * outFile = NULL;
	int endIndex = right; // 指令在重定向前的终止下标

	//判断是否有重定向并分解指令
	for (int i = left; i < right; i++)
	{
		if (strcmp(commands[i], CMD_IN) == 0) // 输入重定向
		{
			inNum++;
			if (i + 1 < right)
				inFile = commands[i + 1];
			else // 重定向符号后缺少参数
				return ERROR_MISS_PARAMETER;

			if (endIndex == right)
				endIndex = i;
		}
		else if (strcmp(commands[i], CMD_OUT) == 0) // 输出重定向
		{
			outNum++;
			if (i + 1 < right)
				outFile = commands[i + 1];
			else // 重定向符号后缺少参数
				return ERROR_MISS_PARAMETER;

			if (endIndex == right)
				endIndex = i;
		}
	}

	if (inNum > 1) // 输入重定向符号超过一个
	{
		return ERROR_TOO_MANY_IN;
	}
	else if (outNum > 1) // 输出重定向符号超过一个
	{
		return ERROR_TOO_MANY_OUT;
	}

	//预处理输入重定向
	if (inNum == 1)
	{
		FILE* fp = fopen(inFile, "r");
		if (fp == NULL) // 输入重定向文件不存在
			return ERROR_PATH;
		fclose(fp);
	}

	int result = RIGHT;
	pid_t pid = vfork();
	if (pid == -1)
	{
		return ERROR_FORK;
	}
	else if (pid == 0) // 子进程执行
	{
		//输入重定向
		if (inNum == 1)
			freopen(inFile, "r", stdin);
		//输出重定向
		if (outNum == 1)
			freopen(outFile, "w", stdout);

		//执行命令
		char* cmds[CMDSIZE];
		for (int i = left; i < endIndex; i++)
			cmds[i] = commands[i];
		cmds[endIndex] = NULL;
		if (execvp(cmds[left], cmds + left) < 0)
		{
			exit(ERROR_EXEC);
		}
		exit(RIGHT);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		result = WEXITSTATUS(status);
	}
	return result;
}