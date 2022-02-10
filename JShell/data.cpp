#include "data.h"
int cmdNum = 0; // 命令个数
char* commands[CMDSIZE] = { 0 }; // 命令个数
char promptSign = '$'; // 提示符
extern char promptPath[PATH_MAX] = "\0"; // 提示路径
extern struct passwd* user_info = NULL; // 用户信息
char curPath[PATH_MAX] = "\0"; // 工作路径
char username[CMDSIZE] = "\0"; // 用户名
char hostname[CMDSIZE] = "\0"; // 主机名

const char CMD_CD[] = "cd"; // cd
const char CMD_PWD[] = "pwd"; // pwd
const char CMD_LS[] = "ls"; // ls
const char CMD_CP[] = "cp"; //cp
const char CMD_ECHO[] = "echo"; // echo
const char CMD_CAT[] = "cat"; // cat
const char CMD_TIME[] = "time"; // time
const char CMD_CLEAR[] = "clear"; // clear
const char CMD_VI[] = "vi"; // vi
const char CMD_GCC[] = "gcc"; // gcc
const char CMD_RUN[] = ".out"; // run .out
const char CMD_EXIT[] = "exit"; // exit
const char CMD_PIPE[] = "|"; // |
const char CMD_IN[] = "<"; // <
const char CMD_OUT[] = ">"; // >