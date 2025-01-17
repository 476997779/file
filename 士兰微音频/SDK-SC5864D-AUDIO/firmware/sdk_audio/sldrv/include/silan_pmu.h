#ifndef _SILAN_PMU_H
#define _SILAN_PMU_H

#include "silan_types.h"
#include "silan_syscfg.h"

typedef volatile struct sysclk_struct
{
	uint32_t  write_key;         // offset 0x000
	uint32_t  sys_ctr0;          // offset 0x004
	uint32_t  sys_ctr1;          // offset 0x008
	uint32_t  sys_ctr2;          // offset 0x00C
	uint32_t  sys_sts;           // offset 0x010
	uint32_t  sys_wdt_tg;           // offset 0x014
	uint32_t  sys_pll_ctrl1;     // offset 0x018
	uint32_t  sys_pll_ctrl2;    	// offset 0x01c
	uint32_t  sscg;    						// offset 0x020
	uint32_t  audio_pll_ctrl1;    // offset 0x024
	uint32_t  audio_pll_ctrl2;    // offset 0x028
	uint32_t  iso_en;
	uint32_t  sys_wdt_clr;
}sysclk_struct_t;

#define sysclk_st  ((sysclk_struct_t *)0x42040000)

/******mode level*******/

//key
#define W_PROTECT_OPEN		0x05fa59a6
#define W_PROTECT_CLOSE		0xa05f0010


//sys_ctr0
#define	SYSCLK_EN						(1U<<31)
#define SYSCLK_CS(x)						((x&0x03)<<29)
#define RCL_EN							(1<<28)
#define RCH_EN							(1<<27)
#define OSC_EN							(1<<26)
#define SYS_PLL_EN						(1<<25)
#define _32KPLL_EN						(1<<24)
#define AUDIO_PLL_EN						(1<<23)
#define REF_CLK_CS						(1<<22)
#define USB20_CLK_CS(x)						((x&0x3)<<20)
#define USB20_SYSPLL_DIV(x)					((x&0x07)<<17)
#define TCK_CS(x)						((x&0x07)<<14)
#define U11BCK_DIV						(1<<13)
#define	OSC12M_CC						((x&0x07)<<10)
#define OSC12M_RSEL						(1<<9)
#define	UPLL32K_EN						(1<<8)
#define	UPLL32K_SEL(x)						((x&0x07)<<5)
#define	U11_BCK_EN						(1<<4)
#define	U11_BCK_PD						(1<<3)
#define	U11_BCK_REFSEL						(1<<2)
#define	U11_BCK_RSTN						(1<<1)
#define	U11_USB11_RSTN						(1<<0)
	

//sys_ctr1

#define CLKMUX_ERR_IRQ_EN			(1U<<31)
#define	CLKMUX_RESETORE_EN			(1<<30)
#define	WDT_WAKE_EN					(1<<29)
#define	IO_WAKE_EN					(1<<28)
#define	LVD_WAKE_EN					(1<<27)
#define	KEY_DET_EN					(1<<26)
#define	KEY_DET_MASK_EN				(1<<25)
#define	LVR_IRQ_EN					(1<<24)
#define	LVD_IRQ_EN					(1<<23)
#define	POC_IRQ_EN					(1<<22)
#define OSC_IRQ_EN					(1<<21)
#define	SPLL_IRQ_EN					(1<<20)
#define	RCH_IRQ_EN					(1<<19)
#define	_32KPLL_IRQ_EN				(1<<18)
#define	APLL_IRQ_EN					(1<<17)
#define	RCL_D(x)					((x&0x7f)<<10)
#define	RCH_FREQS(x)				((x&0x03)<<8)
#define	RCH_TRIM(x)					((x&(0xff))<<0)


//sys_ctr2
#define	SF_PWR					   	(1U<<31)
#define	OSC_PLL_SEL					(1<<30)
#define	SYS_WDT_IRQ_EN				(1<<29)
#define	SYS_WDT_RST_EN				(1<<28)
#define	RTC_WAKE_EN					(1<<27)
#define	SAR_VREF_SEL				(1<<26)
#define	UPLL_S_CMP					(1<<25)
#define	LVRLS(x)					((x&0x3)<<23)
#define	LVREN						(1<<22)
#define	LVDLS(x)					((x&0x7)<<19)
#define	LVDEN						(1<<18)
#define	BUFSEL						(1<<17)
#define	BUFEN						(1<<16)
#define	LDO_DSP_EN					(1<<10)
#define	VSEL(x)						((x&0x3)<<8)
#define	PMU_STOP					(1<<7)
#define	LVR_DSEL(x)					((x&0x3)<<5)
#define	LVR_MASK					(1<<4)
#define	POR_MASK					(1<<3)
#define	POR_TSTN_SEL				(1<<2)
#define	POR_DSEL(x)					((x&0x3)<<0)

