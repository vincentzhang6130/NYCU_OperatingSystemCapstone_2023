#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 内存块结构体
typedef struct block {
    int size;              // 内存块大小
    int free;              // 是否空闲
    struct block *next;    // 指向下一个块
} block_t;

// 全局变量，指向可用内存块列表的头部
block_t *free_list[32];

// 初始化可用内存块列表
void initialize() {
    int i;
    for (i = 0; i < 32; i++) {
        free_list[i] = NULL;
    }
}

// 分配内存
void *my_malloc(int size) {
    int i;
    for (i = 0; i < 32; i++) {
        if (size <= (1 << i)) {    // 找到大小合适的块
            if (free_list[i] != NULL) {    // 如果有空闲块
                block_t *block = free_list[i];    // 获取空闲块
                free_list[i] = free_list[i]->next;    // 更新可用块列表
                block->free = 0;    // 标记块已被使用
                return (void *) block;    // 返回块的地址
            } else {    // 如果没有空闲块，则向上查找更大的块
                int j;
                for (j = i + 1; j < 32; j++) {
                    if (free_list[j] != NULL) {    // 找到较大的空闲块
                        block_t *block = free_list[j];    // 获取空闲块
                        free_list[j] = free_list[j]->next;    // 更新可用块列表
                        // 将空闲块分成两半
                        int k;
                        for (k = j - 1; k >= i; k--) {
                            block_t *new_block = (block_t *)((char *)block + (1 << k));
                            new_block->size = 1 << k;
                            new_block->free = 1;
                            new_block->next = free_list[k];
                            free_list[k] = new_block;
                        }
                        block->free = 0;    // 标记块已被使用
                        return (void *) block;    // 返回块的地址
                    }
                }
                return NULL;    // 没有足够的可用内存块
            }
        }
    }
    return NULL;    // 大小超出范围
}

// 释放内存
void my_free(void *ptr) {
    block_t *block = (block_t *)ptr;
    block->free = 1;    // 标记块为空闲
    int i;
    for (i = block->size; i < 31; i++) {
        // 合并相邻的空闲块
        if (block->next != NULL && block->next->free