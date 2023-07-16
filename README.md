# Operating Systems Capstone 2023

NYCU IOC5226: Operating System Capstone 作業系統總整與實作

## Link
- [Course Syllabus](https://people.cs.nctu.edu.tw/~ttyeh/course/2023_Spring/IOC5226/outline.html)

- [Lab](https://oscapstone.github.io/index.html)

### Lab1: Bare Metal

- Practice bare metal programming.
- Understand how to access rpi3’s peripherals.
- Set up mini UART.
- Set up mailbox.

### Lab2: Booting

- Implement a bootloader that loads kernel images through UART.
- Implement a simple allocator.
- Understand what’s initial ramdisk.
- Understand what’s devicetree.

### Lab 3: Exception and Interrupt

- Understand what’s exception levels in Armv8-A.
- Understand what’s exception handling.
- Understand what’s interrupt.
- Understand how rpi3’s peripherals interrupt the CPU by interrupt controllers.
- Understand how to multiplex a timer.
- Understand how to concurrently handle I/O devices.

### Lab 4: Allocator
- Implement a page frame allocator.
- Implement a dynamic memory allocator.
- Implement a startup allocator.

### Lab 5: Thread and User Process
- Understand how to create threads and user processes.
- Understand how to implement scheduler and context switch.
- Understand what’s preemption.
- Understand how to implement POSIX signals.

### Lab6: Virtual Memory
- Understand ARMv8-A virtual memory system architecture.
- Understand how the kernel manages memory for user processes.
- Understand how demand paging works.
- Understand how copy-on-write works.