//sys_sts
#define XRSN_STS					(1U<<31)
#define	POC_STS						(1<<30)
#define	POR_STS						(1<<29)
#define LVR_STS						(1<<28)
#define	LVD_STS						(1<<27)
#define	RCH_STB_ASYN				(1<<26)
#define	OSC_CLKDET					(1<<25)
#define	SPLL_LOCK					(1<<24)
#define	RCH_STS_REG					(1<<23)
#define	OSC_STS_REG					(1<<22)
#define	SPLL_STS_REG				(1<<21)
#define	CLK_MUX_ERR					(1<<20)
#define	CLK_MUX_LOCK				(1<<19)
#define	ACCESS_EN					(1<<18)
#define	_32KPLL_STS_REG				(1<<17)
#define	APLL_STS_REG				(1<<16)
#define	M31_32KPLL_STS_REG			(1<<15)
#define	KEY_STS_REG					(1<<14)
#define	_32KPLL_LOCK				(1<<13)
#define	APLL_LOCK					(1<<12)
#define	M31_32KPLL_LOCK				(1<<11)
#define	PMU_LVR						(1<<10)
#define	PMU_LVD						(1<<9)
#define	SPI_CRCERR_RST				(1<<8)

//sys_pll_ctrl1
#define USB20_REFCLK_DIV 			((x&0xff)<<24)
#define	SPLL_BYPASS					(1<<23)
#define	SPLL_DACPD					(1<<22)
#define SPLL_DSMPD					(1<<21)
#define	SPLL_FOUTPOSTDIVPD			(1<<20)
#define	SPLL_FOUTVCOPD				(1<<19)
#define	SPLL_FOUT4PHASEPD			(1<<18)
#define	SPLL_POST_DIV2(x)			((x&0x7)<<15)
#define	SPLL_POST_DIV1(x)			((x&0x7)<<12)
#define	SPLL_FBDIV(x)				((x&0xfff)<<0)

//sys_pll_ctrl2	
#define	SPLL_CLK_EN					(1<<30)
#define	SPLL_REFDIV(x)				((x&0x3f)<<24)
#define	SPLL_FRAC					((x&0xffffff)<<0)

//sscg
#define	DISABLE_SSCG				(1<<11)
#define	SEL_EXITWAVE				(1<<10)
#define	DOWNSPREAD					(1<<9)
#define	SPREAD(x)					((x&0x1f)<<4)
#define	DIVVAL(x)					((x&0xf)<<0)

//audio_pll_ctrl1
#define AUDIO_MCLK_S				(1<<26)
#define	APLL_CLK_EN					(1<<24)
#define APLL_BYPASS					(1<<23)
#define	APLL_DACPD					(1<<22)
#define APLL_DSMPD					(1<<21)
#define	APLL_FOUTPOSTDIVPD			(1<<20)
#define	APLL_FOUTVCOPD				(1<<19)
#define	APLL_FOUT4PHASEPD			(1<<18)
#define	APLL_POST_DIV2(x)			((x&0x7)<<15)
#define	APLL_POST_DIV1(x)			((x&0x7)<<12)
#define	APLL_FBDIV(x)				((x&0xfff)<<0)

//audio_pll_ctrl2
#define	APLL_REFDIV(x)				((x&0x3f)<<24)
#define	APLL_FRAC(x)				((x&0xffffff)<<0)

#define	PMU_IRQ_KEYDET				(KEY_DET_MASK_EN)
#define	PMU_IRQ_POC					(POC_IRQ_EN)
#define	PMU_IRQ_APLL				(APLL_IRQ_EN)
#define	PMU_IRQ_32KPLL				(_32KPLL_IRQ_EN)
#define	PMU_IRQ_SPLL				(SPLL_IRQ_EN)
#define	PMU_IRQ_OSC					(OSC_IRQ_EN)
#define	PMU_IRQ_RCH					(RCH_IRQ_EN)
#define	PMU_IRQ_CLKMUX				(CLKMUX_ERR_IRQ_EN)
#define	PMU_IRQ_LVR					(LVR_IRQ_EN)
#define	PMU_IRQ_LVD					(LVD_IRQ_EN)
#define	PMU_IRQ_WDT					(SYS_WDT_IRQ_EN)

