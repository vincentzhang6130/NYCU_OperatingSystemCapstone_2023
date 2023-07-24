#ifndef _CPIO_H_
#define _CPIO_H_

struct cpio_newc_header {
    char c_magic[6];
    char c_ino[8];
    char c_mode[8];
    char c_uid[8];
    char c_gid[8];
    char c_nlink[8];
    char c_mtime[8];
    char c_filesize[8];
    char c_devmajor[8];
    char c_devminor[8];
    char c_rdevmajor[8];
    char c_rdevminor[8];
    char c_namesize[8];
    char c_check[8];
};


#define CPIO_DEFAULT_ADDRESS 0x8000000
#define CPIO_MAGIC_NUMBER "070701"

int cpio_newc_parse_header(struct cpio_newc_header* header);
int hex_to_dec(char* hex);
void align_to_four(struct cpio_newc_header** newc_header_ptr);
int strncmp(char* str1, char* str2, int len);


#endif
