#ifndef	_RPI_UART1_H_
#define	_RPI_UART1_H_

#include "bcm2837/rpi_base.h"

// Memory mapping I/O
// 把暫存器映射到實體記憶體位置

/** 為什麼要用 volatile unsigned int*
 * 這些暫存器是位於記憶體映射I/O區域的硬體設備，可以被其他設備或中斷處理程序修改。
 * 為了確保程序能夠及時地讀取或寫入這些寄存器的值，必須將它們聲明為volatile型別，
 * 這樣可以告訴編譯器，在編譯代碼時不要將這些變量優化掉，
 * 以確保編譯器在生成機器碼時每次都能直接從記憶體中讀取或寫入這些變量的值。
    此外，這些寄存器的值是32位的整數，因此使用unsigned int*型別聲明它們可以確保
    對這些變量進行32位的讀取和寫入操作。
    如果將一個0x開頭的數值直接賦值給一個指針變量，那麼這個指針變量的值將被設置為這個數值所表示的地址。
    但是，如果這個數值不是有效的地址，或者指針變量沒有被正確地初始化，那麼這樣的操作就可能導致程序錯誤或崩潰
*/

// 把16進位數值轉型成指標變量，之後就可以對這個指標變量dereference 得到地址
#define AUX_ENABLES     ((volatile unsigned int*)(PERIPHERAL_BASE+0x00215004))
#define AUX_MU_IO_REG   ((volatile unsigned int*)(PERIPHERAL_BASE+0x00215040))
#define AUX_MU_IER_REG  ((volatile unsigned int*)(PERIPHERAL_BASE+0x00215044))
#define AUX_MU_IIR_REG  ((volatile unsigned int*)(PERIPHERAL_BASE+0x00215048))
#define AUX_MU_LCR_REG  ((volatile unsigned int*)(PERIPHERAL_BASE+0x0021504C))
#define AUX_MU_MCR_REG  ((volatile unsigned int*)(PERIPHERAL_BASE+0x00215050))
#define AUX_MU_LSR_REG  ((volatile unsigned int*)(PERIPHERAL_BASE+0x00215054))
#define AUX_MU_MSR_REG  ((volatile unsigned int*)(PERIPHERAL_BASE+0x00215058))
#define AUX_MU_SCRATCH  ((volatile unsigned int*)(PERIPHERAL_BASE+0x0021505C))
#define AUX_MU_CNTL_REG ((volatile unsigned int*)(PERIPHERAL_BASE+0x00215060))
#define AUX_MU_STAT_REG ((volatile unsigned int*)(PERIPHERAL_BASE+0x00215064))
#define AUX_MU_BAUD_REG ((volatile unsigned int*)(PERIPHERAL_BASE+0x00215068))

#endif  /*_RPI_UART1_H_ */