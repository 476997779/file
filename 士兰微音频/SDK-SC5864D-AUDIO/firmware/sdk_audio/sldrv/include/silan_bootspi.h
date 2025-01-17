/*
 * silan_bootspi.h
 */

#ifndef __SILAN_BOOTSPI_H__
#define __SILAN_BOOTSPI_H__

#include "silan_types.h"

typedef volatile struct spi_struct
{
		unsigned int  main_ctrl;           // offset 0x000
		unsigned int  flash_power_down;     // 0x004
    unsigned int  flash_power_up;     // 0x008
    unsigned int  reserv1[5]; 
		unsigned int  cache_config;        // offset 0x020
		unsigned int  cache_sub_config;        // offset 0x024
		unsigned int  cache_crc_addr;            // offset 0x028
		unsigned int  cryp_code;            // offset 0x02c
    unsigned int  flash_addr_mask;            // offset 0x30
    unsigned int  reserv2[3]; 
		unsigned int  spi_config;          // offset 0x040
    unsigned int  spi_sub_config;          // offset 0x044
    unsigned int  spi_cmd;             // offset 0x048
    unsigned int  spi_addr;             // offset 0x04c
		unsigned int  spi_ctrl;            // offset 0x050
		unsigned int  spi_subctrl;         // offset 0x054
		unsigned int  spi_wdata;           // offset 0x058
		unsigned int  spi_rdata;           // offset 0x05c
    unsigned int  reserv3[8]; //offset 0x060
    unsigned int  spicache_intr; //offset 0x080
		unsigned int  reserv4[3]; //offset 0x084
		unsigned int  softreset;           // offset 0x090
		unsigned int  key;                 // offset 0x094
		unsigned int  reserv0[27];        // offset 0x040 ~ 0x0fc reserved
		unsigned int  id_code;             // offset 0x100
  	unsigned int  reserv[31];             // offset 0x104
		unsigned int  cache_state;         // offset 0x180
		
}spi_struct_t;

#define spi_st  ((spi_struct_t *)0x43400000)

// main_ctrl
#define FLASH_PWD_RESUME_EN              (1 <<25)
#define SPICACHE_SYSRST_EN              (1 <<24)
#define HOST_NOT_CACHE                  (1 << 16)

//cache_sub_config
#define CACHE_CRC_LIMIT_ERR_NUM(x)            ((x&0x3fU) << 26)
#define CACHE_CRC_ERR_OUT_EN            (1 << 25)
#define CACHE_CRC_ENABLE                (1 << 24)
#define CACHE_CRC_TRAP_FIRST_ADDR_EN                (1 << 23)
#define CACHE_CRM_DATA(x)                    ((x&0xff) << 8)
#define CACHE_CMD(x)                    ((x&0xff))

// cache_config
#define CACHE_SET_CFG                   ((unsigned int)1 << 31)
#define CAHCE_DTR_MODE                  ((unsigned int)1 << 28)
#define CACHE_DUMMY_CLK(x)                 ((x&0xff) << 16)
#define CACHE_CRM_NOCMD                     ((unsigned int)1 << 13)
#define CACHE_CRM_EXIST                     ((unsigned int)1 << 12)


#define CACHE_CMD_WIREMODE(x)                     ((unsigned int) (x&0x03))   
#define CACHE_ADDR_WIREMODE(x)                    ((unsigned int) (x&0x03)<< 4)
#define CACHE_DATA_WIREMODE(x)                    ((unsigned int) (x&0x03)<< 24)
#define CACHE_ADDR_XBYTE(x)                     ((x&0xff) <<6)

// spi_config 
//#define SPI_SET_CFG                   ((unsigned int)1 << 31)
#define SPI_DATA_WIREMODE(x)                     ((unsigned int) (x&0x03)<< 28)
#define HOST_CRM_DATA(x)                 ((unsigned int)(x&0xff) << 16)
#define HOST_CRM_EXIST                 ((unsigned int)(1) <<24)
#define HOST_CRM_NOCMD                 ((unsigned int)(1) <<25)
#define SPI_DUMMY_CLK(x)                 ((unsigned int)(x&0xff) << 8)
#define Host_Cmd  1
#define Host_Data 2
#define Host_Addr 3
#define SPI_CMD_WIREMODE(x)                     ((unsigned int) (x&0x03))   
#define SPI_ADDR_WIREMODE(x)                    ((unsigned int) (x&0x03)<< 4)
#define SPI_ADDR_XBYTE(x)                     ((unsigned int) (x&0x03)<< 6)

// spi_sub_config
#define SPI_SET_CFG                   ((unsigned int)1 << 31)
#define NO_PROREADING                   ((unsigned int)1 << 24)
#define SPI_RCV_CPOL                   ((unsigned int)1 << 20)
#define SPI_CLK_DIV(x)                   ((x&0x7) << 10)
#define SPI_CS_SEL(x)                   ((x&0x3) << 16)
#define SPI_IDLE_NUM(x)                   (((unsigned int)x&0x3ff))



// spicmd
#define SPI_OP_CMD(x)                   ((unsigned int)(x & 0xff))
//SPI ADDR
#define SPI_OP_ADDR(x)                  ((unsigned int)(x & 0xffffffff) )

// spi_ctrl
#define FAST_READ_WRITE									((unsigned int)1 << 31)
#define HOST_RREQ                       (1 << 8)
#define HOST_WREQ                       (1 << 0)