#define	PMU_WAKEUP_KEY				(KEY_DET_EN)
#define	PMU_WAKEUP_IO				(IO_WAKE_EN)
#define	PMU_WAKEUP_LVD				(LVD_WAKE_EN)
#define	PMU_WAKEUP_WDT				(WDT_WAKE_EN)
#define	PMU_WAKEUP_RTC				(RTC_WAKE_EN)

typedef union PMU_syspll_ctrl1_reg
{
    uint32_t d32;
    
    struct
    {
        uint32_t fbdiv : 12;
        uint32_t post_div1 : 3;
        uint32_t post_div2 : 3;
        uint32_t reserved18_19 : 2;
        uint32_t foutpostdiv_pd : 1;
        uint32_t dsm_pd : 1;
        uint32_t dac_pd : 1;
        uint32_t pll_bypass : 1;
        uint32_t usb20_refclk_div : 8;
    }
    b;
} PMU_SYSPLL_CTRL1_REG ;

typedef union PMU_syspll_ctrl2_reg
{
    uint32_t d32;
    
    struct
    {
        uint32_t frac : 24;
        uint32_t refdiv : 6;
        uint32_t spll_clken : 1;
        uint32_t reserved31 : 1;
    }
    b;
} PMU_SYSPLL_CTRL2_REG ;

typedef union PMU_sscg_ctrl_reg
{
    uint32_t d32;
    
    struct
    {
        uint32_t divval : 4;
        uint32_t spread : 5;
        uint32_t downspread : 1;
        uint32_t reserved10 : 1;
        uint32_t disable_sscg : 1;
        uint32_t reset_sscg : 1;
        uint32_t reserved13_31 : 19;
    }
    b;
} PMU_SSCG_CTRL_REG ;

typedef union PMU_sys_ctrl0_reg
{
    uint32_t d32;
    
    struct
    {
        uint32_t u11_phy_ponrst : 1;
        uint32_t u11_bck_rstn : 1;
        uint32_t u11_bck_refsel : 1;
        uint32_t u11_bck_pd : 1;
        uint32_t u11_bck_en : 1;
        uint32_t pll32k_sel : 3;
        uint32_t pll32k_clken : 1;
        uint32_t osc12m_rsel : 1;
        uint32_t osc12m_cc : 3;
        uint32_t u11_bck_div : 1;
        uint32_t tck_cs : 3;
        uint32_t usb20_syspll_div : 3;
        uint32_t usb20_refclk_sel : 2;
        uint32_t pll_refclk_sel : 1;
        uint32_t apll_en : 1;
        uint32_t pll32k_en : 1;
        uint32_t syspll_en : 1;
        uint32_t osc12m_en : 1;
        uint32_t rch_en : 1;
        uint32_t rcl_en : 1;
        uint32_t sysclk_cs : 2;
        uint32_t hsclk_en : 1;
    }
    b;
}PMU_SYS_CTRL0_REG ;

typedef union PMU_sys_ctrl1_reg
{
    uint32_t d32;
    
    struct
    {
        uint32_t rch_trim : 8;
        uint32_t rch_freq : 2;
        uint32_t rcl_trim : 7;
        uint32_t apll_irq_en : 1;
        uint32_t pll32k_irq_en : 1;
        uint32_t rch_irq_en : 1;
        uint32_t spll_irq_en : 1;
        uint32_t osc_irq_en : 1;
        uint32_t poc_irq_en : 1;
        uint32_t lvd_irq_en : 1;
        uint32_t lvr_irq_en : 1;
        uint32_t key_det_irq_en : 1;
        uint32_t key_det_en : 1;
        uint32_t lvd_wake_en : 1;
        uint32_t io_wake_en : 1;
        uint32_t wdt_wake_en : 1;
        uint32_t clkmux_restore_en : 1;
        uint32_t clkmux_err_en : 1;
    }
    b;
}PMU_SYS_CTRL1_REG ;

