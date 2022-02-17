#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include "data.h"
#include "ls.h"
#include "cp.h"
#include "pipe.h"

//分解输入的命令
int splitCmds(char argv[]);
//判断命令的类型
int commandsType();
//调用简单函数
int callSimpleCmd();
//调用复杂命令
int callComplexCmd();

/*
* 以下是简单的命令
* 通过单个函数的调用可以实现功能
*/

//切换工作路径
int cd();
//打印当前路径
int pwd();
//字符串输出
int echo();
//获取文件内容
int cat();
//计算进程运行时间的函数
int time();
//清屏函数
int clear();
//编辑文件
int vi();
//编译文件
int gcc();
//运行.out文件
int run_program();
//调用ls命令
int call_ls();
//调用cp命令
int call_cp();