#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "data.h"

//调用重定向命令
int callRedirectCommand(int, int);