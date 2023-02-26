.section ".text.boot"   ; This sets the section for the boot code to the ".text.boot" section
.global _start         ; This declares "_start" as a global symbol that can be accessed from outside this file

_start:                ; This is the entry point of the program
    ldr     x1, =_start     ; Load the address of "_start" into register x1
    mov     sp, x1          ; Set the stack pointer (SP) to the address of "_start"
    ldr     x1, =__bss_start ; Load the address of the start of the BSS section into register x1
    ldr     w2, =__bss_size  ; Load the size of the BSS section into register w2

clear_bss:             ; This loop clears the BSS section
    cbz     w2, run_main   ; If w2 is zero, jump to "run_main"
    str     xzr, [x1], #8  ; Store zero in the current address pointed to by x1, and increment x1 by 8 bytes
    sub     w2, w2, #1     ; Decrement w2 by 1
    cbnz    w2, clear_bss  ; If w2 is not zero, jump to "clear_bss" to clear the next address

run_main:              ; This is where the main code of the program starts
    bl      main           ; Call the "main" function
proc_hang:             ; This loop hangs the processor
    wfe                    ; Wait for event
    b       proc_hang     ; Jump to "proc_hang" to wait indefinitely
