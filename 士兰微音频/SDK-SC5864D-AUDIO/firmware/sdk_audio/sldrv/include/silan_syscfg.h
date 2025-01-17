/*
 * silan_syscfg.h
 */

#ifndef __SILAN_SYSCFG_H__
#define __SILAN_SYSCFG_H__

#include "silan_config.h"

#include "silan_types.h"
#include "ap1508.h"

#define SILAN_SYSCFG_BASE               SCFG_APB_SYSCFG_ADDR_BASE


#define SILAN_SYSCFG_REG0            	(SILAN_SYSCFG_BASE + 0x00)
#define SILAN_SYSCFG_REG1            	(SILAN_SYSCFG_BASE + 0x04)

#define SILAN_SYSCFG_REG3           	(SILAN_SYSCFG_BASE + 0x0c)
#define SILAN_SYSCFG_REG4           	(SILAN_SYSCFG_BASE + 0x10)
#define SILAN_SYSCFG_REG2               (SILAN_SYSCFG_BASE + 0x08)
#define SILAN_SYSCFG_REG9				(SILAN_SYSCFG_BASE + 0x24)
#define SILAN_SYSCFG_REG11				(SILAN_SYSCFG_BASE + 0x2c)
#define SILAN_SYSCFG_REG12				(SILAN_SYSCFG_BASE + 0x30)

/********************************************************************
*                           audio clock                             *
********************************************************************/
#define SILAN_SYSCFG_REG5             	(SILAN_SYSCFG_BASE + 0x14)
#define SILAN_SYSCFG_REG6             	(SILAN_SYSCFG_BASE + 0x18)
#define SILAN_SYSCFG_REG7             	(SILAN_SYSCFG_BASE + 0x1C)
#define SILAN_SYSCFG_REG15			  	(SILAN_SYSCFG_BASE + 0x3c)
#define SILAN_SYSCFG_REG16			  	(SILAN_SYSCFG_BASE + 0x40)
#define SILAN_SYSCFG_REG17            	(SILAN_SYSCFG_BASE + 0x44)
#define SILAN_SYSCFG_REG18            	(SILAN_SYSCFG_BASE + 0x48)
#define SILAN_SYSCFG_REG19            	(SILAN_SYSCFG_BASE + 0x4C)

#define SILAN_SYSCFG_REG8             	(SILAN_SYSCFG_BASE + 0x20)
#define SILAN_SYSCFG_REG13            	(SILAN_SYSCFG_BASE + 0x34)

/*
GPIO PULL UP
*/
#define SILAN_SYSCFG_CTRPAD0            (SILAN_SYSCFG_BASE + 0x100)  
#define SILAN_SYSCFG_CTRPAD1            (SILAN_SYSCFG_BASE + 0x104) 
#define SILAN_SYSCFG_CTRPAD2            (SILAN_SYSCFG_BASE + 0x108) 
#define SILAN_SYSCFG_CTRPAD3            (SILAN_SYSCFG_BASE + 0x10c) 
#define SILAN_SYSCFG_CTRPAD4            (SILAN_SYSCFG_BASE + 0x110) 
#define SILAN_SYSCFG_CTRPAD5            (SILAN_SYSCFG_BASE + 0x114) 
#define SILAN_SYSCFG_CTRPAD6            (SILAN_SYSCFG_BASE + 0x118) 
#define SILAN_SYSCFG_CTRPAD7            (SILAN_SYSCFG_BASE + 0x11c) 
#define SILAN_SYSCFG_CTRPAD8            (SILAN_SYSCFG_BASE + 0x120) 
#define SILAN_SYSCFG_CTRPAD9            (SILAN_SYSCFG_BASE + 0x124) 
#define SILAN_SYSCFG_CTRPAD10           (SILAN_SYSCFG_BASE + 0x128) 

#define SILAN_SYSCFG_DKEY(n)            (SILAN_SYSCFG_BASE + 0x200 + n*4)

#define SILAN_SYSCFG_SOC0               (SILAN_SYSCFG_BASE + 0x300)
#define SILAN_SYSCFG_SOC1               (SILAN_SYSCFG_BASE + 0x304)

#define SILAN_SYSCFG_PD                 (SILAN_SYSCFG_BASE + 0x600) 

#define SILAN_SYSSTS_PD                 (SILAN_SYSCFG_BASE + 0xF10)

