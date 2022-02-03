#pragma once

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "data.h"

extern char* targetDir;
extern const char* permissions[];

char fileType(mode_t);
const char* getPermission(mode_t);
const char* getUsername(uid_t);
const char* getGroupname(gid_t);
int ls(int option);
int ls_l();
int ls();