// spi_subctrl
#define HOST_DATA_NUM(x)                ((unsigned int)(x & 0x3) << 24)
#define HOST_SPI_TRANS_IDLE             ((unsigned int)1 << 20)
#define HOST_SPI_DONE_STATUS            ((unsigned int)1 << 16)
#define HOST_RREADY                     (1 << 9)
#define HOST_RVALID                     (1 << 8)
#define HOST_WREADY                     (1 << 1)
#define HOST_WVALID                     (1 << 0)

// key
#define KEY0                            0x81058888
#define KEY1                            0xf2370609
#define KEY2                            0x35051f3c

#define Cache_Cmd  1
#define Cache_Data 2
#define Cache_Addr 3

//#define BOOTSPI_SUPPORT_CACHELOCK

#define BOOTSPI_CFG_MOD_SINGLE           (0x0<<0)
#define BOOTSPI_CFG_MOD_DUAL             (0x1<<0)
#define BOOTSPI_CFG_MOD_QUAD             (0x2<<0)
#define BOOTSPI_CFG_MOD_MASK             (0x3<<0)
#define BOOTSPI_CFG_ADDR_WIDTH(x)        (((x)&0x3)<<2)
#define BOOTSPI_CFG_ADDR_WIDTH_MASK      (0x3<<2)
#define BOOTSPI_CFG_DATA_WIDTH(x)        (((x)&0x3)<<4)
#define BOOTSPI_CFG_DATA_WIDTH_MASK      (0x3<<4)
#define BOOTSPI_CFG_DTR                  (0x1<<6)
#define BOOTSPI_CFG_CRC                  (0x1<<7)
#define BOOTSPI_CFG_FASTMODE             (0x1<<8)
#define BOOTSPI_CFG_RCV_CPOL             (0x1<<9)
#define BOOTSPI_CFG_PROREAD            	 (0x1<<10)

#define BOOTSPI_CLK_DIV2                 (0x0)
#define BOOTSPI_CLK_DIV4                 (0x1)
#define BOOTSPI_CLK_DIV8                 (0x2)
#define BOOTSPI_CLK_DIV16                (0x3)
#define BOOTSPI_CLK_DIV32                (0x4)
#define BOOTSPI_CLK_DIV64                (0x5)
#define BOOTSPI_CLK_DIV128               (0x6)
#define BOOTSPI_CLK_DIV256               (0x7)

typedef enum {
		WRITE   =   0x02 , /* Write to Memory instruction */
		WRSR    =   0x01 , /* Write Status Register instruction */ 
		WREN    =   0x06 , /* Write enable instruction */
		READ    =   0x03 , /* Read from Memory instruction */
		RDSR    =   0x05 , /* Read Status Register instruction  */
		RDID    =   0x9F , /* Read identification */
		SE      =   0x20 , /* Sector Erase instruction */
		BE      =   0xD8 , /* Bulk Erase instruction */
		FASTREAD =  0x0b ,
		DUALREAD =  0x3b ,
		QUADREAD =  0x6b ,
	
		DUALIOREAD = 0xbb ,
		QUADIOREAD = 0xeb ,
		WORDQUADREAD =  0xe7 ,
		OCTALWORDQUADREAD =  0xe3 ,
			 
}spicmd;

typedef enum {
	SF_CMD_DE		= 0x0D, // Dual Edge
	SF_CMD_DDE		= 0xBD, // Dual Line Dual Edge
	SF_CMD_QDE		= 0xED, // Quad Line Dual Edge
	SF_CMD_READ		= 0x03, // Read
	SF_CMD_FR		= 0x0B, // Fast Read
	SF_CMD_FRD		= 0x3B, // Fast Read Dual
	SF_CMD_FRQ		= 0x6B, // Fast Read Quad
} bootspi_cache_cmd_t;

typedef struct {
	uint32_t cfg;
	uint32_t clk;
	uint32_t crc_tbl_addr;
}bootspi_t;

extern bootspi_t bootspi;
/*
bootspi_init()
clk_div :BOOTSPI_CLK_DIV x
mode_cfg:BOOTSPI_CFG_MOD_X
...
*/
int bootspi_init(uint32_t clk_div,uint32_t mode_cfg);
/*
bootspi_read32()
addr: addr%4k == 0
count:<=4k
...
*/
int bootspi_read32(uint32_t addr, uint32_t *buf, uint32_t count);
/*
bootspi_write32()
addr: addr%4k == 0
count;offset : count+offset<=1k
...
*/
int bootspi_write32(uint32_t addr, uint32_t *buf, uint32_t count,uint32_t offset);
/*
bootspi_read8()
addr: addr%4k == 0
count:<=4k
...
*/
int bootspi_read8(uint32_t addr, uint8_t *buf, uint32_t count);
/*
bootspi_write8()
addr: addr%4k == 0
count;offset : count+offset<=4k
...
*/
int bootspi_write8(uint32_t addr, uint8_t *buf, uint32_t count,uint32_t offset);
/*
bootspi_sectorerase()
addr: addr%4k == 0
...
*/
int bootspi_sectorerase(uint32_t addr, uint32_t bytes);
/*
bootspi_io_done()
spi busy wait
...
*/
int bootspi_io_done(void);

int spi_quad_status_done(void);
void ex_spiflash_power_recover_enable(uint8_t flash_recover_en);
void ex_spi_crc_enable(uint32_t addr);
void cache_spi_cmd_sel(uint8_t spi_cmd, uint8_t spi_div);

#endif

