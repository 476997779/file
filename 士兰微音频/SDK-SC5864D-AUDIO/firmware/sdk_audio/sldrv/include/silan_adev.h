#ifndef __SILAN_ADEV_H__
#define __SILAN_ADEV_H__

#include "silan_config.h"
#include "silan_i2s.h"
// #include "silan_spdif_in.h"
#ifdef _SUPPORT_ADEV_SPDIF_O_
#include "silan_spdif_o.h"
#endif

#include "silan_codec.h"
#include "silan_dmac.h"

#ifndef ADEV_USER_CONFIG

#define ADEV_NOT_USE_SWAP

// 16bit@48KHz
#define ADEV_MAX_DMAC_CHNL		4
#define ADEV_MAX_DATA_WIDTH		16
#define ADEV_MAX_AUDIO_CHNL		2
#define ADEV_MAX_MULTIPLE_16K	1
#define ADEV_LLI_NUM			6

#define ADEV_LLI_SIZE_PERIOD	1

#endif

#if (ADEV_MAX_DATA_WIDTH == 24)
#define ADEV_MAX_BUF_WIDTH      32
#else
#define ADEV_MAX_BUF_WIDTH      ADEV_MAX_DATA_WIDTH
#endif

#define LLI_SIZE_PER_1MS		16000/1000*ADEV_MAX_BUF_WIDTH/8*ADEV_MAX_AUDIO_CHNL*ADEV_MAX_MULTIPLE_16K

#define ADEV_MAX_LLI_SIZE		LLI_SIZE_PER_1MS*ADEV_LLI_SIZE_PERIOD

typedef struct ADEV_MONI_info
{
	uint32_t		last_ccount;
	int32_t			diff_ccount;
	uint32_t		intr_num;
	uint32_t		intr_cnt;
	uint32_t		intr_total;
	uint32_t		buf_fullness;
}
ADEV_MONI_INFO, *PADEV_MONI_INFO;

typedef struct ADEV_cfg
{
	DMA_REQUEST		*tx_dma_req;
	DMA_REQUEST		*rx_dma_req;
	uint8_t			width;
	uint8_t			burst;
	uint32_t		sample_rate;
	int8_t			tx_num;
	int8_t			rx_num;
	uint32_t		lli_period;
	ADEV_MONI_INFO	*tx_info;
	ADEV_MONI_INFO	*rx_info;
}
ADEV_CFG, *PADEV_CFG;

typedef struct ADEV_I2S_handle
{
	ADEV_CFG		adev_cfg;
	I2S_CFG			i2s_cfg;
	CODEC_CFG		codec_cfg;
}
ADEV_I2S_HANDLE, *PADEV_I2S_HANDLE;

//typedef struct ADEV_SPDIFIN_handle
//{
//	ADEV_CFG		adev_cfg;
//	SPDIFIN_CFG		spdifin_cfg;
//}
//ADEV_SPDIFIN_HANDLE, *PADEV_SPDIFIN_HANDLE;
#ifdef _SUPPORT_ADEV_SPDIF_O_
typedef struct ADEV_SPDIF_O_handle
{
	ADEV_CFG		adev_cfg;
	SPDIF_O_CFG		spdif_o_cfg;
}
ADEV_SPDIF_O_HANDLE, *PADEV_SPDIF_O_HANDLE;
#endif

void silan_adev_init(void);
int32_t silan_adev_pre_write(void *pdev, char **write_p, int bytes);
int32_t silan_adev_pre_read(void *pdev, char **read_p, int bytes);
int32_t silan_adev_read(void *pdev, int bytes);
int32_t silan_adev_write(void *pdev, int bytes);

ADEV_I2S_HANDLE *silan_adev_i2s_alloc(I2S_ID i2s);
int32_t silan_adev_i2s_submit(ADEV_I2S_HANDLE *pdev);
int32_t silan_adev_i2s_open(ADEV_I2S_HANDLE *pdev);
int32_t silan_adev_i2s_set_rate(ADEV_I2S_HANDLE *pdev, int rate);
int32_t silan_adev_i2s_start(ADEV_I2S_HANDLE *pdev);
int32_t silan_adev_i2s_set_gain(ADEV_I2S_HANDLE *pdev, int32_t l_gain, int32_t r_gain);

int32_t silan_adev_get_space(void *pdev);
int32_t silan_adev_ring_read(void *pdev, char *read_p, int bytes);
int32_t silan_adev_ring_write(void *pdev, char *write_p, int bytes);
int32_t silan_adev_get_fullness(void *pdev);

int32_t silan_adev_i2s_stop(ADEV_I2S_HANDLE *pdev);
int32_t silan_adev_i2s_revoke(ADEV_I2S_HANDLE *pdev);

#ifdef _SUPPORT_ADEV_SPDIF_O_
ADEV_SPDIF_O_HANDLE *silan_adev_spdif_o_alloc(void);
int32_t silan_adev_spdif_o_open(ADEV_SPDIF_O_HANDLE *pdev);
int32_t silan_adev_spdif_o_set_rate(ADEV_SPDIF_O_HANDLE *pdev, int rate);
int32_t silan_adev_spdif_o_submit(ADEV_SPDIF_O_HANDLE *pdev);
int32_t silan_adev_spdif_o_start(ADEV_SPDIF_O_HANDLE *pdev);
#endif

#endif
