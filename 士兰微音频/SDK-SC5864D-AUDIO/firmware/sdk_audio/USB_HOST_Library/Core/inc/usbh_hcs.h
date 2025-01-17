/**
  ******************************************************************************
  * @file    usbh_hcs.h
  * @author  Audio Application Team
  * @version V2.2.0
  * @date    06-April-2020
  * @brief   Header file for usbh_hcs.c
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive  ----------------------------------------------*/
#ifndef __USBH_HCS_H
#define __USBH_HCS_H

/* Includes ------------------------------------------------------------------*/
#include "usbh_core.h"

/** @addtogroup USBH_LIB
  * @{
  */

/** @addtogroup USBH_LIB_CORE
* @{
*/
  
/** @defgroup USBH_HCS
  * @brief This file is the header file for usbh_hcs.c
  * @{
  */ 

/** @defgroup USBH_HCS_Exported_Defines
  * @{
  */
#define HC_MAX           8

#define HC_OK            0x0000
#define HC_USED          0x8000
#define HC_ERROR         0xFFFF
#define HC_USED_MASK     0x7FFF
/**
  * @}
  */ 

/** @defgroup USBH_HCS_Exported_Types
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup USBH_HCS_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USBH_HCS_Exported_Variables
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USBH_HCS_Exported_FunctionsPrototype
  * @{
  */

uint8_t USBH_Alloc_Channel(USB_OTG_CORE_HANDLE *pdev, uint8_t ep_addr);

uint8_t USBH_Free_Channel  (USB_OTG_CORE_HANDLE *pdev, uint8_t idx);

uint8_t USBH_DeAllocate_AllChannel  (USB_OTG_CORE_HANDLE *pdev);

uint8_t USBH_Open_Channel  (USB_OTG_CORE_HANDLE *pdev,
                            uint8_t ch_num,
                            uint8_t dev_address,
                            uint8_t speed,
                            uint8_t ep_type,
                            uint16_t mps);

uint8_t USBH_Modify_Channel (USB_OTG_CORE_HANDLE *pdev,
                            uint8_t hc_num,
                            uint8_t dev_address,
                            uint8_t speed,
                            uint8_t ep_type,
                            uint16_t mps);
/**
  * @}
  */ 



#endif /* __USBH_HCS_H */


/**
  * @}
  */ 

/**
  * @}
  */ 

/**
* @}
*/ 

/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/


