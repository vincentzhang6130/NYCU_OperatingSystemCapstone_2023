void uart_init(){

    // Set AUXENB register to enable mini UART. Then mini UART register can be accessed.

    // Set AUX_MU_CNTL_REG to 0. Disable transmitter and receiver during configuration.

    // Set AUX_MU_IER_REG to 0. Disable interrupt because currently you don’t need interrupt.

    // Set AUX_MU_LCR_REG to 3. Set the data size to 8 bit.

    // Set AUX_MU_MCR_REG to 0. Don’t need auto flow control.

    // Set AUX_MU_BAUD to 270. Set baud rate to 115200

    // Set AUX_MU_IIR_REG to 6. No FIFO.

    // Set AUX_MU_CNTL_REG to 3. Enable the transmitter and receiver.
}

char uart_recv() {
  
}

void uart_send(unsigned int c) {

}

void uart_puts(char *str) {

}

void uart_2hex(unsigned int d) {

}

