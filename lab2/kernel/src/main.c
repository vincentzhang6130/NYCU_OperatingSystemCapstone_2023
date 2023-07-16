#include "shell.h"
#include "uart1.h"
#include "heap.h"
#include "u_string.h"
#include "dtb.h"
#include "cpio.h"


char* dtb_ptr;

void main(char* arg){ // 這個放參數的方法
    char input_buffer[CMD_MAX_LEN];
    dtb_ptr = arg;
    // flattened device tree (fdt)
    fdt_traverse(initramfs_callback);

    uart_init();

    cli_print_banner();
    while(1){
        cli_cmd_clear(input_buffer, CMD_MAX_LEN);
        uart_puts("# ");
        cli_cmd_read(input_buffer);
        cli_cmd_exec(input_buffer);
    }

}