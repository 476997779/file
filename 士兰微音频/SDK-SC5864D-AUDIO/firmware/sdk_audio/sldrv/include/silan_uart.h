/*
 * silan_uart.h
 *
 */
 
#ifndef __SILAN_UART_H__
#define __SILAN_UART_H__

#include "silan_types.h"
#include "ap1508.h"
#include "assert.h"
#include "silan_ringbuffer.h"
#include "silan_config.h"

#define SILAN_UART1_PHY_BASE        SPER_APB1_UARTHS_BASE
#define SILAN_UART2_PHY_BASE        SPER_APB1_UART2_BASE
#define SILAN_UART3_PHY_BASE        SPER_APB1_UART3_BASE
#define SILAN_UART4_PHY_BASE        SPER_APB1_UART4_BASE

#define SILAN_UART1_BASE            SILAN_UART1_PHY_BASE
#define SILAN_UART2_BASE            SILAN_UART2_PHY_BASE
#define SILAN_UART3_BASE            SILAN_UART3_PHY_BASE
#define SILAN_UART4_BASE            SILAN_UART4_PHY_BASE

#define UART1_BASE                  SILAN_UART1_PHY_BASE
#define UART2_BASE                  SILAN_UART2_PHY_BASE
#define UART3_BASE                  SILAN_UART3_PHY_BASE
#define UART4_BASE                  SILAN_UART4_PHY_BASE

#define SILAN_UART_BASE(x)  		(SPER_APB1_UARTHS_BASE + (x-1)*0x10000)

#define UART_DR                     0x00     /*  Data read or written from the interface. */
#define UART_RSR                    0x04     /*  Receive status register (Read). */
#define UART_FR                     0x18     /*  Flag register (Read only). */
#define UART_ILPR                   0x20
#define UART_IBRD                   0X24
#define UART_FBRD                   0X28
#define UART_LCRH                   0X2C
#define UART_CR                     0X30
#define UART_FLS                    0X34
#define UART_INT				    0X38
#define UART_RIS				    0X3C
#define UART_INT_STA			    0X40
#define UART_INT_CLR			    0X44
#define UART_DMA_CR			        0X48
#define UART_TCR			        0X80
#define UART_TITIP			        0X84
#define UART_TITOP			        0X88
#define UART_TDR			        0X8C
#define UART_PERIPHID0			    0XFE0
#define UART_PERIPHID1			    0XFE4
#define UART_PERIPHID2			    0XFE8
#define UART_PERIPHID3			    0XFEC
#define UART_PCELLID0			    0XFF0
#define UART_PCELLID1			    0XFF4
#define UART_PCELLID2			    0XFF8
#define UART_PCELLID3			    0XFFC

/*UART_RSR*/
#define UART_RSR_OE                 (1 << 0)
#define UART_RSR_BE                 (1 << 1)
#define UART_RSR_PE                 (1 << 2)
#define UART_RSR_FE                 (1 << 3)


/*UART_FR*/
#define UART_FR_CTS                 (1 << 0)
#define UART_FR_DSR                 (1 << 1)
#define UART_FR_DCD                 (1 << 2)
#define UART_FR_BUSY                (1 << 3)
#define UART_FR_RXFE                (1 << 4)
#define UART_FR_TXFF                (1 << 5)
#define UART_FR_RXFF                (1 << 6)
#define UART_FR_TXFE                (1 << 7)
#define UART_FR_RI                  (1 << 8)


/*UART_LCRH*/
#define UART_LCRH_BRK               (1 << 0)
#define UART_LCRH_PEN               (1 << 1)
#define UART_LCRH_EPS               (1 << 2)
#define UART_LCRH_STP2              (1 << 3)
#define UART_LCRH_FEN               (1 << 4)
#define UART_LCRH_WLEN_5            (0 << 5)
#define UART_LCRH_WLEN_6            (1 << 5)
#define UART_LCRH_WLEN_7            (2 << 5)
#define UART_LCRH_WLEN_8            (3 << 5)
#define UART_LCRH_SPS               (1 << 7)