typedef union misc_clk_reg1 {
	/** raw data */
	uint32_t d32;
	/** bits def */
	struct {
		unsigned ispdif_clksel:3;
#define ISPDIF_CCLK_APLL_DIV1    0
#define ISPDIF_CCLK_APLL_DIV2    1
#define ISPDIF_CCLK_APLL_DIV3    2
#define ISPDIF_CCLK_APLL_DIV4    3
#define ISPDIF_CCLK_CLKSYS_DIV1  4
#define ISPDIF_CCLK_CLKSYS_DIV2  5
#define ISPDIF_CCLK_CLKSYS_DIV3  6
#define ISPDIF_CCLK_CLKSYS_DIV4  7

		unsigned ispdif_clkon:1;
		unsigned reserved0:4;
		unsigned sd_clksel:2;
#define SD_CCLK_CLKSYS_DIV1    0
#define SD_CCLK_CLKSYS_DIV2    1
#define SD_CCLK_PLLREF_DIV2    2
#define SD_CCLK_RCL_DIV2       3

		unsigned reserved1:1;
		unsigned sd_clkon:1;
		unsigned sdio_clksel:2;
#define SDIO_CCLK_CLKSYS_DIV1    0
#define SDIO_CCLK_CLKSYS_DIV2    1
#define SDIO_CCLK_PLLREF_DIV2    2
#define SDIO_CCLK_RCL_DIV2       3

		unsigned reserved2:1;
		unsigned sdio_clkon:1;
		unsigned otp_clksel:2;
#define OTP_CCLK_PLLREF_DIV2    0
#define OTP_CCLK_CLKSYS_DIV8    1
#define OTP_CCLK_CLKSYS_DIV16   2
#define OTP_CCLK_RCL_DIV2       3

		unsigned reserved3:1;
		unsigned otp_clkon:1;
		unsigned reserved4:3;
		unsigned codec1_clkon:1;
		unsigned codec2_clkon:1;
		unsigned reserved5:7;
	} __attribute__((packed)) b;
} __attribute__((packed)) misc_clk_reg1_t;

typedef union misc_clk_reg2 {
	/** raw data */
	uint32_t d32;
	/** bits def */
	struct {
		unsigned pwm_clksel:2;
#define PWM_CCLK_CLKSYS_DIV2    0
#define PWM_CCLK_CLKSYS_DIV4    1
#define PWM_CCLK_PLLREF_DIV2    2
#define PWM_CCLK_RCL_DIV2       3

		unsigned reserved0:1;
		unsigned pwm_clkon:1;
		unsigned adc_clksel:2;
#define ADC_CCLK_CLKSYS_DIV8    0
#define ADC_CCLK_CLKSYS_DIV12   1
#define ADC_CCLK_PLLREF_DIV2    2
#define ADC_CCLK_RCL_DIV2       3

		unsigned reserved1:1;
		unsigned adc_clkon:1;
		unsigned reserved2:12;
		unsigned timer_clksel:2;
#define TIMER_CCLK_CLKSYS_DIV2    0
#define TIMER_CCLK_CLKSYS_DIV3    1
#define TIMER_CCLK_PLLREF_DIV2    2
#define TIMER_CCLK_RCL_DIV2       3

		unsigned reserved3:1;
		unsigned timer_clkon:1;
		unsigned rtc_clkon:1;
		unsigned usbfs_clkon:1;
		unsigned pdp_clksel1:2;
#define PDP_CCLK_CLKSYS_DIV4    0
#define PDP_CCLK_CLKSYS_DIV8    1
#define PDP_CCLK_PLLREF_DIV12   2
#define PDP_CCLK_RCL_DIV2       3

		unsigned pdp_clksel2:2;
#define PDP_CCLK_POST_DIV1    0
#define PDP_CCLK_POST_DIV2    1
#define PDP_CCLK_POST_DIV4    2
#define PDP_CCLK_POST_DIV8    3

		unsigned pdp_clkon:1;
		unsigned reserved4:1;
	} __attribute__((packed)) b;
} __attribute__((packed)) misc_clk_reg2_t;

typedef union SOC_clk_reg {
	/** raw data */
	uint32_t d32;
	/** bits def */
	struct {
		unsigned reserved0:2;
		unsigned risc_cclkon:1;
		unsigned dsp_cclkon:1;
		unsigned mcu_cclkon:1;
		unsigned bus_clksel:1;
		unsigned dsp_cclksel:1;
		unsigned sf_hclksel:1;
		unsigned syspre_clksel:2;
		unsigned mcu_cclksel:2;
		unsigned reserved1:2;
		unsigned dsp_hclkon:1;
		unsigned reserved2:5;
		unsigned lp_en:1;
		unsigned reserved3:2;
		unsigned lp_otp_clkon:1;
		unsigned lp_shdw_clkon:1;
		unsigned lp_bus_clkon:1;
		unsigned lp_sf_clkon:1;
		unsigned lp_sdram_clkon:1;
		unsigned lp_sr_clkon:1;
		unsigned reserved4:3;
	} __attribute__((packed)) b;
} __attribute__((packed)) SOC_CLK_REG;