typedef union PMU_sys_ctrl2_reg
{
    uint32_t d32;
    
    struct
    {
        uint32_t por_dsel : 2;
        uint32_t por_rstn_sel : 1;
        uint32_t por_mask : 1;
        uint32_t lvr_mask : 1;
        uint32_t lvr_dsel : 2;
        uint32_t pmu_stop : 1;
        uint32_t dsp_ldo_vsel : 2;
        uint32_t dsp_ldo_en : 1;
        uint32_t reserved11_15 : 5;
        uint32_t buf_en : 1;
        uint32_t buf_sel : 1;
        uint32_t lvd_en : 1;
        uint32_t lvd_ls : 3;
        uint32_t lvr_en : 1;
        uint32_t lvr_ls : 2;
        uint32_t pll32k_cmp : 1;
        uint32_t sar_vref_sel : 1;
        uint32_t rtc_wake_en : 1;
        uint32_t wdt_reset_en : 1;
        uint32_t wdt_irq_en : 1;
        uint32_t pll_refclk_sel : 1;
        uint32_t sf_pwr : 1;
    }
    b;
}PMU_SYS_CTRL2_REG ;

typedef union PMU_sys_sts_reg
{
    uint32_t d32;
    
    struct
    {
        uint32_t reserved0_5 : 6;
        uint32_t u20_pll_lock : 1;
        uint32_t u11_bck_rdy : 1;
        uint32_t sf_crcerr_rst : 1;
        uint32_t lvd : 1;
        uint32_t lvr : 1;
        uint32_t u11_bck_lock : 1;
        uint32_t apll_lock : 1;
        uint32_t pll32k_lock : 1;
        uint32_t key_sts : 1;
        uint32_t u11_bck_sts : 1;
        uint32_t apll_sts : 1;
        uint32_t pll32k_sts : 1;
        uint32_t acess : 1;
        uint32_t clkmux_lock : 1;
        uint32_t clkmux_err : 1;
        uint32_t spll_sts : 1;
        uint32_t osc_sts : 1;
        uint32_t rch_sts : 1;
        uint32_t spll_lock : 1;
        uint32_t osc_clkdet : 1;
        uint32_t rch_stb_asyn : 1;
        uint32_t lvd_sts : 1;
        uint32_t lvr_sts : 1;
        uint32_t por_sts : 1;
        uint32_t poc_sts : 1;
        uint32_t xrst_sts : 1;
    }
    b;
}PMU_SYS_STS_REG ;

typedef enum PLL_mode
{
	PLL_MODE_FRAC	= 0,
	PLL_MODE_INT,
}
PLL_MODE, *PPLL_MODE;

typedef enum PLL_refclk
{
	PLL_REFCLK_OSC	= 0,
	PLL_REFCLK_BCK,
	PLL_REFCLK_PLL32K
}
PLL_REFCLK, *PPLL_REFCLK;

typedef enum SYSCLK_sel
{
	SYSCLK_SEL_RCH	= 0,
	SYSCLK_SEL_REFCLK,
	SYSCLK_SEL_SPLL,
	SYSCLK_SEL_RCL
}
SYSCLK_SEL, *PSYSCLK_SEL;

typedef struct PLL_cfg
{
    PLL_MODE        mode;
    uint8_t         sscg_en;
    uint8_t         downspread;
    uint8_t         spread;
}
PLL_CFG, *PPLL_CFG;


typedef enum {
	SYSCLK_FROM_RCH  = 0,
	SYSCLK_FROM_OSC,
	SYSCLK_FROM_32KPLL,
	SYSCLK_FROM_PLL,
	SYSCLK_FROM_RCL,
	SYSCLK_FROM_BCK,
}silan_sysclk_ref_t;


typedef enum {
	_32KPLL_4M  = 0,
	_32KPLL_2M,
	_32KPLL_1M,
	_32KPLL_500K,
	_32KPLL_8M,
	_32KPLL_12M,
	_32KPLL_16M,
	_32KPLL_32K,
	
	//SYSPLL?
}silan_sysclk_ifsubclk_t;

// usb20 
typedef enum {
  USB20_REFCLKSEL_12MOSC  = 0,
  USB20_REFCLKSEL_M32KPLL , 	
  USB20_REFCLKSEL_SYSPLL_DIV , 
}silan_usb20_ref_t;

typedef enum {
  USB20_SYSPLL_DIV2  = 0,
  USB20_SYSPLL_DIV4  	,
  USB20_SYSPLL_DIV6  	,
  USB20_SYSPLL_DIV8  	,
  USB20_SYSPLL_DIV10  ,
  USB20_SYSPLL_DIV12  ,
  USB20_SYSPLL_DIV14  ,
  USB20_SYSPLL_DIV16  ,
}silan_usb20_under_syspll_div_t;

typedef enum {
	AUDIOPLL_45M  = 0,
	AUDIOPLL_49M,
}silan_audiopllsel_t;

