/*
 * The Clear BSD License
 * Copyright (c) 2018, Hangzhou Silan Microelectronics CO.,LTD.
 * Copyright 2018-2020 SILAN
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _SILAN_SPDIF_O_H_
#define _SILAN_SPDIF_O_H_

#include "silan_types.h"
#include "ap1508.h"


#define SPDIF_O_ID              8

#define SPDIF_O_BASE_ADDR		APER_APB_SPDIF_O_BASE

#define SPDIF_O_FIFO_DEPTH      32

typedef struct SPDIF_o_core_regs
{
	__IO uint32_t		SPD_USR1;
    __IO uint32_t       SPD_USR2;
    __IO uint32_t       SPD_USR3;
    __IO uint32_t       SPD_Q2W;
    __IO uint32_t       SPD_USR_CNT;
    __IO uint32_t		SPD_CSD1;
    __IO uint32_t		SPD_CSD2;
    __IO uint32_t		SPD_CSD3;
    __IO uint32_t		SPD_CSD4;
    __IO uint32_t		SPD_CSD5;
    __IO uint32_t		SPD_CSD6;
    __IO uint32_t		SPD_FF_CTL;
    __IO uint32_t		SPD_FF_WDAT;
    __IO uint32_t		SPD_STS;
    __IO uint32_t		SPD_IRQEN;
    __IO uint32_t		SPD_CTL;

}
SPDIF_O_CORE_REGS, *PSPDIF_O_CORE_REGS;

typedef union SPD_q2w_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t q2w : 3;
        uint32_t reserved3_31 : 29;
    }
    b;
} SPD_Q2W_REGS ;

typedef union SPD_usr_cnt_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t row_cnt : 4;
        uint32_t col_cnt : 7;
        uint32_t reserved11_31 : 21;
    }
    b;
} SPD_USR_CNT_REGS ;

typedef union SPD_ff_ctl_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t almost_full_num : 8;
        uint32_t almost_empty_num : 8;
        uint32_t reserved16_30 : 15;
        uint32_t fifo_flush : 1;
    }
    b;
} SPD_FF_CTL_REGS ;

typedef union SPD_sts_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t sub_block_end_int : 1;
        uint32_t block_end_int : 1;
        uint32_t reserved2_3 : 2;
        uint32_t aempty_int : 1;
        uint32_t afull_int : 1;
        uint32_t empty_int : 1;
        uint32_t full_int : 1;
        uint32_t unvalid_int : 1;
        uint32_t shit : 1;
        uint32_t reserved10_11 : 2;
        uint32_t ld_vld_usr : 1;
        uint32_t ld_vld_csd : 1;
        uint32_t reserved14_15 : 2;
        uint32_t almost_empty : 1;
        uint32_t almost_full : 1;
        uint32_t empty : 1;
        uint32_t full : 1;
        uint32_t valid : 1;
        uint32_t reserved21_31 : 11;
    }
    b;
} SPD_STS_REGS ;

typedef union SPD_irqen_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t sub_block_end_irqen : 1;
        uint32_t block_end_irqen : 1;
        uint32_t reserved2_3 : 2;
        uint32_t aempty_irqen : 1;
        uint32_t afull_irqen : 1;
        uint32_t empty_irqen : 1;
        uint32_t full_irqen : 1;
        uint32_t unvalid_irqen : 1;
        uint32_t reserved9_31 : 23;
    }
    b;
} SPD_IRQEN_REGS ;

typedef union SPD_ctl_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t spd_en : 1;
        uint32_t zbuf_en : 1;
        uint32_t data_width : 1;
        uint32_t sw_rst : 1;
        uint32_t sw_cfg : 1;
        uint32_t interval : 1;
        uint32_t reserved6_7 : 2;
        uint32_t valid_bit : 1;
        uint32_t reserved9_31 : 23;
    }
    b;
} SPD_CTL_REGS ;

typedef enum SPDIF_o_wlen
{
	SPDIF_O_WLEN_16	= 0,
	SPDIF_O_WLEN_24,
}
SPDIF_O_WLEN, *PSPDIF_O_WLEN;


typedef struct SPDIF_o_cfg
{
    uint8_t             id;
    uint8_t             sw_cfg;
    uint8_t             zbuf_en;
    uint8_t             valid_bit;
    SPDIF_O_WLEN        wlen;
    uint32_t            csd[6];
    uint32_t            usr[3];
	uint8_t			    tx_srcid;
	SPDIF_O_CORE_REGS	*regs;
}
SPDIF_O_CFG, *PSPDIF_O_CFG;

int32_t silan_spdif_o_dev_open(SPDIF_O_CFG *pcfg);
void silan_spdif_o_start(SPDIF_O_CFG *pcfg);

#endif

