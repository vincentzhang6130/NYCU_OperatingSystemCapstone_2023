# Lab0 WriteUp
熟悉QEMU環境，將assembly code 編譯成kernel image，再載入target machine。
## Steps

gcc -c 編譯但不連結，產生.o 檔
```bash
aarch64-linux-gnu-gcc -c a.S
```
-T 這個參數是用於指定aarch64-linux-gnu-ld 這個 linker 所使用的鏈結器腳本文件，這樣就可以使用我們自定義的鏈結腳本。

```bash
aarch64-linux-gnu-ld -T linker.ld -o kernel8.elf a.o
```

```bash
aarch64-linux-gnu-objcopy -O binary kernel8.elf kernel8.img
```
讓image在qemu的raspi3b模擬 執行binary 反組譯成assembly
```bash
qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -d in_asm
```
dump 結果
```
----------------
IN: 
0x0000000000000300:  d2801b05      mov x5, #0xd8
0x0000000000000304:  d53800a6      mrs x6, (unknown)
0x0000000000000308:  924004c6      and x6, x6, #0x3
0x000000000000030c:  d503205f      unimplemented (System)
0x0000000000000310:  f86678a4      ldr x4, [x5, x6, lsl #3]
0x0000000000000314:  b4ffffc4      cbz x4, #-0x8 (addr 0x30c)

----------------
IN: 
0x0000000000000300:  d2801b05      mov x5, #0xd8
0x0000000000000304:  d53800a6      mrs x6, (unknown)
0x0000000000000308:  924004c6      and x6, x6, #0x3
0x000000000000030c:  d503205f      unimplemented (System)
0x0000000000000310:  f86678a4      ldr x4, [x5, x6, lsl #3]
0x0000000000000314:  b4ffffc4      cbz x4, #-0x8 (addr 0x30c)

----------------
IN: 
0x0000000000000300:  d2801b05      mov x5, #0xd8
0x0000000000000304:  d53800a6      mrs x6, (unknown)
0x0000000000000308:  924004c6      and x6, x6, #0x3
0x000000000000030c:  d503205f      unimplemented (System)
0x0000000000000310:  f86678a4      ldr x4, [x5, x6, lsl #3]
0x0000000000000314:  b4ffffc4      cbz x4, #-0x8 (addr 0x30c)

----------------
IN: 
0x0000000000000000:  580000c0      ldr x0, pc+24 (addr 0x18)
0x0000000000000004:  aa1f03e1      mov x1, xzr
0x0000000000000008:  aa1f03e2      mov x2, xzr
0x000000000000000c:  aa1f03e3      mov x3, xzr
0x0000000000000010:  58000084      ldr x4, pc+16 (addr 0x20)
0x0000000000000014:  d61f0080      br x4

----------------
IN: 
0x000000000000030c:  d503205f      unimplemented (System)
0x0000000000000310:  f86678a4      ldr x4, [x5, x6, lsl #3]
0x0000000000000314:  b4ffffc4      cbz x4, #-0x8 (addr 0x30c)

----------------
IN: 
0x0000000000080000:  d503205f      unimplemented (System)
0x0000000000080004:  17ffffff      b #-0x4 (addr 0x80000)

----------------
IN: 
0x000000000000030c:  d503205f      unimplemented (System)
0x0000000000000310:  f86678a4      ldr x4, [x5, x6, lsl #3]
0x0000000000000314:  b4ffffc4      cbz x4, #-0x8 (addr 0x30c)

----------------
IN: 
0x000000000000030c:  d503205f      unimplemented (System)
0x0000000000000310:  f86678a4      ldr x4, [x5, x6, lsl #3]
0x0000000000000314:  b4ffffc4      cbz x4, #-0x8 (addr 0x30c)

```


## Discussion
What is the difference between  ELF files and kernel image? `Answer from ChatGPT`
>ELF (Executable and Linkable Format) files and kernel image are both binary formats used to represent programs or software, but they serve different purposes and have different structures.

- ELF is a common binary file format used by many different operating systems, including Linux, Unix, and other Unix-like systems. ELF files are used to represent executable programs, shared libraries, and object files. 
- An ELF file is a structured format that contains information about the code, data, and other resources needed to execute a program. 
- It also contains information about how the different parts of the program are linked together, including function and variable addresses, symbol tables, and relocation information. 
- ELF files can be loaded into memory and executed directly by the operating system.

>On the other hand, a kernel image is a binary file that contains the entire operating system kernel, including its code, data, and other resources.
- The kernel image is loaded directly into memory by the boot loader and executed by the processor to start the operating system. 
- The kernel image is specific to the operating system and hardware architecture, and it typically includes device drivers, file systems, and other low-level components that are necessary for the operating system to function.

>In summary, ELF files are used to represent individual programs or libraries, while kernel images represent entire operating systems. ELF files contain information about how a program is structured and how its different parts are linked together, while kernel images contain the entire operating system kernel and everything needed to start the system.

## Reference

https://ivanagyro.medium.com/elf-executable-and-linkable-format-%E5%AD%B8%E7%BF%92%E9%80%94%E5%BE%91%E8%88%87%E8%B3%87%E6%BA%90-a552e1679d8f


https://tupelo-shen.github.io/2020/03/08/linux%E5%86%85%E6%A0%B81-GNU%E6%B1%87%E7%BC%96%E5%85%A5%E9%97%A8_X86-64&ARM/
