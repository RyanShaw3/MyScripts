#include "prompt.h"

//获取用户名
void getUserName()
{
	user_info = getpwuid(getuid());
	strcpy(username, user_info->pw_name);
}
//获取主机名
void getHostName()
{
	gethostname(hostname, CMDSIZE);
}
//获取提示符
void getPromptSign()
{
	//修改root用户的提示符为'#'
	if (getuid() == 0)
		promptSign = '#';
}
//获取提示路径
void getPromptPath()
{
	getcwd(curPath, PATH_MAX);
	int pw_dir_len = strlen(user_info->pw_dir);
	if (strncmp(user_info->pw_dir, curPath, pw_dir_len))
		strcpy(promptPath, curPath);
	else
	{
		promptPath[0] = '~';
		strcpy(promptPath + 1, curPath + pw_dir_len);
	}
}
//打印提示
void printPrompt()
{
	getUserName();
	getHostName();
	getPromptSign();
	getPromptPath();

	printf("\033[40;32m[JShell]%s@%s\033[0m", username, hostname);
	printf(":");
	printf("\033[40;34m%s\033[0m", promptPath);
	printf("%c ", promptSign);
	fflush(stdout);
}