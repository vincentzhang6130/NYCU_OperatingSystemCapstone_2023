#include "shell.h"

CLI_CMDS cmd_list [CLI_MAX_CMD] = {

    {.command = "hello", .help ="Print Hello World!"},
    {.command = "help",  .help ="Show all available commands"},
    {.command = "info",  .help ="Get device information via mailbox"},
    {.command = "reboot", .help="Reboot the device"}
};


int cli_cmd_strcmp(const char *str1, const char* str2){
    int i;
    for(i=0; str1[i]!='\0' && str2[i]!='\0'; i++){
        if(str1[i] != str2[i]){
            return str1[i] - str2[i]; 
        }
    }
    return str1[i] - str2[i]; 
}

void cli_cmd_clear(char*, int){

}
void cli_cmd_read(char*){
    uart_recv();
}
void cli_cmd_exec(char* buffer){
    
    if(cli_cmd_strcmp(buffer, "hello")){
        do_cmd_hello();
    }
    else if(cli_cmd_strcmp(buffer, "help")){
        do_cmd_help();
    }
    else if(cli_cmd_strcmp(buffer, "info")){
        do_cmd_info();
    }
    else if(cli_cmd_strcmp(buffer, "reboot")){
        do_cmd_reboot();
    }
    
}
void cli_print_banner(){
    uart_puts("=======================================\n");
    uart_puts("Welcome to Yusong's NYCU-OSC 2023 Lab1 :)\n");
    uart_puts("=======================================\n");
}

void do_cmd_help(){
    uart_puts("All the command you can use: \n");
}
void do_cmd_hello(){
    uart_puts("Hello World !\n");
}
void do_cmd_info(){

}

void do_cmd_reboot(){

}