/*UART_CR*/
#define UART_CR_UARTEN              (1 << 0)
#define UART_CR_SIREN               (1 << 1)
#define UART_CR_SIRLP               (1 << 2)
#define UART_CR_LPE                 (1 << 7)
#define UART_CR_TXE                 (1 << 8)
#define UART_CR_RXE                 (1 << 9)
#define UART_CR_DTS                 (1 << 10)
#define UART_CR_RTS                 (1 << 11)
#define UART_CR_OUT1                (1 << 12)
#define UART_CR_OUT2                (1 << 13)
#define UART_CR_RTSEN               (1 << 14)
#define UART_CR_CTSEN               (1 << 15)


/*UART_FLS*/
#define UART_FLS_TXIFLSEL_1         (0 << 0)
#define UART_FLS_TXIFLSEL_2         (1 << 0)
#define UART_FLS_TXIFLSEL_4         (2 << 0)
#define UART_FLS_TXIFLSEL_6         (3 << 0)
#define UART_FLS_TXIFLSEL_7         (4 << 0)
#define UART_FLS_RXIFLSEL_1         (0 << 3)
#define UART_FLS_RXIFLSEL_2         (1 << 3)
#define UART_FLS_RXIFLSEL_4         (2 << 3)
#define UART_FLS_RXIFLSEL_6         (3 << 3)
#define UART_FLS_RXIFLSEL_7         (4 << 3)

#define UART_INT_OE                 (1 << 10)
#define UART_INT_BE                 (1 << 9)
#define UART_INT_PE                 (1 << 8)
#define UART_INT_FE                 (1 << 7)
#define UART_INT_RT                 (1 << 6)
#define UART_INT_TX                 (1 << 5)
#define UART_INT_RX                 (1 << 4)
#define UART_INT_DSR                (1 << 3)
#define UART_INT_DCD                (1 << 2)
#define UART_INT_CTS                (1 << 1)
#define UART_INT_RI                 (1 << 0)

typedef struct UART_core_regs
{
    __IO uint32_t		UARTDR;
	__IO uint32_t		UARTRSR_ECR;
	__IO uint32_t		RESERVED0[4];
	__IO uint32_t		UARTFR;
	__IO uint32_t		RESERVED1;
	__IO uint32_t		UARTILPR;
	__IO uint32_t		UARTIBRD;
    __IO uint32_t		UARTFBRD;
    __IO uint32_t		UARTLCR_H;
    __IO uint32_t		UARTCR;
    __IO uint32_t		UARTIFLS;
    __IO uint32_t		UARTIMSC;
    __IO uint32_t		UARTRIS;
    __IO uint32_t		UARTMIS;
    __IO uint32_t		UARTICR;
    __IO uint32_t		UARTDMACR;
}
UART_CORE_REGS, *PUART_CORE_REGS;

typedef union UART_lcrh_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t brk : 1;
        uint32_t pen : 1;
        uint32_t even : 1;
        uint32_t stp2 : 1;
        uint32_t fen : 1;
        uint32_t wlen : 2;
        uint32_t sps : 1;
        uint32_t reserved8_31 : 24;
    }
    b;
} UART_LCRH_REGS ;

typedef union UART_cr_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t uarten : 1;
        uint32_t siren : 1;
        uint32_t sirlp : 1;
        uint32_t reserved3_6 : 4;
        uint32_t lbe : 1;
        uint32_t txe : 1;
        uint32_t rxe : 1;
        uint32_t dtr : 1;
        uint32_t rts : 1;
        uint32_t reserved12_31 : 20;
    }
    b;
} UART_CR_REGS ;

typedef union UART_ifls_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t txiflsel : 3;
        uint32_t rxiflsel : 3;
        uint32_t reserved6_31 : 26;
    }
    b;
} UART_IFLS_REGS ;

