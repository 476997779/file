/*
 * silan_irq.h
 * 
 * Modified Date: 2016-03-22
 */

#ifndef __SILAN_PIC_H__
#define __SILAN_PIC_H__

#include "silan_types.h"
#include "ap1508.h"
#include "silan_config.h"

#if defined(__CC_ARM)
#include "silan_core_m0.h"
#endif

#define INTR_STS_RAW(id)        __REG32(SCFG_APB_INTR_ADDR_BASE+0x000+id*4)
#define INTR_STS_MSK_RISC(id)   __REG32(SCFG_APB_INTR_ADDR_BASE+0x100+id*4)
#define INTR_CTR_MSK_RISC(id)   __REG32(SCFG_APB_INTR_ADDR_BASE+0x200+id*4)
#define INTR_STS_MSK_DSP(id)    __REG32(SCFG_APB_INTR_ADDR_BASE+0x300+id*4)
#define INTR_CTR_MSK_DSP(id)    __REG32(SCFG_APB_INTR_ADDR_BASE+0x400+id*4)
#define INTR_STS_MSK_M0(id)     __REG32(SCFG_APB_INTR_ADDR_BASE+0x500+id*4)
#define INTR_CTR_MSK_M0(id)     __REG32(SCFG_APB_INTR_ADDR_BASE+0x600+id*4)

#if defined(__CC_ARM)
#define INTR_STS_MSK(id)        INTR_STS_MSK_M0(id)
#define INTR_CTR_MSK(id)        INTR_CTR_MSK_M0(id)
#endif

#if defined(__CSKY__)
#define INTR_STS_MSK(id)        INTR_STS_MSK_RISC(id)
#define INTR_CTR_MSK(id)        INTR_CTR_MSK_RISC(id)
#endif

#if defined(__XCC__)
#define INTR_STS_MSK(id)        INTR_STS_MSK_DSP(id)
#define INTR_CTR_MSK(id)        INTR_CTR_MSK_DSP(id)
#endif
// typedef void (*hdl_t)(uint32_t subid);

typedef struct IRQ_Handler
{
	uint32_t	irqid;
	uint32_t	priority;
	void		(*handler)(uint32_t irqid);
}IRQ_HANDLER, *PIRQ_HANDLER;

typedef enum {
	PIC_IRQID_NONE             = -1,
	PIC_IRQID_NONE1            =  0,
	PIC_IRQID_NONE2            =  1,
	PIC_IRQID_SAR              =  2,
	PIC_IRQID_SPIFLASH         =  3,
	PIC_IRQID_MISC             =  4,
	PIC_IRQID_PDM              =  5, 
	PIC_IRQID_GPIO1            =  6,
	PIC_IRQID_GPIO2            =  7,
	PIC_IRQID_TIMER            =  8,
	PIC_IRQID_SDMAC            =  9,
	PIC_IRQID_SDMMC            = 10,
	PIC_IRQID_IIR              = 11,
	PIC_IRQID_SDIO             = 12,
	PIC_IRQID_USBFS            = 13,
	PIC_IRQID_USBHS            = 14,
	PIC_IRQID_CXC              = 15,
	PIC_IRQID_ADMAC            = 16,
	PIC_IRQID_SPDIF            = 17,
	PIC_IRQID_PCM              = 18,
	PIC_IRQID_I2S              = 19,
	PIC_IRQID_RTC              = 20,
	PIC_IRQID_PMU              = 21,
	PIC_IRQID_DMAC             = 22,
	PIC_IRQID_DSP_SDMAC,  /* Only DSP */
	PIC_IRQID_DSP_ADMAC,  /* Only DSP */
	PIC_IRQID_DSP_GPIO,   /* Only DSP */
	PIC_IRQID_WDOG             = 30,
	PIC_IRQID_CTIMER,
	PIC_IRQID_LMT,
}pic_irq_t;

#define PIC_SUBID_SOLO                (-1)
#define PIC_SUBID_LMT                 (32)
#define PIC_SUBID_MISC_UART1          (0)
#define PIC_SUBID_MISC_UART2          (1)
#define PIC_SUBID_MISC_UART3          (2)
#define PIC_SUBID_MISC_UART4          (3)
#define PIC_SUBID_MISC_SPI1           (4)
#define PIC_SUBID_MISC_SPI2           (5)
#define PIC_SUBID_MISC_I2C1           (6)
#define PIC_SUBID_MISC_I2C2           (7)
#define PIC_SUBID_MISC_PDB            (9)
#define PIC_SUBID_DMAC_CH0            (0)
#define PIC_SUBID_DMAC_CH1            (1)
#define PIC_SUBID_DMAC_CH2            (2)
#define PIC_SUBID_DMAC_CH3            (3)
#define PIC_SUBID_DMAC_CH4            (4)
#define PIC_SUBID_DMAC_CH5            (5)
#define PIC_SUBID_DMAC_CH6            (6)
#define PIC_SUBID_DMAC_CH7            (7)
#define PIC_SUBID_SPDIF_IN            (0)
#define PIC_SUBID_SPDIF_OUT           (1)
#define PIC_SUBID_I2S_O1              (0)
#define PIC_SUBID_I2S_O2              (1)
#define PIC_SUBID_I2S_O3              (2)
#define PIC_SUBID_I2S_I1              (8)
#define PIC_SUBID_I2S_I2              (9)
#define PIC_SUBID_I2S_I3              (10)
#define PIC_SUBID_TIMER_0             (0)
#define PIC_SUBID_TIMER_1             (1)
#define PIC_SUBID_TIMER_2             (2)
#define PIC_SUBID_TIMER_3             (3)
#define PIC_SUBID_TIMER_4             (4)
#define PIC_SUBID_TIMER_MSO           (5)     /* millisecond */
#define PIC_SUBID_TIMER_SO            (6)     /* second      */

#define SPDIF_HDL_NUM      2
#define DMAC_HDL_NUM       8
#define GPIO_HDL_NUM       32
#define TIMER_HDL_NUM      7
#define MISC_HDL_NUM       10
#define PMU_HDL_NUM        11

int  silan_pic_request(pic_irq_t id, int subid, hdl_t hdl);
void silan_pic_free(pic_irq_t id, int subid);
void silan_pic_init(void);
int32_t silan_pic_disable(pic_irq_t id, int32_t subid);
int32_t silan_pic_enable(pic_irq_t id, int32_t subid);

void silan_irq_free(int id);

void pic_port_init(void);
int  pic_port_request(int id, hdl_t hdl);
void pic_port_free(int id);

#if defined(__CC_ARM) || defined(__CSKY__)
uint32_t pic_get_enable(void);
void pic_set_enable(uint32_t restored);
void pic_clr_enable(uint32_t restored);
#endif

void pic_do_hdl(uint32_t stat, hdl_t *hdl);

#endif
