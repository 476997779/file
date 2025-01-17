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
 
#ifndef _SILAN_SSP_H_
#define _SILAN_SSP_H_

#include "assert.h"
#include "silan_types.h"
#include "ap1508.h"
#include "silan_dmac.h"

#define SSP_CP_MODE0            0
#define SSP_CP_MODE1            1
#define SSP_CP_MODE2            2
#define SSP_CP_MODE3            3

typedef struct SSP_core_regs
{
	__IO uint32_t		SSPCR0;
	__IO uint32_t		SSPCR1;
	__IO uint32_t		SSPDR;
	__IO uint32_t		SSPSR;
	__IO uint32_t		SSPCPSR;
	__IO uint32_t		SSPIMSC;
	__IO uint32_t		SSPRIS;
	__IO uint32_t		SSPMIS;
	__IO uint32_t		SSPICR;
	__IO uint32_t		SSPDMACR;	
}
SSP_CORE_REGS, *PSSP_CORE_REGS;

typedef union SSP_sspcr0_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t data_size : 2;
        uint32_t comd_en : 1;
        uint32_t rx_en : 1;
        uint32_t frf : 2;
        uint32_t cpol : 1;
        uint32_t cpha : 1;
        uint32_t scr : 8;
        uint32_t rdf_cmd : 8;
        uint32_t rds_cmd : 8;
    }
    b;
} SSP_SSPCR0_REGS ;

typedef union SSP_sspcr1_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t lbm : 1;
        uint32_t en : 1;
        uint32_t slave_mode : 1;
        uint32_t sod : 1;
        uint32_t sub_fram_num : 9;
        uint32_t fssout_sw : 1;
        uint32_t fssout_sw_en : 1;
        uint32_t fss_hw_en : 1;
        uint32_t wrf_cmd : 8;
        uint32_t dymreg : 8;
    }
    b;
} SSP_SSPCR1_REGS ;

typedef union SSP_sspsr_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t txfifo_empty : 1;
        uint32_t txfifo_no_full : 1;
				uint32_t rxfifo_no_empty : 1;
				uint32_t rxfifo_full : 1;
				uint32_t busy : 1;
				uint32_t rxcomdshft : 8;
				uint32_t reserved13_31 : 19;
    }
    b;
} SSP_SSPSR_REGS ;

typedef union SSP_sspimsc_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t rorim : 1;
        uint32_t rtim : 1;
				uint32_t rxim : 1;
				uint32_t txim : 1;
				uint32_t tfeim : 1;
				uint32_t tnfim : 1;
				uint32_t rneim : 1;
				uint32_t rffim : 1;
				uint32_t cmdim : 1;
				uint32_t softim : 1;
				uint32_t soft_en : 1;
				uint32_t soft_start : 1;		
				uint32_t reserved12_31 : 20;
    }
    b;
} SSP_SSPIMSC_REGS ;

typedef union SSP_sspris_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t rorris : 1;
        uint32_t rtris : 1;
				uint32_t rxris : 1;
				uint32_t txris : 1;
				uint32_t tferis : 1;
				uint32_t tnfris : 1;
				uint32_t rneris : 1;
				uint32_t refris: 1;
				uint32_t cmdris : 1;
				uint32_t softris : 1;		
				uint32_t reserved10_31 : 20;
    }
    b;
} SSP_SSPRIS_REGS ;

typedef union SSP_sspmis_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t rormis : 1;
        uint32_t rtmis : 1;
				uint32_t rxmis : 1;
				uint32_t txmis : 1;
				uint32_t tfemis : 1;
				uint32_t tnfmis : 1;
				uint32_t rnemis : 1;
				uint32_t refmis: 1;
				uint32_t cmdmis : 1;
				uint32_t softmis : 1;		
				uint32_t reserved10_31 : 20;
    }
    b;
} SSP_SSPMIS_REGS ;

typedef union SSP_sspicr_regs
{
    uint32_t d32;
    
    struct
    {
        uint32_t roric : 1;
        uint32_t rtic : 1;
				uint32_t cmdic : 1;
				uint32_t softic : 1;		
				uint32_t reserved4_31 : 28;
    }
    b;
} SSP_SSPICR_REGS ;

typedef enum SSP_datasize
{
	SSP_DATASIZE_32BIT		= 0,
	SSP_DATASIZE_24BIT,
	SSP_DATASIZE_16BIT,
	SSP_DATASIZE_8BIT,
}
SSP_DATASIZE, *PSSP_DATASIZE;

typedef struct SSP_cfg
{
	uint8_t			slave_mode;
	uint8_t			cpha;
	uint8_t			cpol;
	uint8_t			freq;
	uint8_t			tx_srcid;
	uint8_t			rx_srcid;	
}
SSP_CFG, *PSSP_CFG;

typedef struct SSP_port_cfg
{
	DMA_REQUEST		*tx_dma_req;
	DMA_REQUEST		*rx_dma_req;
	int8_t				tx_num;
	int8_t				rx_num;
}
SSP_PORT_CFG, *PSSP_PORT_CFG;

typedef struct SSP_port
{
	SSP_CFG		    ssp_cfg;
	SSP_PORT_CFG	port_cfg;
	SSP_CORE_REGS	*regs;
}
SSP_PORT, *PSSP_PORT;

typedef struct SSP_xfer
{
	uint32_t        xfer_size;      // Transfer size, Bytes
	uint8_t         *rx_buf;
	uint8_t         *tx_buf;
	uint8_t         dma_en;
}
SSP_XFER, *PSSP_XFER;

int32_t silan_ssp_open(SSP_PORT *port, uint8_t mode, uint8_t slave);
int32_t silan_ssp_xfer(SSP_PORT *port, SSP_XFER *xfer);
int32_t silan_ssp_check_busy(SSP_PORT *port);
int32_t silan_ssp_check_dma_done(SSP_PORT *port);

#endif

