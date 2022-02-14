#pragma once

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <dirent.h>
#include <utime.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

//拷贝软链接
int copylink(char path1[], char path2[]);
//拷贝文件
int copyfile(char path1[], char path2[]);
//拷贝目录
int copydir(char source[], char target[]);
//cp命令的主函数
int cp();