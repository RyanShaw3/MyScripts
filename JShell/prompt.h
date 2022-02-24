#pragma once

#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "data.h"

//获取用户名
void getUserName();
//获取主机名
void getHostName();
//获取提示符
void getPromptSign();
//获取提示路径
void getPromptPath();
//打印提示
void printPrompt();