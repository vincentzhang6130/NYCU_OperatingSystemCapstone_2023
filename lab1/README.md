# Lab1 WriteUp

## Goals of this lab

- Practice bare metal programming.
- Understand how to access rpi3’s peripherals.
- Set up mini UART.
- Set up mailbox.

>https://oscapstone.github.io/labs/lab1.html#

## Basic Exercise 1 - Basic Initialization
 
- 需了解用簡易的 boot程式，將我們自己寫的kernel code 載入到memory

- 將bss 段的變數都設為0


## Ex1 Reference
[BIOS, BootManager, Bootstrap與Bootloader的差別](http://mark-shih.blogspot.com/2011/10/bios-bootmanager-bootstrapbootloader.html)

先bootstrap再bootloader



### memory-mapped I/O
hardware devices are mapped to specific memory addresses in the processor's address space. 

How to make a mailbox to communicate with other device in Raspberry Pi memory-mapped I/O system ?

為了理解 memory-mapped I/O 看了這幾篇文章

- https://ithelp.ithome.com.tw/articles/10282974

- https://zhuanlan.zhihu.com/p/142586194

- (BCM2835 外設規格書) https://www.raspberrypi.org/app/uploads/2012/02/BCM2835-ARM-Peripherals.pdf
 
- https://cloud.tencent.com/developer/news/701928

#### memory-mapped I/O: 
外部的設備被映射到 特定的記憶體位置

#### Board Revision: 
是指 Raspberry Pi 模型的硬體版本編號，它是一個由 Raspberry Pi Foundation 分配的代碼，用來區分不同的 Raspberry Pi 模型。這個版本編號通常以一個 R（代表 Revision）開頭，然後跟著一串數字或字母，例如 RPi 4 Model B 的編號是 RPi 4B V1.2。 Board Revision 的確定方式與硬體版本和時鐘計算相關，因此在 Raspberry Pi 的開發和測試中，Board Revision 是一個非常重要的概念。


#### Link script

```
SECTIONS
{
    . = 0x80000; 
    .text : { *(.text.boot) *(.text) }
    .rodata : { *(.rodata) }
    .data : { *(.data) }
    .bss : {
        . = ALIGN(16);
        __bss_start = .;
        *(.bss) 
        __bss_end = .;
    }
}
# 64bit
__bss_size = (__bss_end - __bss_start) >> 3;

```

The program counter is set to correct memory address.???

The bss segment are initialized to 0 ??? 怎麼做？

### Mini UART


### Reference
>https://github.com/raspberrypi/firmware

>https://jsandler18.github.io/extra/mailbox.html

>https://hackmd.io/@AndyKuo/Lab2

>https://hackmd.io/@AndyKuo/Lab3

>https://blog.csdn.net/suz_cheney/article/details/86027172

>https://www.slideshare.net/stenlyho/raspberry-pi-47602690

>https://blog.louie.lu/2016/11/06/10%E5%88%86%E9%90%98%E8%AE%80%E6%87%82-linker-scripts/

>https://s-matyukevich.github.io/raspberry-pi-os/docs/lesson01/rpi-os.html

>https://github.com/bztsrc/raspi3-tutorial