#include "cpio.h"


void initramfs_callback(){


}

int hex_to_dec(char* hex){

    // 參考lab1
}

void align_to_four(struct cpio_newc_header** newc_header_ptr){

    // 需要改成較泛用的
    unsigned int addr = (unsigned int)(*newc_header_ptr);
    unsigned int alignment = 4;
    unsigned int remainder = addr % alignment;
    unsigned int aligned_addr = addr + (alignment - remainder);

    *newc_header_ptr = (struct cpio_newc_header*)aligned_addr;
}

int strncmp(char* str1, char* str2, int len){
    // 相同就回傳 0

    for(int count=0; count<len; str1++, str2++, count++){
        if(){

        }

    }

}


int cpio_newc_parse_header(struct cpio_newc_header* header){

    /*檢查這個記憶體位置上是否有放置cpio歸檔的內容*/
    /*成功取出header則回傳 1 ， 失敗回傳 -1 */
    if(!strncmp(header->c_magic, CPIO_MAGIC_NUMBER, 6)){
        return 1;
    }

    return -1;
}