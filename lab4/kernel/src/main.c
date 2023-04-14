#include "mm.h"
#include "list.h"
#include "uart.h"
#include "utils.h"
#include "cpio.h"

frame_t *frame_array;
list_head_t free_list[]
list_head_t pool_list[]

char _heap_start;
char* heap_top = &_heap_start;
char _end;
char* kernel_end = &_end;

void* simple_malloc(unsigned long size){

    return addr;
}

void init_allocator(){

}

void* buddy_alloc(unsigned long long size){ //why long long??
    return //?
}


void release_redundant_frame(int frame_idx, int order){

}

void buddy_free(void* ptr){

}

frame_t *get_buddy(frame_t *frame){

}

void *dynamic_alloc(unsigned long long size) {


}

void put_chunks_to_pool(int order) {}

void dynamic_free(void *ptr) {}

void *kmalloc(unsigned long long size) {}

void *kfree(void *ptr) {}

void memory_reserve(unsigned long long start, unsigned long long end) {}

void test_dynamic_alloc() {}

void show_free_list(int order) {
}

void show_pool_list(int order) {}