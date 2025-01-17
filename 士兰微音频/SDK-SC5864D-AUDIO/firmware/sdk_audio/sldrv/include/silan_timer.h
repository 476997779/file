#ifndef __SILAN_TIMER_H__
#define __SILAN_TIMER_H__

#include "silan_types.h"
#include "ap1508.h"

#include "silan_syscfg.h"

#define TIMER_BASE_ADDR				        SPER_APB2_TIMER_BASE   //0x41860000

#define TIMER0_COUNT        				__REG32(TIMER_BASE_ADDR + 0x00)
#define TIMER0_COMPARE      				__REG32(TIMER_BASE_ADDR + 0x04)
#define TIMER0_CTRL         				__REG32(TIMER_BASE_ADDR + 0x08)
#define TIMER0_SEL							__REG32(TIMER_BASE_ADDR + 0x0C)
#define TIMER1_COUNT        				__REG32(TIMER_BASE_ADDR + 0x10)
#define TIMER1_COMPARE      				__REG32(TIMER_BASE_ADDR + 0x14)
#define TIMER1_CTRL         				__REG32(TIMER_BASE_ADDR + 0x18)
#define TIMER1_SEL							__REG32(TIMER_BASE_ADDR + 0x1C)
#define TIMER2_COUNT        				__REG32(TIMER_BASE_ADDR + 0x20)
#define TIMER2_COMPARE      				__REG32(TIMER_BASE_ADDR + 0x24)
#define TIMER2_CTRL         				__REG32(TIMER_BASE_ADDR + 0x28)
#define TIMER2_SEL							__REG32(TIMER_BASE_ADDR + 0x2C)
#define TIMER3_COUNT        				__REG32(TIMER_BASE_ADDR + 0x30)
#define TIMER3_COMPARE      				__REG32(TIMER_BASE_ADDR + 0x34)
#define TIMER3_CTRL         				__REG32(TIMER_BASE_ADDR + 0x38)
#define TIMER3_SEL							__REG32(TIMER_BASE_ADDR + 0x3C)
#define TIMER4_COUNT        				__REG32(TIMER_BASE_ADDR + 0x40)
#define TIMER4_COMPARE      				__REG32(TIMER_BASE_ADDR + 0x44)
#define TIMER4_CTRL         				__REG32(TIMER_BASE_ADDR + 0x48)
#define TIMER4_SEL							__REG32(TIMER_BASE_ADDR + 0x4C)

#define TIMER_MS_COUNT						__REG32(TIMER_BASE_ADDR + 0x50)
#define TIMER_MS_COMPARE 					__REG32(TIMER_BASE_ADDR + 0x54)
#define TIMER_MS_CTRL						__REG32(TIMER_BASE_ADDR + 0x58)
#define TIMER_1MS_COMPARE					__REG32(TIMER_BASE_ADDR + 0x5C)
#define TIMER_S_COUNT						__REG32(TIMER_BASE_ADDR + 0x60)
#define TIMER_S_COMPARE 					__REG32(TIMER_BASE_ADDR + 0x64)
#define TIMER_S_CTRL						__REG32(TIMER_BASE_ADDR + 0x68)

#define TIMER0_BASE                         0x41860000
#define TIMER1_BASE                         0x41860010
#define TIMER2_BASE                         0x41860020
#define TIMER3_BASE                         0x41860030
#define TIMER4_BASE                         0x41860040
#define TIMER_MS_BASE                       0x41860050
#define TIMER_S_BASE                        0x41860060

#define TIMER_COUNT                         0x00
#define TIMER_COMPARE                       0x04
#define TIMER_CTRL                          0x08
#define TIMER_SEL                           0x0c

#define TIMER_EN    					    (1<<0)
#define TIMER_TO    					    (1<<1)
#define TIMER_INT  							(1<<2)

#define TIMER_ADDR(x)						(TIMER_BASE_ADDR+x*0x10)


#define TIMER_TASK_NUM	                    8

#define TIMER_1MS_CNT	                    silan_get_timer_cclk()/1000

#define DELAY_CALIB_PRECISION	10			// us
#define DELAY_CALIB_TEST_TIME	10*1000		// 10ms
#define DELAY_CALIB_DEFAULT		100

typedef enum {
	TIMER_0           = 0,
	TIMER_1,
	TIMER_2,
	TIMER_3,
	TIMER_4,
	TIMER_MS,
	TIMER_S,
}silan_timer_t;

/*************************************************************************/
static void inline silan_timer_stop(uint32_t addr)
{
    __sREG32(addr, TIMER_CTRL) = ~(TIMER_TO|TIMER_EN);
}

static void inline silan_timer_1ms_set(void)
{
	TIMER_1MS_COMPARE = silan_get_timer_cclk() / 1000;
}

static void inline silan_timer_irq_reset(uint32_t addr)
{
   __sREG32(addr, TIMER_CTRL) = TIMER_EN|TIMER_INT;
}

static void inline silan_timer_irq_clear(uint32_t addr)
{
   __sREG32(addr, TIMER_CTRL) = ~TIMER_INT;
}

static void inline silan_timer_count(uint32_t addr, uint32_t count)
{
    __sREG32(addr, TIMER_COUNT) = count;
}

static void inline silan_timer_compare(uint32_t addr, uint32_t compare)
{
    __sREG32(addr, TIMER_COMPARE) = compare;
}

static void inline silan_timer_sel(uint32_t addr, uint32_t sel)
{
    __sREG32(addr, TIMER_SEL) = sel;
}

static void inline silan_timer_enable(uint32_t addr)
{
    __sREG32(addr, TIMER_CTRL) = TIMER_EN;
}

static void inline silan_timer_disable(uint32_t addr)
{
	__sREG32(addr, TIMER_CTRL) &= ~TIMER_EN;
}

static void inline silan_timer_to_clear(uint32_t addr)
{
    __sREG32(addr, TIMER_CTRL) &= ~TIMER_TO;
}

static uint32_t inline silan_timer_to_state(uint32_t addr)
{
	if(__sREG32(addr, TIMER_CTRL)& TIMER_TO)
        return 1;
    else
        return 0;
}

static void inline silan_timer_irq_enable(uint32_t addr)
{
   __sREG32(addr, TIMER_CTRL) = TIMER_EN|TIMER_INT;
}

static void inline silan_timer_irq_disable(uint32_t addr)
{
   __sREG32(addr, TIMER_CTRL) = ~(TIMER_EN|TIMER_INT);
}

static uint32_t inline silan_get_timer_count(uint32_t addr)
{
	return __sREG32(addr, TIMER_COUNT);
}

static void inline silan_timer_start(uint32_t addr)
{
    silan_timer_count(addr, 0x0);
    silan_timer_compare(addr, 0xffffffff);
    silan_timer_enable(addr);
}

static void inline silan_timer_irq_start(uint32_t addr, uint32_t time)
{
    silan_timer_count(addr, 0x0);
    silan_timer_compare(addr, time);
    silan_timer_irq_enable(addr);
}

/*************************************************************************/
void silan_udelay(uint32_t us);
void silan_mdelay(uint32_t ms);
void silan_delay_calib(void);
int32_t silan_timer_task_init(silan_timer_t timer, uint32_t period);
int32_t silan_timer_task_request(tsk_t task);

#endif

