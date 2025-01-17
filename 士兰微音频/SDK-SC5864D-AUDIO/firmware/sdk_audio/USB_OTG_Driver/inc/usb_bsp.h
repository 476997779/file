/**
  ******************************************************************************
  * @file    usb_bsp.h
  * @author  Audio Application Team
  * @version V2.2.0
  * @date    06-April-2020
  * @brief   Specific api's relative to the used hardware platform
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_BSP__H__
#define __USB_BSP__H__

/* Includes ------------------------------------------------------------------*/
#include "usb_core.h"
#include "silan_pmu.h"
#include "silan_pic.h"
#include "silan_syscfg.h"
#include "silan_printf.h"
#include "silan_timer.h"

/** @addtogroup USB_OTG_DRIVER
  * @{
  */
  
/** @defgroup USB_BSP
  * @brief This file is the 
  * @{
  */ 


/** @defgroup USB_BSP_Exported_Defines
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup USB_BSP_Exported_Types
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup USB_BSP_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USB_BSP_Exported_Variables
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USB_BSP_Exported_FunctionsPrototype
  * @{
  */ 
void BSP_Init(void);

void USB_OTG_BSP_Init (USB_OTG_CORE_HANDLE *pdev, USB_OTG_CORE_ID_TypeDef coreID, USB_OTG_ROLE role);
void USB_OTG_BSP_uDelay (const uint32_t usec);
void USB_OTG_BSP_mDelay (const uint32_t msec);
void USB_OTG_BSP_EnableInterrupt (USB_OTG_CORE_HANDLE *pdev, USB_OTG_CORE_ID_TypeDef coreID);
void USB_OTG_BSP_TimerIRQ (void);
void USB_OTG_BSP_TimeInit ( void );
#ifdef USE_HOST_MODE
void USB_OTG_BSP_ConfigVBUS(USB_OTG_CORE_HANDLE *pdev);
void USB_OTG_BSP_DriveVBUS(USB_OTG_CORE_HANDLE *pdev,uint8_t state);
void USB_OTG_BSP_Resume(USB_OTG_CORE_HANDLE *pdev) ;                                                                
void USB_OTG_BSP_Suspend(USB_OTG_CORE_HANDLE *pdev);

#endif /* USE_HOST_MODE */

#ifdef _SUPPORT_OS_
void event_urbstate_create(void);
int32_t os_get_urbstate(uint8_t ch_num);
void os_set_urbstate(uint8_t ch_num);
void os_clr_urbstate(uint8_t hc_num);
#endif
/**
  * @}
  */ 

#endif /* __USB_BSP__H__ */

/**
  * @}
  */ 

/**
  * @}
  */ 
/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/

