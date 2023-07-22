#include "cpio.h"


void initramfs_callback(){


}

int hex_to_dec(char* hex){

}

void align_to_four(struct cpio_newc_header* newc_header_ptr){

    // 如果 要改成比較泛用的參數？？？



}

int strcpy_cpio(){
    // 相同救回傳 1
}


int cpio_newc_parse_header(
    struct cpio_newc_header* header, char** data, 
){

    /*檢查這個記憶體位置上是否有放置cpio歸檔的內容*/
    /*成功取出header則回傳 0 ， 失敗回傳 -1 */
    

    
    hex_to_dec();

};