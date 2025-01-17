/*
***************************************************************************************************
* 名称: main.c
* 描述: 
* 作者: yrf
* 时间: 
***************************************************************************************************
*/
#include "silan_pmu.h"
#include "silan_printf.h"
#include "silan_iomux.h"
#include "silan_m0_cache.h"
#include "silan_bootspi.h"
#include "silan_rtc.h"
#include "silan_pic.h"
#include "silan_sdram.h"
#include "silan_uart.h"
#include "silan_timer.h"
#include "silan_calib.h"
#include "silan_adc.h"
#include "silan_gpio.h"

#include "string.h"


/* 宏定义 ****************************************************************************************/
#ifdef SC5864D
#define PROJECT_NAME		"sdk_audio sc5864d"
#else
#define PROJECT_NAME		"sdk_audio"
#endif
#define CONSOLE_UART    SILAN_UART2
#define PIN_LED1       	IO_CONFIG_PA6					
#define PIN_LED2       	IO_CONFIG_PA3
#define PIN_KEY1				IO_CONFIG_PA2
#define PIN_KEY2				IO_CONFIG_PA1

/* 变量 ******************************************************************************************/
uint8_t sdram_cap;
volatile uint8_t int5ms_f;
volatile uint8_t int10ms_f;
volatile uint8_t int100ms_f;
volatile uint8_t int1s_f;
volatile uint32_t cnt10ms;
volatile uint32_t cnt100ms;
volatile uint32_t cnt1s;

/* 函数 ******************************************************************************************/

/*
*************************************************************
函数 : print_version
功能 : 打印工程信息
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void print_version(void)
{
	sl_printf("\r\n\r\n");
	sl_printf("+=================================+\r\n");
	sl_printf("|       " PROJECT_NAME "           |\r\n");
	sl_printf("| Build: "__DATE__" "__TIME__"     |\r\n");
	sl_printf("+=================================+\r\n");
}

/*
*************************************************************
函数 : console_init
功能 : 调试串口初始化
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void console_init(void)
{
	silan_io_func_config(IO_CONFIG_PA4, PA4_FUNC_UART2);
	silan_io_func_config(IO_CONFIG_PA5, PA5_FUNC_UART2);
	silan_uart_sys_init(CONSOLE_UART, BAUDRATE_115200);
}

/*
*************************************************************
函数 : reset_init
功能 : 初始化
输入 : 
输出 : 
注意 : 
*************************************************************
*/
int32_t reset_init(void)
{	
#if defined (SC5864D)
	spi_quad_status_done();
	cache_spi_cmd_sel(SF_CMD_FRQ, 0);
#else
	cache_spi_cmd_sel(SF_CMD_FRD, 1);
#endif
	silan_m0_cache_disable();
	silan_m0_cache_clear();
	silan_m0_cache_init(CACHE_AREA_1, 0);
	silan_m0_cache_lock(0x0, 16);
	silan_m0_cache_enable();
	silan_mcu_cclksel(MCU_CCLK_DIV2);
	silan_dsp_cclk_onoff(CLK_OFF);
	silan_risc_cclk_onoff(CLK_OFF);
	silan_calib();
	silan_mcu_debug_close();
	silan_risc_debug_close();
	silan_dsp_debug_close();
}

/*
*************************************************************
函数 : system_init
功能 : 初始化
输入 : 
输出 : 
注意 : 
*************************************************************
*/
int32_t system_init(void)
{
	PLL_CFG syspll_cfg;
    
	silan_dsp_ldo_config(LDO_OUT_12V);
	
	silan_vlsp_cclk_config(CLK_ON);
	silan_soc_ldo_config(LDO_OUT_12V);
	
	memset((void *)&syspll_cfg, 0, sizeof(PLL_CFG));
	syspll_cfg.mode = PLL_MODE_FRAC;
	syspll_cfg.sscg_en = 0;
	syspll_cfg.spread = 0;
    
	silan_pmu_sysclk_switch(SYSCLK_SEL_REFCLK);
	silan_pmu_syspll_config(&syspll_cfg);
	silan_pmu_pll_refclk(PLL_REFCLK_OSC);

	silan_pmu_syspll_freq(160 * 1000000);
	silan_pmu_sysclk_switch(SYSCLK_SEL_SPLL);
	
	silan_uart_sys_init(SILAN_UART2, BAUDRATE_115200);

	silan_dsp_dcache_cfg(DCACHE_MODE_DC);
#ifdef SC5864D
#else
	sdram_cap = silan_sdram_init();
#endif

	silan_timer_cclk_config(TIMER_CCLK_CLKSYS_DIV2, CLK_ON);
	silan_delay_calib();
	silan_audiopll_init();
}