#if defined(__CSKY__)
#include "csi_core.h"
#endif

typedef enum {
	CLK_OFF = 0,
	CLK_ON
} silan_clk_onff_t;

typedef enum {
	SYSCLK_DIV1 = 0,
	SYSCLK_DIV2,
	SYSCLK_DIV3,
	SYSCLK_DIV4
} silan_presys_clksel_t;

/*
silan mcu cclk config
*/
typedef enum{
	MCU_CCLK_DIV1=0,
	MCU_CCLK_DIV2,
	MCU_CCLK_DIV4
}silan_mcu_cclksel_t;

typedef enum {
	DCACHE_MODE_DC = 0,
	DCACHE_MODE_MEM
} silan_dcache_mode_t;

typedef enum {
	DSP_BOOT_FLASH = 0,
	DSP_BOOT_SDRAM
} silan_dsp_boot_t;

#if defined(__XCC__)
static inline uint32_t cpu_to_dma(uint32_t addr)
{
	/*
	 * dsp inner sram addr is 0x30XX_XXXX,
	 * but dmac accesses them at 0x23XX_XXXX.
	 *
	 * dmac can't access SDRAM at 0x02XX_XXXX,
	 * but accesses them at 0x22XX_XXXX.
	 * TODO, SDRAM maybe on 0x00XX_XXXX.
	 */
	switch (addr&(0xff000000)) {
		case 0x30000000 :
			return 0x23000000 | (addr & 0x00ffffff);
		case 0x02000000 :
			return 0x22000000 | (addr & 0x00ffffff);
		default:
			return addr;
	}
}

static inline uint32_t dma_to_cpu(uint32_t addr)
{
	/*
	 * dsp inner sram addr is 0x30XX_XXXX,
	 * but dmac accesses them at 0x23XX_XXXX.
	 *
	 * dmac can't access SDRAM at 0x02XX_XXXX,
	 * but accesses them at 0x22XX_XXXX.
	 * TODO, SDRAM maybe on 0x00XX_XXXX.
	 */
	switch (addr&(0xff000000)) {
		case 0x23000000 :
			return 0x30000000 | (addr & 0x00ffffff);
		case 0x22000000 :
			return 0x02000000 | (addr & 0x00ffffff);
		default:
			return addr;
	}
}
static inline void dcache_writeback(void *addr, uint32_t size)
{
	xthal_dcache_region_writeback(addr, size);
}

static inline void dcache_invalidate(void *addr, uint32_t size)
{
	xthal_dcache_region_invalidate(addr, size);
}
#endif

#if defined(__CC_ARM)
static inline uint32_t cpu_to_dma(uint32_t addr)
{
	return addr;
}

static inline uint32_t dma_to_cpu(uint32_t addr)
{
	return addr;
}

static inline void dcache_writeback(void *addr, uint32_t size)
{
	// do nothing!
}

static inline void dcache_invalidate(void *addr, uint32_t size)
{
	// do nothing!
}
#endif

#if defined(__CSKY__)
static inline uint32_t cpu_to_dma(uint32_t addr)
{
	switch (addr&(0xff000000)) {
		case 0x02000000 :
			return 0x22000000 | (addr & 0x00ffffff);
		default:
			return addr;
	}
}

static inline uint32_t dma_to_cpu(uint32_t addr)
{
	switch (addr&(0xff000000)) {
		case 0x22000000 :
			return 0x02000000 | (addr & 0x00ffffff);
		default:
			return addr;
	}
}

static inline void dcache_writeback(void *addr, uint32_t size)
{
	csi_dcache_clean_range(addr, size);
}

static inline void dcache_invalidate(void *addr, uint32_t size)
{
	csi_dcache_invalid_range(addr, size);
}
#endif

static inline uint32_t *ptr_cpu_to_dma(uint32_t *addr)
{
	return (uint32_t *)cpu_to_dma((uint32_t)addr);
}

static inline uint32_t *ptr_dma_to_cpu(uint32_t *addr)
{
	return (uint32_t *)dma_to_cpu((uint32_t)addr);
}

static inline void silan_dsp_dcache_cfg(int mode)
{
	if(mode == DCACHE_MODE_DC)
		__REG32(SILAN_SYSCFG_SOC1) |=  (0x1);
	else
		__REG32(SILAN_SYSCFG_SOC1) &= ~(0x1);
}

