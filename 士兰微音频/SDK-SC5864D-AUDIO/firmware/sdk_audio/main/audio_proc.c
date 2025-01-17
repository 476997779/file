/*
***************************************************************************************************
* 名称: audio_proc.c
* 描述: 
* 作者: yrf
* 时间: 
***************************************************************************************************
*/
#include "silan_printf.h"
#include "silan_adev_onelli.h"
#include "silan_syscfg.h"
#include "silan_iomux.h"

#include "string.h"

#include "usbd_audio_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usb_conf.h"
#include "usbd_audio_micspk.h"

/* 宏定义 ****************************************************************************************/
#define AUDIO_CHS				2									// 2 4 6 8
#define AUDIO_BITS			16								// 16 24
#define AUDIO_SAMPLES		48000							// 8000 16000 32000 12000 24000 48000 11025 22050 44100

/* 变量 ******************************************************************************************/
ADEV_I2S_HANDLE		i2s_o1_dev;
ADEV_I2S_HANDLE		*pi2s_o1_dev;
static int o1_buf[1920/sizeof(int)];

ADEV_I2S_HANDLE		i2s_o3_dev;
ADEV_I2S_HANDLE		*pi2s_o3_dev;
static int o3_buf[1920/sizeof(int)];

ADEV_I2S_HANDLE		i2s_i1_dev;
ADEV_I2S_HANDLE		*pi2s_i1_dev;
static int i1_buf[1920/sizeof(int)];

ADEV_I2S_HANDLE		i2s_i3_dev;
ADEV_I2S_HANDLE		*pi2s_i3_dev;
static int i3_buf[1920/sizeof(int)];

extern USB_OTG_CORE_HANDLE      USB_HS_Core;
/* 函数 ******************************************************************************************/

