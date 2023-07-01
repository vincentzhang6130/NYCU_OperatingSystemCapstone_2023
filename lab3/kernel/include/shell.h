#ifndef _SHELL_H_
#define _SHELL_H_

#define CMD_MAX_LEN 0x100
#define MSG_MAX_LEN 0x100

typedef struct CLI_CMDS
{
    char command[CMD_MAX_LEN];
    char help[MSG_MAX_LEN];
} CLI_CMDS;

#endif