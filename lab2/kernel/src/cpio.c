#include "cpio.h"


int hex_to_dec(char* hex){
    
    int decimal_num; 

    while(!*hex){
        int trans_value = 0;
        if(*hex >= 65){
            trans_value = (*hex) - 55; // A->10
        }
        else{
            trans_value = (*hex) - 48;
        }
        decimal_num += trans_value;
        hex++;
    }
    return decimal_num;
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
    
    // 在一半發現不同
    int count = 0;
    while (!*str1 && !*str2 && *str1==*str2 && count<len){

        str1++;
        str2++;
        count++;
    }
    if(count == len){
        return 0;
    }
    if(!*str1){
        // str2 longer
        return -1;   
    }
    else if(!*str2){
        // str1 longer
        return 1;
    }
    // 一樣長出現不同的
    return (*str1) - (*str2);
}


int cpio_newc_parse_header(struct cpio_newc_header* header){

    /*檢查這個記憶體位置上是否有放置cpio歸檔的內容*/
    /*成功取出header則回傳 1 ， 失敗回傳 -1 */
    if(!strncmp(header->c_magic, CPIO_MAGIC_NUMBER, 6)){
        return 1;
    }

    return -1;
}