typedef union UART_dmacr_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t rxdmae : 1;
        uint32_t txdmae : 1;
				uint32_t dmaonerr : 1;
        uint32_t reserved3_31 : 29;
    }
    b;
} UART_DMACR_REGS ;

#define SILAN_UART_INST		4
#define SILAN_UART_FIFO     64

#define UART_1 				1
#define UART_2 				2
#define UART_3 				3
#define UART_4 				4

#define SILAN_UART1			1
#define SILAN_UART2			2
#define SILAN_UART3			3
#define SILAN_UART4			4

#define BAUDRATE_9600       9600

#define BAUDRATE_115200     115200
#define BAUDRATE_230400     230400
#define BAUDRATE_460800     460800
#define BAUDRATE_921600     921600
#define BAUDRATE_1152000    1152000


typedef enum UART_wlen
{
	UART_WLEN_5BIT		= 0,
	UART_WLEN_6BIT,
	UART_WLEN_7BIT,
	UART_WLEN_8BIT,
}
UART_WLEN;

typedef enum UART_parity
{
	UART_PARITY_ODD		= 0,
	UART_PARITY_EVEN,
}
UART_PARITY;

typedef enum UART_ifls
{
	UART_IFLS_1_8	= 0,
	UART_IFLS_1_4,
	UART_IFLS_1_2,
	UART_IFLS_3_4,
	UART_IFLS_7_8,
}
UART_IFLS;

typedef struct UART_cfg
{
    uint8_t         id;
    uint32_t        baudrate;
	uint8_t 		parity;
    uint8_t         even;
    uint8_t         stop2;
    uint8_t         wlen;
    
    uint8_t         fifo_disable;
    uint8_t         simplex;
    uint8_t         stream;     // With TX/RX Software buffer
    RB_HANDLE  		*rb_rcv;
		uint8_t					tx_srcid;
	uint8_t						tx_dma_en;
}
UART_CFG, *PUART_CFG;

typedef struct UART_port
{
	UART_CFG		uart_cfg;
    UART_CORE_REGS	*regs;
}
UART_PORT, *PUART_PORT;

typedef struct UART_xfer
{
	uint32_t        xfer_size;      // Transfer size, Bytes
	int8_t          *tx_buf;
}
UART_XFER, *PUART_XFER;

#ifdef UART_USER_CONFIG
#define UART_RCV_BUF_SIZE       USER_UART_RCV_BUF_SIZE
#else
#define UART_RCV_BUF_SIZE       128
#endif

int32_t serial_putc(const char c);
int32_t serial_getc(char *c);
void silan_uart_sys_init(uint32_t addr,uint32_t baudrate);

#ifndef _SUPPORT_UART_NEW_
int32_t silan_uart_putc(uint32_t uart_addr, char c);
int32_t silan_uart_getc(unsigned int uart_addr);
void silan_uart_config(uint32_t uart_addr, uint32_t baudrate, uint32_t en_fifo, uint32_t en_intr); 
int32_t serial_clear(void);
int32_t silan_uart_getc_noblock(uint32_t uart_addr, uint8_t *c);

int32_t silan_uart_tstc(uint32_t uart_addr);

#else
int32_t silan_uart_setup(UART_CORE_REGS *regs, UART_CFG *cfg);
int32_t silan_console_setup(uint8_t id, uint32_t baudrate);
int32_t silan_console_setup(uint8_t id, uint32_t baudrate);
int32_t silan_uart_read(UART_PORT *port, int8_t *data, int32_t *size);
int32_t silan_uart_fullness(UART_PORT *port, int32_t *size);
int32_t silan_uart_write(UART_PORT *port, int8_t *data, int32_t *size);
int32_t silan_uart_open(UART_PORT *port, uint8_t id);
void silan_uart_read_flush(UART_PORT *port);

void silan_printf_onoff(char onoff);
#endif

#endif //__SILAN_UART_H__

