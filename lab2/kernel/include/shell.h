#ifndef _SHELL_H_
#define _SHELL_H_

#define CLI_MAX_CMD 6
#define CMD_MAX_LEN 32
#define MSG_MAX_LEN 128

typedef struct CLI_CMDS
{
    char command[CMD_MAX_LEN];
    char help[MSG_MAX_LEN];
} CLI_CMDS;

int  cli_cmd_strcmp(const char*, const char*);
void cli_cmd_clear(char*, int);
void cli_cmd_read(char*);
void cli_cmd_exec(char*);
void cli_print_banner();

/*Lab1*/
void do_cmd_help();
void do_cmd_hello();
void do_cmd_info();
void do_cmd_reboot();

/*Lab2*/
void do_cmd_rootls();
void do_cmd_allocate();

#endif /* _SHELL_H_ */