static inline void silan_risc_debug_open(void)
{
	__REG32(SILAN_SYSCFG_REG11) |=  (0x1<<21);
}

static inline void silan_risc_debug_close(void)
{
	__REG32(SILAN_SYSCFG_REG11) &= ~(0x1<<21);
}

static inline void silan_dsp_debug_open(void)
{
	__REG32(SILAN_SYSCFG_REG11) |=  (0x1<<22);
}

static inline void silan_dsp_debug_close(void)
{
	__REG32(SILAN_SYSCFG_REG11) &= ~(0x1<<22);
}

static inline void silan_mcu_debug_open(void)
{
	__REG32(SILAN_SYSCFG_REG11) |=  (0x1<<20);
}

static inline void silan_mcu_debug_close(void)
{
	__REG32(SILAN_SYSCFG_REG11) &= ~(0x1<<20);
}

static inline void silan_halt_dsp(void)
{
	__REG32(SILAN_SYSCFG_SOC0) |=  (0x1<<0);
}

static inline void silan_run_dsp(void)
{
	__REG32(SILAN_SYSCFG_SOC0) &= ~(0x1<<0);
}

inline static void silan_dsp_unreset(void)
{
	__REG32(SILAN_SYSCFG_REG11) |= (0x1<<2);
}
//-------------------------------------------
inline static void silan_dsp_reset(void)
{
	__REG32(SILAN_SYSCFG_REG11) &= ~(0x1<<2);
}
//-------------------------------------------
inline static void silan_risc_unreset(void)
{
	__REG32(SILAN_SYSCFG_REG11) |= (0x1);
}
//-------------------------------------------
inline static void silan_risc_reset(void)
{
	__REG32(SILAN_SYSCFG_REG11) &= ~(0x1);
}
//-------------------------------------------
inline static void silan_remap_cnofig(uint8_t remap)
{
    __REG32(SILAN_SYSCFG_REG11) &= ~((1 << 29) | (1 << 28));
    __REG32(SILAN_SYSCFG_REG11) |= remap << 28;
}

void silan_otp_cclk_config(int clksel, silan_clk_onff_t onoff);
void silan_dsp_cclk_onoff(silan_clk_onff_t onoff);
void silan_risc_cclk_onoff(silan_clk_onff_t onoff);
void silan_dsp_boot_from(int media);
void silan_risc_boot(void);
void silan_dsp_reboot(void);
void silan_risc_reboot(void);

/*
 * return 0: request attachs to dmac0(ADMAC).
 *        1: request attachs to dmac1(SDMAC).
 */
int silan_syscfg_get_dmac_reqid(int id, int *dmac_req);

/*
silan misc clk config
*/
typedef enum{
		SILAN_SPDIF = 0,
		SILAN_SDMMC,
		SILAN_SDIO,
		SILAN_OTP,
		SILAN_CODEC1,
		SILAN_CODEC2,
		SILAN_PWM,
		SILAN_ADC,
		SILAN_TIMER,
		SILAN_RTC,
		SILAN_USBFS,
		SILAN_PDB,
		SILAN_SSP,
}silan_misc_clk_t;

/*
silan mcu clk config
*/
typedef enum{
	MCUCLK_BUS_1=0,
	MCUCLK_BUS_2,
	MCUCLK_BUS_4,
}silan_mcu_clk_t;


/*
if_div:
0: sysclk
1: sysclk/2
2: pll_ref/2
3: rcl/2

but:
SILAN_SPDIF
*/
void silan_system_misc_clk_config(silan_misc_clk_t misc_mode,int if_div);
void silan_mcuclk_div_config(silan_mcu_clk_t bus_div);
void silan_adc_cclk_config(int clksel, silan_clk_onff_t onoff);
void silan_pwm_cclk_config(int clksel, silan_clk_onff_t onoff);
void silan_vlsp_cclk_config(silan_clk_onff_t onoff);
void silan_usbfs_cclk_config(silan_clk_onff_t onoff);
void silan_codec1_cclk_config(silan_clk_onff_t onoff);
void silan_codec2_cclk_config(silan_clk_onff_t onoff);
void silan_sdio_cclk_config(int clksel, silan_clk_onff_t onoff);
void silan_sd_cclk_config(int clksel, silan_clk_onff_t onoff);
void silan_syspre_clksel(silan_presys_clksel_t div);

void silan_mcu_cclksel(silan_mcu_cclksel_t bus_div);
void silan_timer_cclk_config(int clksel, silan_clk_onff_t onoff);
void silan_bootup_dsp(uint32_t load_addr, uint32_t len, int media);
void silan_bootup_risc(uint32_t load_addr, uint32_t len);

