/*
 * silan_i2c.h
 */

#ifndef __SILAN_I2C_H__
#define __SILAN_I2C_H__

#include "silan_types.h"
#include "silan_printf.h"

/************************** Regisster Definition ***************************/

#define SILAN_I2C1_ID           0
#define SILAN_I2C2_ID           1

#define SILAN_I2C_INST			(2)

#define	 IC_DATA_CMD_READ		0X0100

typedef enum SLAVE_event
{
	SLAVE_EVENT_START			= 0,
	SLAVE_EVENT_READ_REQUESTED,
	SLAVE_EVENT_READ_PROCESSED,
	SLAVE_EVENT_WRITE_REQUESTED,
	SLAVE_EVENT_WRITE_RECEIVED,
	SLAVE_EVENT_STOP,
}
SLAVE_EVENT;

typedef enum I2C_mode
{
	I2C_MODE_MASTER	= 1,
	I2C_MODE_SLAVE,
	I2C_MODE_DUAL,
}
I2C_MODE;

// address offset in strcture
typedef struct I2C_core_regs
{
	__IO uint32_t		IC_CON;
	__IO uint32_t		IC_TAR;
	__IO uint32_t		IC_SAR;
	__IO uint32_t		IC_HS_MADDR;
	__IO uint32_t		IC_DATA_CMD;
    __IO uint32_t		IC_SS_HCNT;
    __IO uint32_t		IC_SS_LCNT;
    __IO uint32_t		IC_FS_HCNT;
    __IO uint32_t		IC_FS_LCNT;
	__IO uint32_t		IC_HS_HCNT;
	__IO uint32_t		IC_HS_LCNT;
	__IO uint32_t		IC_INTR_STAT;
	__IO uint32_t		IC_INTR_MASK;
	__IO uint32_t		IC_RAW_INTR_STAT;
	__IO uint32_t		IC_RX_TL;
	__IO uint32_t		IC_TX_TL;
	__IO uint32_t		IC_CLR_INTR;
	__IO uint32_t		IC_CLR_RX_UNDER;
	__IO uint32_t		IC_CLR_RX_OVER;
	__IO uint32_t		IC_CLR_TX_OVER;
	__IO uint32_t		IC_CLR_RD_REQ;
	__IO uint32_t		IC_CLR_TX_ABRT;
	__IO uint32_t		IC_CLR_RX_DONE;
	__IO uint32_t		IC_CLR_ACTIVITY;
	__IO uint32_t		IC_CLR_STOP_DET;
	__IO uint32_t		IC_CLR_START_DET;
	__IO uint32_t		IC_CLR_GEN_CALL;
	__IO uint32_t		IC_ENABLE;
	__IO uint32_t		IC_STATUS;
	__IO uint32_t		IC_TXFLR;
	__IO uint32_t		IC_RXFLR;
	__IO uint32_t		RESERVED1;
	__IO uint32_t		IC_TX_ABRT_SOURCE;
	__IO uint32_t		RESERVED2;
	__IO uint32_t		IC_DMA_TDLR;
	__IO uint32_t		IC_DMA_RDLR;	
}
I2C_CORE_REGS, *PI2C_CORE_REGS;

typedef union I2C_iccon_regs
{
    uint32_t d32;
    struct
    {
        uint32_t master_mode : 1;		// width=1
        uint32_t speed1_2 : 2;
        uint32_t ic_10bitaddr_slave : 1;
        uint32_t ic_10bitaddr_master_rd_only : 1;
        uint32_t ic_restart_enable : 1;
        uint32_t ic_slave_disable : 1;
        uint32_t reserved7_31 : 25;
    }
    b;
} I2C_ICCON_REGS ;

typedef union I2C_ictar_regs
{
    uint32_t d32;
    struct
    {
        uint32_t ic_tar : 10;
        uint32_t gc_or_start : 1;
        uint32_t special : 1;
        uint32_t ic_10bitaddr_master : 1;
        uint32_t reserved13_31 : 19;
    }
    b;
} I2C_ICTAR_REGS ;

typedef union I2C_icenable_regs
{
    uint32_t d32;
    struct
    {
        uint32_t ic_en : 1;
		uint32_t fifo_en : 1;
        uint32_t reserved2_31 : 30;
    }
    b;
} I2C_ICENABLE_REGS ;

typedef union I2C_icstatus_regs
{
    uint32_t d32;
    struct
    {
        uint32_t activity : 1;
		uint32_t tfnf : 1;
        uint32_t tfe : 1;
		uint32_t rfne : 1;
		uint32_t rff : 1;
        uint32_t mst_activity : 1;
		uint32_t slv_activity : 1;
		uint32_t reserved7_31 : 25;
    }
    b;
} I2C_ICSTATUS_REGS ;

typedef union I2C_intr_regs
{
    uint32_t d32;
    struct
    {
        uint32_t rx_under : 1;
		uint32_t rx_over : 1;
        uint32_t rx_full : 1;
		uint32_t tx_over : 1;
		uint32_t tx_empty : 1;
        uint32_t rd_req : 1;
		uint32_t tx_abrt : 1;
		uint32_t rx_done : 1;
		uint32_t activity : 1;
		uint32_t stop_det : 1;
		uint32_t start_det : 1;
		uint32_t gen_call : 1;
		uint32_t reserved12_31 : 20;
    }
    b;
} I2C_INTR_REGS ;

typedef enum I2C_speed_mode
{
	I2C_SPEED_SS	= 1,
	I2C_SPEED_FS,
	I2C_SPEED_HS,
}
I2C_SPEED_MODE;

typedef struct I2C_cfg
{
	uint8_t			id;
	I2C_MODE		mode;
	I2C_SPEED_MODE	speed;
	
	uint8_t			slv_addr;
}
I2C_CFG, *PI2C_CFG;

typedef struct I2C_slave
{
	uint8_t        	slv_addr;
	
	int32_t			(*slv_cb)(SLAVE_EVENT event, int8_t *val);
}
I2C_SLAVE, *PI2C_SLAVE;

typedef struct I2C_port
{
	I2C_CFG		    i2c_cfg;
	I2C_SLAVE		*slv;
    I2C_CORE_REGS	*regs;
}
I2C_PORT, *PI2C_PORT;

typedef struct I2C_xfer
{
    uint8_t         slv_addr;		// slave address
    uint8_t         *data;			// buffer pointer in master memory
    uint16_t        len;
}
I2C_XFER, *PI2C_XFER;

// function declaration
static int32_t silan_i2c_config(I2C_CORE_REGS *regs, I2C_CFG *pcfg);
void silan_i2c_master(I2C_PORT *port, uint8_t id, I2C_SPEED_MODE spdmode);
int32_t silan_i2c_write(I2C_PORT *port, I2C_XFER *xfer);
int32_t silan_i2c_read(I2C_PORT *port, I2C_XFER *xfer);

void silan_i2c_slave(I2C_PORT *port, uint8_t id, I2C_SLAVE *slv);

#endif
