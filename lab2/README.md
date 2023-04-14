# Lab2 WriteUp

## Goals of this lab

- Implement a bootloader that loads kernel images through UART.
- Implement a simple allocator.
- Understand what’s initial ramdisk.
- Understand what’s devicetree.

## Basic Exercise 1 - UART Bootloader


## Basic Exercise 2 - Initial Ramdisk

### Initial Ramdisk.
>Initial Ramdisk (initrd) 是 Linux kernel 在啟動時使用的一種機制。它是一個由內核加載到內存中的臨時文件系統，包含在 Linux kernel image 之外的文件和程序，用於初始化硬件設備、文件系統、網絡等等。

>initrd 最常用於在啟動時加載驅動程序，這些驅動程序可能需要在系統啟動之前加載到內核中。它還可以包含一些工具和腳本，用於系統的自定義配置和調試。

>在 Linux 啟動時，內核首先加載 initrd 文件到內存中，並在內存中創建一個臨時的根文件系統。然後，內核將控制權轉交給 initrd，由它負責初始化系統，並在完成後將控制權轉交回內核。一旦系統初始化完成，initrd 將被卸載並釋放內存，然後系統將繼續啟動到用戶空間。



我的理解 intial ramdisk 是要先對想要load進來的文件先作一個歸檔壓縮，再讓後續可以利用這個資料結構

CPIO
> https://www.mankier.com/5/cpio
## Advanced Exercises

### Ex2 Device Tree

### Reference
> http://blog.ittraining.com.tw/2019/10/linux-device-driver-linux-open-firmware.html

> https://e-mailky.github.io/2016-12-06-dts-introduce#%E5%9B%9B--%E8%AE%BE%E5%A4%87%E6%A0%91%E6%BA%90%E7%A0%81-dts-%E8%A1%A8%E7%A4%BA