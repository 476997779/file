#ifndef __SILAN_SDRAM_H__
#define __SILAN_SDRAM_H__

#include "silan_types.h"
#include "ap1508.h"

#define SDRAM_CFG_REG0      __REG32(PCFG_SF2_ADDR_BASE + 0x000)
#define SDRAM_CFG_REG1      __REG32(PCFG_SF2_ADDR_BASE + 0x004)
#define SDRAM_CFG_REG2      __REG32(PCFG_SF2_ADDR_BASE + 0x008)

#define SDR_PD_SREF_REQ     (1 << 0)
#define SDR_PD_PDN_REQ      (1 << 1)
#define SDR_PD_DPDN_REQ     (1 << 2)

#define SDR_PD_SREF_ACK     (1 << 4)
#define SDR_PD_PDN_ACK      (1 << 5)
#define SDR_PD_DPDN_ACK     (1 << 6)

typedef enum{
	SDR_CAP_1M = 1,
	SDR_CAP_2M = 2,
	SDR_CAP_8M = 8,
	SDR_CAP_32M = 32,
}sdram_cap_t;

typedef enum {
	SDR_MODE_SREF = 0,
	SDR_MODE_PDN,
	SDR_MODE_DPDN,
    SDR_MODE_NORMAL,
} sdram_mode_t;

#define SDRAM_REFCNT(m)    (((int)(m * 78 / 10)) & 0xFFFF)

#define SDRAM_PARA		0x6A21

uint8_t silan_sdram_init(void);  
int32_t silan_sdram_mode(sdram_mode_t mode);

uint8_t silan_get_sdram_cap(void);

#endif

