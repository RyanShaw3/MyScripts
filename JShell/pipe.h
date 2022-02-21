#pragma once

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "data.h"
#include "redirect.h"

//调用管道命令
int callPipeCommand(int, int);