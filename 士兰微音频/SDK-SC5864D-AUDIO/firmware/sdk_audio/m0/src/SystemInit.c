#include "silan_pmu.h"
#include "silan_m0_cache.h"

// called by startup_CMSDK_CM0.s
// Early initialize
void SystemInit(void)
{
	sysclk_st->write_key = W_PROTECT_OPEN;
	sysclk_st->sys_ctr2 &= ~SYS_WDT_RST_EN;
    // DSP LDO->0.8V
    sysclk_st->sys_ctr2 |= (1 << 9);
	sysclk_st->sys_ctr2 |= LDO_DSP_EN;
    // DSP LDO->1.2V
    sysclk_st->sys_ctr2 &= ~(1 << 9);
    sysclk_st->sys_ctr2 |= POR_MASK;
	sysclk_st->iso_en = 0;
    sysclk_st->sys_ctr1 &= ~CLKMUX_RESETORE_EN;
	sysclk_st->write_key = W_PROTECT_CLOSE;
	
	// reset 32k sram controller
	__REG32(SILAN_SYSCFG_REG8) &= ~(1 << 1);
	__REG32(SILAN_SYSCFG_REG8) |=  (1 << 1);
    
    // Reset almost all module except:
    // SFlash/32KSRAM_CTRL/SHADOW_CTRL/OTP/SCFG(BUS+SYSCTRL+CXC+INTR+REQ)
    __REG32(SILAN_SYSCFG_REG8) &= ~(0xFFFFFDE0);
    __REG32(SILAN_SYSCFG_REG8) |=  (0xFFFFFDE0);
    // PMU
    __REG32(SILAN_SYSCFG_REG9) &= ~(0xFFFEFFFF);
    __REG32(SILAN_SYSCFG_REG9) |=  (0xFFFEFFFF);
    
    // cache clear
    spicache_st->cache_ctrl = CACHE_AUTOCLEAR;
	while (!(spicache_st->cache_ctrl & CACHE_AUTOCLEAR_END));
	spicache_st->cache_ctrl = CACHE_AUTOCLEAR_END;
    // cache area
    spicache_st->main_ctrl &= ~(CACHE_AREA_1|CACHE_AREA_2|CACHE_AREA_3|CACHE_AREA_4);	
	spicache_st->main_ctrl |= CACHE_AREA_1;
    // cache enable
    spicache_st->main_ctrl |= CACHE_ENABLE;
	
	// otp may not switch sysclk to osc12m, because of no clear pmu status
	silan_pmu_sysclk_switch(SYSCLK_SEL_REFCLK);
}