/*
*************************************************************
函数 : audio_dev_init
功能 : 初始化配置I2S和CODEC
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void audio_dev_init(void)
{
	silan_dmac_req_matrix_init();
	silan_dmac_init();
	
	silan_codec1_cclk_config(CLK_ON);
	silan_codec2_cclk_config(CLK_ON);

	silan_adev_init();
// O1
	pi2s_o1_dev = &i2s_o1_dev;
	SL_LOG("i2s o1 pdev=%p", pi2s_o1_dev);
  memset(pi2s_o1_dev, 0, sizeof(ADEV_I2S_HANDLE));
  pi2s_o1_dev->i2s_cfg.id = I2S_ID_O1;
	pi2s_o1_dev->adev_cfg.width	= AUDIO_BITS;
	
	if (AUDIO_CHS == 4) {
		pi2s_o1_dev->i2s_cfg.ch		= I2S_CH_40;
	} else if (AUDIO_CHS == 6) {
		pi2s_o1_dev->i2s_cfg.ch		= I2S_CH_51;
	} else if (AUDIO_CHS == 8) {
		pi2s_o1_dev->i2s_cfg.ch		= I2S_CH_71;
	} else {
		pi2s_o1_dev->i2s_cfg.ch		= I2S_CH_20;
	}
	pi2s_o1_dev->i2s_cfg.ws		= I2S_WS_32;
	pi2s_o1_dev->i2s_cfg.prot	= I2S_PROT_I2S;
	pi2s_o1_dev->i2s_cfg.codec	= CODEC_ID_1;
	
// O3	
	pi2s_o3_dev = &i2s_o3_dev;
	SL_LOG("i2s o3 pdev=%p", pi2s_o3_dev);
  memset(pi2s_o3_dev, 0, sizeof(ADEV_I2S_HANDLE));
  pi2s_o3_dev->i2s_cfg.id = I2S_ID_O3;
	pi2s_o3_dev->adev_cfg.width	= AUDIO_BITS;
	pi2s_o3_dev->i2s_cfg.ch		= I2S_CH_20;
	pi2s_o3_dev->i2s_cfg.ws		= I2S_WS_32;
	pi2s_o3_dev->i2s_cfg.prot	= I2S_PROT_I2S;
	pi2s_o3_dev->i2s_cfg.codec	= CODEC_ID_EXT;
	pi2s_o3_dev->i2s_cfg.master	= CLK_MASTER;
	
// I1
	pi2s_i1_dev = &i2s_i1_dev;
	SL_LOG("i2s i1 pdev=%p", pi2s_i1_dev);
	memset(pi2s_i1_dev, 0, sizeof(ADEV_I2S_HANDLE));
	pi2s_i1_dev->i2s_cfg.id = I2S_ID_I1;

	pi2s_i1_dev->adev_cfg.width	= AUDIO_BITS;

	if (AUDIO_CHS == 4) {
		pi2s_i1_dev->i2s_cfg.ch		= I2S_CH_40;
	} else if (AUDIO_CHS == 6) {
		pi2s_i1_dev->i2s_cfg.ch		= I2S_CH_51;
	} else if (AUDIO_CHS == 8) {
		pi2s_i1_dev->i2s_cfg.ch		= I2S_CH_71;
	} else {
		pi2s_i1_dev->i2s_cfg.ch		= I2S_CH_20;
	}
	pi2s_i1_dev->i2s_cfg.ws		= I2S_WS_32;
	pi2s_i1_dev->i2s_cfg.prot	= I2S_PROT_I2S;
	pi2s_i1_dev->i2s_cfg.codec	= CODEC_ID_1;//CODEC_ID_EXT;//
	pi2s_i1_dev->i2s_cfg.master	= CLK_MASTER;
	pi2s_i1_dev->codec_cfg.adc_sel= CODEC_ADSEL_AUX;//CODEC_ADSEL_FM;//
	pi2s_i1_dev->codec_cfg.adc_diff = CODEC_SINGLE;

// I3	
	pi2s_i3_dev = &i2s_i3_dev;
	SL_LOG("i2s i3 pdev=%p", pi2s_i3_dev);
	memset(pi2s_i3_dev, 0, sizeof(ADEV_I2S_HANDLE));
	pi2s_i3_dev->i2s_cfg.id = I2S_ID_I3;
	pi2s_i3_dev->adev_cfg.width	= AUDIO_BITS;
	pi2s_i3_dev->i2s_cfg.ch		= I2S_CH_20;
	pi2s_i3_dev->i2s_cfg.ws		= I2S_WS_32;
	pi2s_i3_dev->i2s_cfg.prot	= I2S_PROT_I2S;
	pi2s_i3_dev->i2s_cfg.codec	= CODEC_ID_EXT;
	pi2s_i3_dev->i2s_cfg.master	= CLK_MASTER;

// O1
	silan_adev_i2s_open(pi2s_o1_dev);
	silan_adev_i2s_set_rate(pi2s_o1_dev, AUDIO_SAMPLES);
  silan_adev_i2s_submit(pi2s_o1_dev, o1_buf, sizeof(o1_buf));
	silan_adev_i2s_start(pi2s_o1_dev);
	silan_adev_i2s_set_gain(pi2s_o1_dev, -150, -150);//210放大输出刚好不失真
// O3
	silan_adev_i2s_open(pi2s_o3_dev);
	silan_adev_i2s_set_rate(pi2s_o3_dev, AUDIO_SAMPLES);
  silan_adev_i2s_submit(pi2s_o3_dev, o3_buf, sizeof(o3_buf));
	silan_adev_i2s_start(pi2s_o3_dev);

// I1
	silan_adev_i2s_open(pi2s_i1_dev);
	silan_adev_i2s_set_rate(pi2s_i1_dev, AUDIO_SAMPLES);
  silan_adev_i2s_submit(pi2s_i1_dev, i1_buf, sizeof(i1_buf));
	silan_adev_i2s_start(pi2s_i1_dev);
	//silan_adev_i2s_set_gain(pi2s_i1_dev, 0, 0);
// I3
	silan_adev_i2s_open(pi2s_i3_dev);
	silan_adev_i2s_set_rate(pi2s_i3_dev, AUDIO_SAMPLES);
  silan_adev_i2s_submit(pi2s_i3_dev, i3_buf, sizeof(i3_buf));
	silan_adev_i2s_start(pi2s_i3_dev);
}

/*
*************************************************************
函数 : audio_spk_proc
功能 : USB收到的数据，通过lineout输出
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void audio_spk_proc(void)
{
	int32_t ret;
	signed short *out1;
	signed short *usb_in;
	int xfer_size = 192;
  
	ret = silan_adev_pre_write((void *)pi2s_o1_dev, (char **)&out1, xfer_size);
	if (ret != xfer_size) {
		return;
	}
	
  ret = silan_usbd_audio_pre_read((char **)&usb_in, xfer_size);
	if (ret != xfer_size) {
		return;
	}
	
	memcpy(out1, usb_in, xfer_size);
	
	silan_usbd_audio_read(xfer_size);

	silan_adev_write((void *)pi2s_o1_dev, xfer_size);
}

/*
*************************************************************
函数 : audio_mic_proc
功能 : AUX收到的数据，通过USB输出
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void audio_mic_proc(void)
{
	int32_t ret;
	signed short *in1;
	signed short *usb_out;
	int xfer_size = 192;
    
	ret = silan_adev_pre_read((void *)pi2s_i1_dev, (char **)&in1, xfer_size);
	if (ret != xfer_size) {
		return;
	}

  ret = silan_usbd_audio_pre_write((char **)&usb_out, xfer_size);
	if(ret != xfer_size) {
		return;
	}
    
	memcpy(usb_out, in1, xfer_size);
	
  silan_usbd_audio_write(xfer_size);

	silan_adev_read((void *)pi2s_i1_dev, xfer_size);
}

/*
*************************************************************
函数 : audio_dev_proc
功能 : 内部CODEC处理, AUX收到的数据，通过LINEOUT输出
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void audio_dev_proc(void)
{
	int32_t ret;
  int xfer_size = 192;
	
  signed short *out1;
	ret = silan_adev_pre_write((void *)pi2s_o1_dev, (char **)&out1, xfer_size);
	if (ret != xfer_size) {
		return;
	}

  signed short *in1;
	ret = silan_adev_pre_read((void *)pi2s_i1_dev, (char **)&in1, xfer_size);
	if (ret != xfer_size) {
		return;
	}

	memcpy(out1, in1, xfer_size);

	silan_adev_read((void *)pi2s_i1_dev, xfer_size);

	silan_adev_write((void *)pi2s_o1_dev, xfer_size);
}

/*
*************************************************************
函数 : audio_ext_codec_proc
功能 : 外部CODEC处理，I2SIN到I2SOUT
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void audio_ext_codec_proc(void)
{
	int32_t ret;
	int xfer_size = 192;
	
	signed short *out3;
	ret = silan_adev_pre_write((void *)pi2s_o3_dev, (char **)&out3, xfer_size);
	if (ret != xfer_size) {
		return;
	}

	signed short *in3;
	ret = silan_adev_pre_read((void *)pi2s_i3_dev, (char **)&in3, xfer_size);
	if (ret != xfer_size) {
		return;
	}
	
	memcpy(out3, in3, xfer_size);

	silan_adev_read((void *)pi2s_i3_dev, xfer_size);

	silan_adev_write((void *)pi2s_o3_dev, xfer_size);
}

/*
*************************************************************
函数 : usb_audio_init
功能 : usbaudio初始化
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void usb_audio_init(void)
{
	USBD_Init(&USB_HS_Core, 
			  USB_OTG_HS_CORE_ID,
			  &USR_desc,
			  &AUDIO_cb, 
			  &USRD_cb);
    
	silan_mdelay(2000);
}

/*
*************************************************************
函数 : usb_audio_proc
功能 : 
输入 : 
输出 : 
注意 : 
*************************************************************
*/
void usb_audio_proc(void)
{
	audio_mic_proc();  
	audio_spk_proc();
}
/*
***************************************************************************************************
                                            END
***************************************************************************************************
*/