/*
*************************************************************
函数 : period_task_handler
功能 : timer中断函数
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void period_task_handler()
{
	int5ms_f = 1;
	if (++cnt10ms > 1) {
		cnt10ms = 0;
		int10ms_f = 1;
		if (++cnt100ms > 9) {
			cnt100ms = 0;
			int100ms_f = 1;
			if (++cnt1s > 9) {
				cnt1s = 0;
				int1s_f = 1;			
			}
		}
	}
}

/*
*************************************************************
函数 : timer_init
功能 : timer初始化
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void timer_init(void)
{
	int5ms_f = 0;
	int10ms_f = 0;
	int100ms_f = 0;
	int1s_f = 0;
	cnt10ms = 0;
	cnt100ms = 0;
	cnt1s = 0;	
	
	silan_delay_calib();
	
	silan_timer_task_init(TIMER_3, 5);
	silan_timer_task_request(period_task_handler);
}

/*
*************************************************************
函数 : gpio_init
功能 : gpio初始化
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void gpio_init(void)
{
	silan_io_driver_config(PIN_LED1, IO_ATTR_DS_4mA);
	silan_io_func_config(PIN_LED1, IO_FUNC_GPIO);
	silan_io_output(PIN_LED1);
	silan_io_set_low(PIN_LED1);

	silan_io_driver_config(PIN_LED2, IO_ATTR_DS_8mA);
	silan_io_func_config(PIN_LED2, IO_FUNC_GPIO);
	silan_io_output(PIN_LED2);
	silan_io_set_low(PIN_LED2);	
	
	silan_io_func_config(PIN_KEY1, IO_FUNC_GPIO);
	silan_io_input(PIN_KEY1);

	silan_io_func_config(PIN_KEY2, IO_FUNC_GPIO);
	silan_io_input(PIN_KEY2);
	
	silan_io_func_config(IO_CONFIG_PC3, PC3_FUNC_I3_I2S);
	silan_io_func_config(IO_CONFIG_PC4, PC4_FUNC_I3_I2S);
	silan_io_func_config(IO_CONFIG_PC5, PC5_FUNC_I3_I2S);
	silan_io_func_config(IO_CONFIG_PC6, PC6_FUNC_I3_I2S);
	
	silan_io_func_config(IO_CONFIG_PD1, PD1_FUNC_O3_I2S_20);
	silan_io_func_config(IO_CONFIG_PD2, PD2_FUNC_O3_I2S_20);
	silan_io_func_config(IO_CONFIG_PD3, PD3_FUNC_O3_I2S_20);
	silan_io_func_config(IO_CONFIG_PD4, PD4_FUNC_O3_I2S_20);
}

/*
*************************************************************
函数 : dev_init
功能 : 
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void dev_init(void)
{
	timer_init();
    
	gpio_init();
}

/*
*************************************************************
函数 : main
功能 : 
输入 : 
输出 : 
注意 : 
*************************************************************
*/
int main()
{
	console_init();
	print_version();
	
	reset_init();
	system_init();
    
	silan_pic_init();
    
	dev_init();

	usb_audio_init();
	audio_dev_init();
	while (1) {
		usb_audio_proc();
		audio_ext_codec_proc();
// 5ms-------------------------------------		
		if (int5ms_f) {
			int5ms_f = 0;
			if (silan_io_get(PIN_KEY1) == 0) {
				silan_io_set_high(PIN_LED2);
			}
			if (silan_io_get(PIN_KEY2) == 0) {
				silan_io_set_low(PIN_LED2);
			}
		}
// 10ms------------------------------------	
		if (int10ms_f) {
			int10ms_f = 0;

		}
// 100ms-----------------------------------			
		if (int100ms_f) {
			int100ms_f = 0;
		}
// 1s--------------------------------------			
		if(int1s_f) {
			int1s_f = 0;
			silan_io_toggle(PIN_LED1);
		}
	}
}
/*
***************************************************************************************************
                                            END
***************************************************************************************************
*/