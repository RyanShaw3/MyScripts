#include "pipe.h"

int callPipeCommand(int left, int right)
{
	if (left >= right)
		return RIGHT;

	//判断是否有管道符并定位
	int pipeIndex = -1;
	for (int i = left; i < right; i++)
	{
		if (strcmp(commands[i], CMD_PIPE) == 0)
		{
			pipeIndex = i;
			break;
		}
	}

	if (pipeIndex == -1) // 不含管道符
	{
		return callRedirectCommand(left, right);
	}
	else if (pipeIndex + 1 == right) // 管道符后缺少命令
	{
		return ERROR_MISS_PARAMETER;
	}

	//执行命令
	int fdes[2];
	if (pipe(fdes) == -1)
	{
		return ERROR_PIPE;
	}
	int result = RIGHT;
	pid_t pid = vfork();
	if (pid == -1)
	{
		result = ERROR_FORK;
	}
	else if (pid == 0) // 子进程执行单个命令
	{
		close(fdes[0]);
		dup2(fdes[1], STDOUT_FILENO);
		close(fdes[1]);

		result = callRedirectCommand(left, pipeIndex);
		exit(result);
	}
	else // 父进程递归得执行后继的管道命令
	{
		//等待子进程的命令执行完毕
		int status;
		waitpid(pid, &status, 0);
		result = WEXITSTATUS(status);

		if (result != RIGHT) // 子进程运行出错
		{
			close(fdes[1]);
			dup2(fdes[0], STDIN_FILENO);
			close(fdes[0]);
		}
		else if (pipeIndex + 1 < right) // 递归执行后继命令
		{
			close(fdes[1]);
			dup2(fdes[0], STDIN_FILENO);
			close(fdes[0]);
			result = callPipeCommand(pipeIndex + 1, right);
		}
	}
	return result;
}