#include "shell.h"
#include "uart1.h"
#include "mbox.h"
#include "power.h"
#include "cpio.h"

CLI_CMDS cmd_list [CLI_MAX_CMD] = {

    {.command = "hello", .help ="Print Hello World!"},
    {.command = "help",  .help ="Show all available commands"},
    {.command = "info",  .help ="Get device information via mailbox"},
    {.command = "reboot", .help="Reboot the device"},
    {.command = "ls", .help="List the rootfs"},
    {.command = "cat", .help="Show a file content"}
};


int cli_cmd_strcmp(const char *str1, const char* str2){
    int i;
    for(i=0; str1[i]!='\0' && str2[i]!='\0'; i++){
        if(str1[i] != str2[i]){
            return (int)(str1[i] - str2[i]); 
        }
    }
    //轉型純粹是怕不同編譯器下，可能會出錯
    return (int)(str1[i] - str2[i]); 
}

void cli_cmd_clear(char* buffer, int length){

    for(int i=0; i<length; i++){
        buffer[i] = '\0';
    }
}

void cli_cmd_read(char* buffer){
    
    int index = 0;
    while (1)
    {
        if ( index >= CMD_MAX_LEN ) break;
        char c = uart_recv();
        if ( c == '\n')
        {
            uart_puts("\r\n");
            break;
        }
        if ( c > 16 && c < 32 ) continue;

        buffer[index++] = c;
        uart_send(c);
    }
}

void cli_cmd_exec(char* buffer){
    
    if(cli_cmd_strcmp(buffer, "hello")==0){
        do_cmd_hello();
    }
    else if(cli_cmd_strcmp(buffer, "help")==0){
        do_cmd_help();
    }
    else if(cli_cmd_strcmp(buffer, "info")==0){
        do_cmd_info();
    }
    else if(cli_cmd_strcmp(buffer, "reboot")==0){
        do_cmd_reboot();
    }
    else if(cli_cmd_strcmp(buffer, "ls")==0){
        do_cmd_rootls();
    }
    
}
void cli_print_banner(){

    uart_puts("=======================================\n");
    uart_puts("Welcome to YuSung's NYCU-OSC 2023 Lab2 :)\n");
    uart_puts("=======================================\n");
}

void do_cmd_help(){

    uart_puts("All the command you can use: \n");
    for(int i=0; i<CLI_MAX_CMD; i++){
        uart_puts(cmd_list[i].command);
        uart_puts("\t\t: ");
        uart_puts(cmd_list[i].help);
        uart_puts("\r\n");
    }
}

void do_cmd_hello(){
    uart_puts("Hello World !\n");
}
void do_cmd_info(){
    /* 透過 mailbox 拿到硬體資訊 和 arm memory based address*/
    get_board_revision();
    get_arm_memory();
}

void do_cmd_reboot(){
    uart_puts("Reboot in 5 seconds ...\r\n\r\n");
    volatile unsigned int* rst_addr = (unsigned int*)PM_RSTC;
    *rst_addr = PM_PASSWORD | 0x20;
    volatile unsigned int* wdg_addr = (unsigned int*)PM_WDOG;
    *wdg_addr = PM_PASSWORD | 5;
}

void do_cmd_rootls(){

    /*把root fs 打印出來*/
    unsigned int* header_ptr = (unsigned int*) CPIO_DEFAULT_ADDRESS;
    struct cpio_newc_header* newc_header_ptr = (struct cpio_newc_header*)header_ptr;
    
    int namesize;
    int filesize;

    while(cpio_newc_parse_header(newc_header_ptr)){

        // newc_header_ptr
        namesize = hex_to_dec(newc_header_ptr->c_namesize);
        filesize = hex_to_dec(newc_header_ptr->c_filesize);

        newc_header_ptr += sizeof(struct cpio_newc_header);
        for(int i=0; i<namesize; i++){
            uart_puts((char*) (newc_header_ptr+i));
        }
        uart_puts("\n");
        // 印完file name就可以跨過檔名
        newc_header_ptr += namesize;
        // 再跨過file 本身資料的部份
        newc_header_ptr += filesize;
        // 對齊到4 byte 倍數
        align_to_four(newc_header_ptr);
    }
}

void do_cmd_cat(char* file_to_cat){
    // 傳入檔名

    unsigned int* header_ptr = (unsigned int*) CPIO_DEFAULT_ADDRESS;
    struct cpio_newc_header* newc_header_ptr = (struct cpio_newc_header*)header_ptr;
    
    int namesize;
    int filesize;

    while(cpio_newc_parse_header(newc_header_ptr)){

        // newc_header_ptr
        namesize = hex_to_dec(newc_header_ptr->c_namesize);
        filesize = hex_to_dec(newc_header_ptr->c_filesize);
        // 跨過 header // 停在放檔名的位置
        newc_header_ptr += sizeof(struct cpio_newc_header);
        if(strcpy_cpio(newc_header_ptr, file_to_cat, filesize)){
            // 可以跨過檔名
            newc_header_ptr += namesize;
            // 印出檔案內容
            for(int i=0; i<filesize; i++){
                uart_puts((char*) (newc_header_ptr+i));
            }
            break;
        }
        else{
            // 可以跨過檔名
            newc_header_ptr += namesize;
            // 再跨過file 本身資料的部份
            newc_header_ptr += filesize;
            // 對齊到4 byte 倍數
            align_to_four(newc_header_ptr);
        }
    }

}