typedef enum {
//	SYSPLL_40M  
	SYSPLL_60M = 0,
	SYSPLL_80M ,
	SYSPLL_100M ,
	SYSPLL_120M ,
	SYSPLL_140M ,
	SYSPLL_160M ,
	SYSPLL_180M ,
	SYSPLL_200M ,
}silan_syspllsel_t;

#define SYSPLL_SSCG_ON    1
#define SYSPLL_SSCG_OFF   0

#define LDO_ON  1
#define LDO_OFF 0 
typedef enum {
	LDO_OUT_12V, //1.2V
	LDO_OUT_10V,
	LDO_OUT_08V,
	LDO_OUT_14V,
}silan_ldo_level_sel_t;

#define DEFAULT_VREF 0
typedef enum {
	LVDLS_20  = 0,
	LVDLS_21,
	LVDLS_22,
	LVDLS_23,
	LVDLS_24,
	LVDLS_25,
	LVDLS_27,
	LVDLS_29,
}silan_lvd_level_t;

typedef enum {
	LVRLS_19  = 0,
	LVRLS_21,
	LVRLS_23,
	LVRLS_25,
}silan_lvr_level_t;

typedef struct 
{
	uint32_t  sysclk;       //
	uint32_t  sysclk_ref;     // res
}sysclk_cfg_t;

extern sysclk_cfg_t sysclk_init;

typedef enum{
	TCK_CLKSEL_RCL = 0,
	TCK_CLKSEL_RCH,
	TCK_CLKSEL_OSC32K,
	TCK_CLKSEL_OSC12M,
	TCK_CLKSEL_32KPLL,
	TCK_CLKSEL_UBCK,
	TCK_CLKSEL_APLLDIV4,
	TCK_CLKSEL_SPLLDIV16,
}silan_tck_clksel_t;

// Static Inline Func
static inline void sysclk_regs_protect_open(void)
{
	sysclk_st->write_key = W_PROTECT_OPEN;
}

static inline void sysclk_regs_protect_close(void)
{
	sysclk_st->write_key = W_PROTECT_CLOSE;
}

static inline uint32_t silan_pmu_get_sts(void)
{
    return (sysclk_st->sys_sts);
}

int get_sysclk_val_settled(void);
void syspll_config(silan_syspllsel_t type);
void sysclk_init_op(void);
int pre_sysclk_sel(silan_sysclk_ref_t sysclk_ref,silan_syspllsel_t if_clk_sel);

void silan_spiflash_power_enable(void);
void silan_pmu_wakeup_enable(uint32_t id);
void silan_pmu_wakeup_disable(uint32_t id);
void silan_sar_adc_vref_select(int inner);

void silan_dsp_ldo_disable(void);
void silan_dsp_ldo_config(int level);
void silan_pmu_wdt_init(uint32_t wdt_cnt);
void silan_pmu_wdt_reset_config(uint32_t wdt_cnt);
void silan_pmu_wdt_reset_disable(void);
void silan_pmu_wdt_clr(void);
void silan_pwr_iso_disable(void);
void silan_pwr_iso_enable(void);
void silan_osc_disable(void);

void silan_pmu_wakeup_disable(uint32_t id);
void silan_sar_adc_vref_select(int inner);

void silan_soc_stop(void);
void silan_sdram_pwd_deal(void);
void silan_sdram_pwd_quit(void);
void silan_usb_pwd_deal(void);
void silan_usb_pwd_quit(void);

void silan_audiopll_init(void);
void silan_syspll_init(uint32_t sscg);
void silan_sysclk_change(silan_sysclk_ref_t sysclk_ref,silan_syspllsel_t if_clk_sel);
void audiopll_config(silan_audiopllsel_t type);
void silan_module_clkon(int mod, silan_clk_onff_t onoff);

void silan_pmu_wakeup_disable(uint32_t id);
void silan_sar_adc_vref_select(int inner);

void silan_ubck_enable(void);
uint32_t silan_get_audiopll_clk(void);

void silan_tck_config(silan_tck_clksel_t clk_sel);

void silan_pmu_get_dsp_ldo(uint8_t *level, uint8_t *en);
int32_t silan_pmu_syspll_config(PLL_CFG *cfg);
int32_t silan_pmu_syspll_freq(uint32_t freq);
int32_t silan_pmu_pll_refclk(PLL_REFCLK refclk);
int32_t silan_pmu_sysclk_switch(SYSCLK_SEL sel);
uint32_t silan_pmu_get_sysclk(void);
uint32_t silan_pmu_get_pllclk(void);
void silan_pmu_syspll_pdn(void);

#endif
