/**
  ******************************************************************************
  * @file    usbd_msc_core.h
  * @author  Audio Application Team
  * @version V1.2.0
  * @date    06-April-2020
  * @brief   header for the usbd_msc_core.c file
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _USB_MSC_CORE_H_
#define _USB_MSC_CORE_H_

#include  "usbd_ioreq.h"

/** @addtogroup USBD_MSC_BOT
  * @{
  */
  
/** @defgroup USBD_MSC
  * @brief This file is the Header file for USBD_msc.c
  * @{
  */ 


/** @defgroup USBD_BOT_Exported_Defines
  * @{
  */ 


#define BOT_GET_MAX_LUN              0xFE
#define BOT_RESET                    0xFF
#define USB_MSC_CONFIG_DESC_SIZ      32

#define MSC_EPIN_SIZE                MSC_MAX_PACKET 
#define MSC_EPOUT_SIZE               MSC_MAX_PACKET 

/**
  * @}
  */ 

/** @defgroup USB_CORE_Exported_Types
  * @{
  */ 

extern USBD_Class_cb_TypeDef  USBD_MSC_cb;
/**
  * @}
  */ 
#ifdef USBD_MSC_ASYNC
void USBD_MSC_Process(void *pdev);
#endif
/**
  * @}
  */ 
#endif /* _USB_MSC_CORE_H_ */
/**
  * @}
  */ 
  
/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/
