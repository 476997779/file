/*
 * silan_gpio.h
 *
 * Modify Date:
 */
#ifndef __SILAN_GPIO_H__
#define __SILAN_GPIO_H__

#include "silan_types.h"
#include "ap1508.h"

#define SILAN_GPIO1_BASE          SPER_APB1_GPIO1_BASE
#define SILAN_GPIO2_BASE          SPER_APB1_GPIO2_BASE

#define SILAN_GPIO_BASE(n)        (SPER_APB1_GPIO1_BASE + n*0x10000)
 
 // GPIO1(0) ~ GPIO1(22)
 // GPIO2(0) ~ GPIO2(28)
//#define GPIO1(n)            n    n*
//#define GPIO2(n)            (SL_GPIO_NR + n)
#define GPIO_PIN(n)         (1 << n)
 
#define GPIO_High_Level     1
#define GPIO_High_Edge      2
#define GPIO_Low_Level      3
#define GPIO_Low_Edge       4
#define GPIO_Edge           5


#define GPIO_DATA           0X000
#define GPIO_DIR            0X400
#define GPIO_IS             0X404
#define GPIO_IBE            0X408
#define GPIO_IEV            0x40c
#define GPIO_IE             0X410
#define GPIO_RIS            0x414
#define GPIO_MIS            0x418
#define GPIO_IC             0X41C
#define GPIO_AFSEL          0X420
#define GPIO_FILSEL         0X424
#define GPIO_FILDIV         0X428

#define GPIO_FIL_DIV(x)		log2(x)

#define GPIO1			 0
#define GPIO2            1

#define GPIO1_MAX_NUM    22
#define GPIO2_MAX_NUM    10

#define IO_MAX_NUM       41

#define IO_INPUT		 0
#define IO_OUTPUT 		 1

#define GPIO_CONFIG_OFFSET(x)    (x / (GPIO1_MAX_NUM+1))
#define GPIO_CONFIG_PIN(x)       (x % (GPIO1_MAX_NUM+1))
#define IO_TO_GPIO(x)            ((x>=8) ? (x-8) : (34+x))

static inline void silan_gpio_input(uint32_t addr, uint32_t pin)
{
	__sREG32(addr, GPIO_DIR) &= ~pin;
}

static inline void silan_gpio_output(uint32_t addr, uint32_t pin)
{
	__sREG32(addr, GPIO_DIR) |= pin;
}

static inline void silan_gpio_set_high(uint32_t addr, uint32_t pin)
{
	__sREG32(addr, GPIO_DATA) |= pin;
}

static inline void silan_gpio_set_low(uint32_t addr, uint32_t pin)
{
	__sREG32(addr, GPIO_DATA) &= ~pin;
}

static inline int silan_gpio_get(uint32_t addr, uint32_t pin)
{
	if (__sREG32(addr, GPIO_DATA) & pin)
	{
        return 1;
    }
    return 0;
}

static inline void silan_gpio_irq_enable(uint32_t addr, uint32_t pin)
{
	__sREG32(addr, GPIO_IE) |= pin;
}

static inline void silan_gpio_irq_disable(uint32_t addr, uint32_t pin)
{
	__sREG32(addr, GPIO_IE) &= ~pin;
}

static inline void silan_gpio_irq_clear(uint32_t addr, uint32_t pin)
{
	__sREG32(addr, GPIO_IC) |= pin;
}

static inline void silan_gpio_irq_mode(uint32_t addr, uint32_t pin, int mode)
{
    uint32_t base = addr;

    if ((mode == GPIO_High_Level) || (mode == GPIO_Low_Level))
    {
        __sREG32(base,GPIO_IS) |= pin;
    }
    else
    {
        __sREG32(base,GPIO_IS) &= ~pin;
        if (mode == GPIO_Edge)
        {
            __sREG32(base,GPIO_IBE) |= pin;
        }
    }
    if ((mode == GPIO_High_Level) || (mode == GPIO_High_Edge))
    {
        __sREG32(base,GPIO_IEV) |= pin;
    }
    else
    {
        __sREG32(base,GPIO_IEV) &= ~pin;
    }
}

static inline void silan_gpio_filsel_open(uint32_t addr,uint32_t pin)
{
	__sREG32(addr, GPIO_FILSEL) |= pin;
}

static inline void silan_gpio_filsel_close(uint32_t addr,uint32_t pin)
{
	__sREG32(addr, GPIO_FILSEL) &= ~pin;
}

static inline void silan_gpio_filsel_div(uint32_t addr,int div)
{
	__sREG32(addr, GPIO_FILDIV) |= ((div&0xf)<<1)|0x1;
}

void silan_io_input(int io);
void silan_io_output(int io);
void silan_io_direction(int io, int dir);
void silan_io_set_high(int io);
void silan_io_set_low(int io);
void silan_io_set_value(int io, int val);
int silan_io_get(int io);
void silan_io_toggle(int io);
void silan_io_irq_enable(int io);
void silan_io_irq_clear(int io);
void silan_io_irq_mode(int io, int mode);

void silan_io_filter_config(int io, int div);
void silan_io_filter_open(int io);

#endif // __SILAN_GPIO_H__
