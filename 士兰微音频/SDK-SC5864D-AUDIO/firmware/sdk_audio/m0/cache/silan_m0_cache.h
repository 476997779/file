#ifndef _SILAN_CACHE_H_
#define _SILAN_CACHE_H_

#include "silan_types.h"

typedef volatile struct spicache_struct
{
	uint32_t  main_ctrl;           // offset 0x000
	uint32_t  cache_ctrl;          // offset 0x004
	uint32_t  opaddr;              // offset 0x008
	uint32_t  opsize;              // offset 0x00C
	uint32_t  reserve1[8];        // offset 0x010
	uint32_t  intr;                // offset 0x030
	uint32_t  reserve2;          // offset 0x034
	uint32_t  softreset;           // offset 0x038
	uint32_t  reserve0[85];        // offset 0x040 ~ 0x0fc reserved
	uint32_t  cache_hit_num_l;             // offset 0x190
	uint32_t  cache_hit_num_h;             // offset 0x194
	uint32_t  cache_miss_num_l;         // offset 0x198
	uint32_t  cache_miss_num_h;         // offset 0x19c
}spicache_struct_t;

#define spicache_st  ((spicache_struct_t *)0xa0000000)

//main_ctrl
#define CACHE_AREA_1    ((uint32_t)1<<24)
#define CACHE_AREA_2    ((uint32_t)1<<25)
#define CACHE_AREA_3    ((uint32_t)1<<26)
#define CACHE_AREA_4    ((uint32_t)1<<27)

#define CACHE_RAM_EN    ((uint32_t)1<<8)
#define CACHE_ENABLE    1

// cache_ctrl
#define CACHE_UNVALID             			(1 << 20)

#define CACHE_UNLOCK_END             		(1 << 18)
#define CACHE_UNLOCKING              		(1 << 17)
#define CACHE_UNLOCK                 		(1 << 16)
#define CACHE_AUTOCLEAR_END             (1 << 10)
#define CACHE_AUTOCLEARING              (1 << 9)
#define CACHE_AUTOCLEAR                 (1 << 8)

//#define CACHE_RUNLOCK             			(1 << 5)

#define CACHE_AUTOFILL_LOCK             (1 << 4)
#define CACHE_AUTOFILL_END              (1 << 2)
#define CACHE_AUTOFILLING               (1 << 1)
#define CACHE_AUTOFILL                  (1 << 0)

#define CACHE_STATISTICS_ENABLE         ((uint32_t)1 << 30)

// cache intr
#define CACHE_STATISTICS_ERR_INTR_EN    (1 << 21)
#define CACHE_STATE_ERR_INTR_EN         (1 << 17)
#define CACHE_STATISTICS_ERR_INTR       (1 << 5)
#define CACHE_STATE_ERR_INTR            (1 << 1)

#define CACHE_SOFTRESET_KEY      0xa05f9696

#define M0_CACHE_LINE_SIZE    16

#define CACHE_ENABLE 		  1
#define CACHE_DISABLE 		  0

#define CACHE_LOCK			  1
#define CACHE_ULOCK		      0

#define CACHE_LOCK_ADDR       0x1FDC00
#define CACHE_LOCK_LEN        0xFF
/*
m0_cache_init()
operation :1 cahce en  ;0 cache dis
if_lock :1 cahce lock  ;0 cache unlock
...
*/
void m0_cache_init(uint8_t operation,uint8_t if_lock, uint32_t lock_addr, uint32_t len);
void silan_m0_cache_init(uint32_t cache_area, uint8_t statistics);
void silan_m0_cache_lock(uint32_t lock_addr, uint32_t len);
void silan_m0_cache_unlock(uint32_t lock_addr, uint32_t len, uint8_t unvalid);
void silan_m0_cache_enable(void);
void silan_m0_cache_disable(void);
void silan_m0_cache_clear(void);

#endif

