#include "bcm2837/rpi_mailbox.h"
#include "mbox.h"
#include "uart1.h"

int mbox_call(mbox_channel_type channel, volatile unsigned int *mailbox){
    // 這段code 其實是在模擬arm 與gpu的互動行為，包含了 arm寄信 gpu(video core)收信的行為

    //把 message 讀取出來
    unsigned int message = (unsigned long) mailbox; //因為是用aarch64編譯，所以地址要先轉型，才不會有警告
    // 把 message最低4位清掉，填上channel，這個位址就是mail的內容 這樣硬體才可以藉由MBOX_WRITE知道
    // 現在要 mailbox 做什麼行為 （ex. ARM to VideoCore)
    message &= ~(0xF);
    message |= channel; 

    while ( (*MBOX_STATUS & BCM_ARM_VC_MS_FULL) != 0 ) {}    
    //把 message寫到暫存器
    *MBOX_WRITE = message;
    while(1){
        while(*MBOX_STATUS & BCM_ARM_VC_MS_EMPTY) {}
        if(message == *MBOX_READ)
            return mailbox[1] == MBOX_REQUEST_SUCCEED;
    }
    return 0; // 應該不需要
}


void get_board_revision(){
    //宣告一個 mailbox buffer 把資訊存起來
    volatile unsigned int __attribute__((aligned(16))) mailbox[8];
    mailbox[0] = 8 * 4;
    mailbox[1] = MBOX_REQUEST_PROCESS;
    //tags begin
    mailbox[2] = MBOX_TAG_GET_BOARD_REVISION;
    mailbox[3] = 4; 
    mailbox[4] = MBOX_TAG_REQUEST_CODE;
    mailbox[5] = 0;
    mailbox[6] = 0;
    mailbox[7] = MBOX_TAG_LAST_BYTE;
    // tag end
    if(mbox_call(MBOX_TAGS_ARM_TO_VC, mailbox)){ //mailbox 請求成功印出訊息
        uart_puts("Hardware Revision\t: ");
        uart_2hex(mailbox[6]); //被更新後的值
        uart_2hex(mailbox[5]);
        uart_puts("\r\n");
    }
}

void get_arm_memory(){
    //根據規格寫信
    volatile unsigned int __attribute__((aligned(16))) mailbox[8];
    mailbox[0] = 8 * 4;
    mailbox[1] = MBOX_REQUEST_PROCESS;
    //tags begin
    mailbox[2] = MBOX_TAG_GET_ARM_MEMORY;
    mailbox[3] = 8;
    mailbox[4] = MBOX_TAG_REQUEST_CODE;
    mailbox[5] = 0;
    mailbox[6] = 0;
    mailbox[7] = MBOX_TAG_LAST_BYTE;
    
    // 把這封信的地址傳進去
    if(mbox_call(MBOX_TAGS_ARM_TO_VC, mailbox)){ //mailbox 請求成功印出訊息
        uart_puts("ARM Memory Base Address\t: ");
        uart_2hex(mailbox[5]);
        uart_puts("\r\n");
        uart_puts("ARM Memory Size\t\t: ");
        uart_2hex(mailbox[6]);
        uart_puts("\r\n");
    }
}