/**
  ******************************************************************************
  * @file    usbd_audio_core.h
  * @author  Audio Application Team
  * @version V1.2.0
  * @date    06-April-2020
  * @brief   header file for the usbd_audio_core.c file.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/

#ifndef __USB_AUDIO_CORE_H_
#define __USB_AUDIO_CORE_H_

#include "usbd_ioreq.h"
#include "usbd_req.h"
#include "usbd_desc.h"




/** @addtogroup AP_USB_OTG_DEVICE_LIBRARY
  * @{
  */
  
/** @defgroup usbd_audio
  * @brief This file is the Header file for USBD_audio.c
  * @{
  */ 


/** @defgroup usbd_audio_Exported_Defines
  * @{
  */ 

/* AudioFreq * DataSize (2 bytes) * NumChannels (Stereo: 2) */
#define AUDIO_OUT_PACKET                              (uint32_t)(((SPK_AUDIO_FREQ * 2 * 2) /1000)) 
#define AUDIO_IN_PACKET                               (uint32_t)(((MIC_AUDIO_FREQ * 2 * 2) /1000)) 

/* Number of sub-packets in the audio transfer buffer. You can modify this value but always make sure
  that it is an even number and higher than 3 */
#define OUT_PACKET_NUM                               4
#define IN_PACKET_NUM                                4

/* Total size of the audio transfer buffer */
#define TOTAL_OUT_BUF_SIZE                           ((uint32_t)(AUDIO_OUT_PACKET * OUT_PACKET_NUM))
#define TOTAL_IN_BUF_SIZE                            ((uint32_t)(AUDIO_IN_PACKET * IN_PACKET_NUM))

#define AUDIO_CONFIG_DESC_SIZE                        192
#define AUDIO_INTERFACE_DESC_SIZE                     9
#define AUDIO_CS_AC_INTERFACE_DESC_SIZE               10
#define USB_AUDIO_DESC_SIZ                            0x09
#define AUDIO_STANDARD_ENDPOINT_DESC_SIZE             0x09
#define AUDIO_STREAMING_ENDPOINT_DESC_SIZE            0x07

#define AUDIO_DESCRIPTOR_TYPE                         0x21
#define USB_DEVICE_CLASS_AUDIO                        0x01
#define AUDIO_SUBCLASS_AUDIOCONTROL                   0x01
#define AUDIO_SUBCLASS_AUDIOSTREAMING                 0x02
#define AUDIO_PROTOCOL_UNDEFINED                      0x00
#define AUDIO_STREAMING_GENERAL                       0x01
#define AUDIO_STREAMING_FORMAT_TYPE                   0x02

/* Audio Descriptor Types */
#define AUDIO_INTERFACE_DESCRIPTOR_TYPE               0x24
#define AUDIO_ENDPOINT_DESCRIPTOR_TYPE                0x25

/* Audio Control Interface Descriptor Subtypes */
#define AUDIO_CONTROL_HEADER                          0x01
#define AUDIO_CONTROL_INPUT_TERMINAL                  0x02
#define AUDIO_CONTROL_OUTPUT_TERMINAL                 0x03
#define AUDIO_CONTROL_SELECTOR_UNIT                   0x05
#define AUDIO_CONTROL_FEATURE_UNIT                    0x06

#define AUDIO_INPUT_TERMINAL_DESC_SIZE                0x0C
#define AUDIO_OUTPUT_TERMINAL_DESC_SIZE               0x09
#define AUDIO_STREAMING_INTERFACE_DESC_SIZE           0x07

#define AUDIO_CONTROL_MUTE                            0x0001

#define AUDIO_FORMAT_TYPE_I                           0x01
#define AUDIO_FORMAT_TYPE_III                         0x03

#define USB_ENDPOINT_TYPE_ISOCHRONOUS                 0x01
#define AUDIO_ENDPOINT_GENERAL                        0x01

#define AUDIO_REQ_GET_CUR                             0x81
#define AUDIO_REQ_SET_CUR                             0x01

#define AUDIO_OUT_STREAMING_CTRL                      0x05
#define AUDIO_IN_STREAMING_CTRL                       0x02

/**
  * @}
  */ 


/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */
typedef struct _Audio_Fops
{
    uint8_t  (*Init)         (uint32_t  AudioFreq, uint32_t Volume, uint32_t options);
    uint8_t  (*DeInit)       (uint32_t options);
    uint8_t  (*AudioCmd)     (uint8_t* pbuf, uint32_t size, uint8_t cmd);
    uint8_t  (*VolumeCtl)    (uint8_t vol);
    uint8_t  (*MuteCtl)      (uint8_t cmd);
    uint8_t  (*PeriodicTC)   (uint8_t cmd);
    uint8_t  (*GetState)     (void);
}AUDIO_FOPS_TypeDef;
/**
  * @}
  */ 



/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */ 
#define AUDIO_PACKET_SZE(frq)          (uint8_t)(((frq * 2 * 2)/1000) & 0xFF), \
                                       (uint8_t)((((frq * 2 * 2)/1000) >> 8) & 0xFF)
#define AUDIO_MIC_PACKET_SZE(frq)      (uint8_t)(((frq * 2 * 2)/1000) & 0xFF), \
                                       (uint8_t)((((frq * 2 * 2)/1000) >> 8) & 0xFF)

#define SAMPLE_FREQ(frq)               (uint8_t)(frq), (uint8_t)((frq >> 8)), (uint8_t)((frq >> 16))
/**
  * @}
  */ 

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */ 

extern USBD_Class_cb_TypeDef  AUDIO_cb;

/**
  * @}
  */ 

/** @defgroup USB_CORE_Exported_Functions
  * @{
  */
int32_t silan_usbd_audio_pre_read(char **read_p, int bytes);
int32_t silan_usbd_audio_read(int bytes);
int32_t silan_usbd_audio_pre_write(char **write_p, int bytes);
int32_t silan_usbd_audio_write(int bytes);
/**
  * @}
  */ 

#endif  /* __USB_AUDIO_CORE_H_ */
/**
  * @}
  */ 

/**
  * @}
  */ 
  
/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/