uint32_t silan_get_timer_cclk(void);
uint32_t silan_get_mcu_cclk(void);
uint32_t silan_get_dsp_cclk(void);
uint32_t silan_get_bus_cclk(void);
uint32_t silan_get_sdio_cclk(void);
uint32_t silan_get_sd_cclk(void);

void silan_usb11_set_dev(void);
void silan_usb20_phy_init(void);
void silan_usb20_set_dev(void);

void silan_risc_cclk_onoff(silan_clk_onff_t onoff);
void silan_dsp_cclk_onoff(silan_clk_onff_t onoff);

void silan_dsp_power_domain_reset(void);

#define    SOFT_RST_SF1                  0
#define    SOFT_RST_SR1                  1
#define    SOFT_RST_SHDW                 2
#define    SOFT_RST_OTP                  (  3+(  4<<8))
#define    SOFT_RST_SDRAM                (  5+(  6<<8))
#define    SOFT_RST_SPER                 7
#define    SOFT_RST_APER                 8
#define    SOFT_RST_SCFG                 9
#define    SOFT_RST_PCFG                 10
#define    SOFT_RST_SDMMC                11
#define    SOFT_RST_SDIO                 12
#define    SOFT_RST_SDMAC                13
#define    SOFT_RST_OSPDIF               ( 14+( 15<<8))
#define    SOFT_RST_ISPDIF               ( 16+( 17<<8))
#define    SOFT_RST_I1_I2S               ( 18+( 19<<8))
#define    SOFT_RST_I2_I2S               ( 20+( 21<<8))
#define    SOFT_RST_I3_I2S               ( 22+( 23<<8))
#define    SOFT_RST_O1_I2S               ( 24+( 25<<8))
#define    SOFT_RST_O2_I2S               ( 26+( 27<<8))
#define    SOFT_RST_O3_I2S               ( 28+( 29<<8))
#define    SOFT_RST_PCM_I2S              ( 30+( 31<<8))
#define    SOFT_RST_PDM                  ( 32+( 33<<8))
#define    SOFT_RST_ADMAC                34
#define    SOFT_RST_GPIO1                35
#define    SOFT_RST_GPIO2                36
#define    SOFT_RST_SPI                  37
#define    SOFT_RST_UART1                38
#define    SOFT_RST_UART2                39
#define    SOFT_RST_UART3                40
#define    SOFT_RST_UART4                41
#define    SOFT_RST_I2C1                 42
#define    SOFT_RST_I2C2                 43
#define    SOFT_RST_CXC                  44
#define    SOFT_RST_IIR                  45
#define    SOFT_RST_TIMER                ( 46+( 47<<8))
#define    SOFT_RST_PMU                  48
#define    SOFT_RST_RTC                  49
#define    SOFT_RST_CODEC1               50
#define    SOFT_RST_CODEC2               51
#define    SOFT_RST_PDP                  ( 52+( 53<<8))
#define    SOFT_RST_PWM                  ( 54+( 55<<8))
#define    SOFT_RST_ADC                  ( 56+( 57<<8))

void silan_soft_rst(unsigned int mod);

#define    CLK_SDMMC                0
#define    CLK_SDIO                 1
#define    CLK_USBHS                2
#define    CLK_USBFS                3
#define    CLK_SDMAC                4
#define    CLK_OSPDIF               5
#define    CLK_ISPDIF               6
#define    CLK_I1_I2S               7
#define    CLK_I2_I2S               8
#define    CLK_I3_I2S               9
#define    CLK_O1_I2S               10
#define    CLK_O2_I2S               11
#define    CLK_O3_I2S               12
#define    CLK_PCM_I2S              13
#define    CLK_PDM                  14
#define    CLK_ADMAC                15
#define    CLK_GPIO1                16
#define    CLK_GPIO2                17
#define    CLK_SPI                  18
#define    CLK_UART1                19
#define    CLK_UART2                20
#define    CLK_UART3                21
#define    CLK_UART4                22
#define    CLK_I2C1                 23
#define    CLK_I2C2                 24
#define    CLK_PMU                  25
#define    CLK_CXC                  26
#define    CLK_IIR                  27
#define    CLK_TIMER                28
#define    CLK_PDP                  29
#define    CLK_PWM                  30
#define    CLK_ADC                  31
#define    CLK_SSP                  32

/*
 * app reset to bootload 
 * app程序复位重跑bootload
 * para : 重启后进入模式， 0表示ucp， 1表示iap
 */
void silan_app_goto_bootload(unsigned char para);


#endif  // __SILAN_SYSCFG_H__

