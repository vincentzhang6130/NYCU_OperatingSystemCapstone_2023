#include "bcm2837/rpi_gpio.h"
#include "bcm2837/rpi_uart1.h"
#include "uart1.h"

void uart_init(){

    // Set AUXENB register to enable mini UART. Then mini UART register can be accessed.
    *AUX_ENABLES     |= 1;
    // Set AUX_MU_CNTL_REG to 0. Disable transmitter and receiver during configuration.
    *AUX_MU_CNTL_REG  = 0;
    // Set AUX_MU_IER_REG to 0. Disable interrupt because currently you don’t need interrupt.
    *AUX_MU_IER_REG   = 0;
    // Set AUX_MU_LCR_REG to 3. Set the data size to 8 bit.
    *AUX_MU_LCR_REG   = 3;
    // Set AUX_MU_MCR_REG to 0. Don’t need auto flow control.
    *AUX_MU_MCR_REG   = 0;
    // Set AUX_MU_BAUD to 270. Set baud rate to 115200
    *AUX_MU_BAUD_REG  = 270;
    // Set AUX_MU_IIR_REG to 6. No FIFO.
    *AUX_MU_IIR_REG   = 6;
    // Set AUX_MU_CNTL_REG to 3. Enable the transmitter and receiver.
    *AUX_MU_CNTL_REG = 3;

    /* Map uart1 to gpio pins */  //這部份要補 微控制器...
    register unsigned int r; //??
    r = *GPFSEL1;
    r &= ~(7<<12);               // clean gpio14
    r |= 2<<12;                  // set gpio14 to alt5
    r &= ~(7<<15);               // clean gpio15
    r |= 2<<15;                  // set gpio15 to alt5
    *GPFSEL1 = r;

     /* Enable pin 14, 15 - ref: Page 101 */
    *GPPUD = 0;
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = (1<<14)|(1<<15);
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = 0;

}

char uart_recv() {
  
}

void uart_send(unsigned int c) {

}

void uart_puts(char *str) {

}

void uart_2hex(unsigned int d) {

}

