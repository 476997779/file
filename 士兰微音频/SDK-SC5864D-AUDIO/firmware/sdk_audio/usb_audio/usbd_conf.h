/**
  ******************************************************************************
  * @file    usbd_conf.h
  * @author  Audio Application Team
  * @version V1.2.0
  * @date    06-April-2020
  * @brief   USB Device configuration file
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CONF__H__
#define __USBD_CONF__H__

/* Includes ------------------------------------------------------------------*/
#include "usb_conf.h"

/** @defgroup USB_CONF_Exported_Defines
  * @{
  */ 

/* Audio frequency in Hz */
#define SPK_AUDIO_FREQ                  48000 /* Audio frequency in Hz. */
#define MIC_AUDIO_FREQ                  48000 /* Audio frequency in Hz. */

#define DEFAULT_VOLUME                  65    /* Default volume in % (Mute=0%, Max = 100%) in Logarithmic values.
                                                 To get accurate volume variations, it is possible to use a logarithmic
                                                 conversion table to convert from percentage to logarithmic law.
                                                 In order to keep this example code simple, this conversion is not used.*/

/* Use this section to modify the number of supported interfaces and configurations.
   Note that if you modify these parameters, you have to modify the descriptors 
   accordingly in usbd_audio_core.c file */
#define AUDIO_TOTAL_IF_NUM              0x03
#define USBD_CFG_MAX_NUM                1
#define USBD_ITF_MAX_NUM                2
#define USB_MAX_STR_DESC_SIZ            200 

#define USBD_SELF_POWERED               

/**
  * @}
  */ 

/** @defgroup USB_AUDIO_Class_Layer_Parameter
  * @{
  */ 
#define AUDIO_OUT_EP                    0x01
#define AUDIO_IN_EP                     0x82
/**
  * @}
  */ 

/** @defgroup USB_CONF_Exported_Types
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup USB_CONF_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USB_CONF_Exported_Variables
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USB_CONF_Exported_FunctionsPrototype
  * @{
  */ 
/**
  * @}
  */ 


#endif //__USBD_CONF__H__

/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/

