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



intial ramdisk 是要先對想要load進來的文件先作一個歸檔壓縮，再讓後續可以利用這個資料結構

如何知道有多少個檔案？ 就看還有沒有magic number


CPIO
> https://www.mankier.com/5/cpio

實作ls與cat前需要先了解其格式，把這篇看懂就能知道其歸檔的方式與header的規格。
> https://www.systutorials.com/docs/linux/man/5-cpio/


- 要開始實作這裡時在思考為什麼可以直接把cpio 歸檔的位置給轉型成指向我們自定義的struct
，加上struct本身編譯器會對其padding，不知道該如何肯定memory中擺放byte的順序是否如同規格書所示。
- 先實做看看，或許這個假設是多餘的。


## Advanced Exercises

### Ex2 Device Tree

### Reference
> http://blog.ittraining.com.tw/2019/10/linux-device-driver-linux-open-firmware.html

> https://e-mailky.github.io/2016-12-06-dts-introduce#%E5%9B%9B--%E8%AE%BE%E5%A4%87%E6%A0%91%E6%BA%90%E7%A0%81-dts-%E8%A1%A8%E7%A4%BA


> https://github.com/stweil/raspberrypi-documentation/blob/master/configuration/device-tree.md



>https://abcamus.github.io/2016/12/28/uboot%E8%AE%BE%E5%A4%87%E6%A0%91-%E8%A7%A3%E6%9E%90%E8%BF%87%E7%A8%8B/
>https://blog.csdn.net/wangdapao12138/article/details/82934127