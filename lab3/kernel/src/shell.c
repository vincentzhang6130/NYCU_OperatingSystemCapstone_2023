#include "shell.h"
#include "time.h" 
/*有哪些指令可以用？*/
// help
// hello
// reboot


// load user program from initramfs

#define CLI_MAX_CMD 11

CLI_CMDS cmd_list[CLI_MAX_CMD] = {

    {.command="cat", .help="concatenate files and print on the standard output"},
    {.command="dtb", .help="show device tree"},
    {.command="exec", .help="execute a command, replacing current image with a new image"},
    {.command="hello", .help="print Hello World!"},
    {.command="help", .help="print all available commands"},
    {.command="kmalloc", .help="simple allocator in heap session"},
    {.command="info", .help="get device information via mailbox"},
    {.command="ls", .help="list directory contents"},
    {.command="setTimeout", .help="setTimeout [MESSAGE] [SECONDS]"},
    {.command="set2sAlert", .help="set core timer interrupt every 2 second"},
    {.command="reboot", .help="reboot the device"}
};

void cli_cmd_read(char* buffer){


}

void cli_cmd_exec(char* buffer){

}


void cli_print_banner(){

}

void do_cmd_cat(char* filepath){


}

void do_cmd_dtb(){


}

void do_cmd_help(){


}

void do_cmd_exec(){

}


void do_cmd_hello(){

}

void do_cmd_kmalloc(){}

void do_cmd_info(){}

void do_cmd_ls(){}


void do_cmd_setTimeout(){
    add_timer();
}

/*這是讓core timer 每兩秒就對 cpu 發出中斷*/
void do_cmd_set2sAlert(){
    
    add_timer();
}