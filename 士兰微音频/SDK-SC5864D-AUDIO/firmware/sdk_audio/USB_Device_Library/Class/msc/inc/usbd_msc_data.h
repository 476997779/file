/**
  ******************************************************************************
  * @file    usbd_msc_data.h
  * @author  Audio Application Team
  * @version V1.2.0
  * @date    06-April-2020
  * @brief   header for the usbd_msc_data.c file
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef _USBD_MSC_DATA_H_
#define _USBD_MSC_DATA_H_

/* Includes ------------------------------------------------------------------*/
#include "usbd_conf.h"

/** @addtogroup AP_USB_OTG_DEVICE_LIBRARY
  * @{
  */
  
/** @defgroup USB_INFO
  * @brief general defines for the usb device library file
  * @{
  */ 

/** @defgroup USB_INFO_Exported_Defines
  * @{
  */ 
#define MODE_SENSE6_LEN			 8
#define MODE_SENSE10_LEN		 8
#define LENGTH_INQUIRY_PAGE00		 7
#define LENGTH_FORMAT_CAPACITIES    	20

/**
  * @}
  */ 


/** @defgroup USBD_INFO_Exported_TypesDefinitions
  * @{
  */
/**
  * @}
  */ 



/** @defgroup USBD_INFO_Exported_Macros
  * @{
  */ 

/**
  * @}
  */ 

/** @defgroup USBD_INFO_Exported_Variables
  * @{
  */ 
extern const uint8_t MSC_Page00_Inquiry_Data[];  
extern const uint8_t MSC_Mode_Sense6_data[];
extern const uint8_t MSC_Mode_Sense10_data[] ;

/**
  * @}
  */ 

/** @defgroup USBD_INFO_Exported_FunctionsPrototypes
  * @{
  */ 

/**
  * @}
  */ 

#endif /* _USBD_MSC_DATA_H_ */

/**
  * @}
  */ 

/**
* @}
*/ 

/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/
