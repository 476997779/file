/**
  ******************************************************************************
  * @file    usb_dcd_int.h
  * @author  Audio Application Team
  * @version V2.2.0
  * @date    06-April-2020
  * @brief   Peripheral Device Interface Layer
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef USB_DCD_INT_H__
#define USB_DCD_INT_H__

/* Includes ------------------------------------------------------------------*/
#include "usb_dcd.h"



/** @addtogroup USB_OTG_DRIVER
  * @{
  */
  
/** @defgroup USB_DCD_INT
  * @brief This file is the 
  * @{
  */ 


/** @defgroup USB_DCD_INT_Exported_Defines
  * @{
  */ 

typedef struct _USBD_DCD_INT
{
  uint8_t (* DataOutStage) (USB_OTG_CORE_HANDLE *pdev , uint8_t epnum);
  uint8_t (* DataInStage)  (USB_OTG_CORE_HANDLE *pdev , uint8_t epnum);
  uint8_t (* SetupStage) (USB_OTG_CORE_HANDLE *pdev);
  uint8_t (* SOF) (USB_OTG_CORE_HANDLE *pdev);
  uint8_t (* Reset) (USB_OTG_CORE_HANDLE *pdev);
  uint8_t (* Suspend) (USB_OTG_CORE_HANDLE *pdev);
  uint8_t (* Resume) (USB_OTG_CORE_HANDLE *pdev);
  uint8_t (* IsoINIncomplete) (USB_OTG_CORE_HANDLE *pdev);
  uint8_t (* IsoOUTIncomplete) (USB_OTG_CORE_HANDLE *pdev);  
  
  uint8_t (* DevConnected) (USB_OTG_CORE_HANDLE *pdev);
  uint8_t (* DevDisconnected) (USB_OTG_CORE_HANDLE *pdev);   
  
}USBD_DCD_INT_cb_TypeDef;

extern USBD_DCD_INT_cb_TypeDef *USBD_DCD_INT_fops;
/**
  * @}
  */ 


/** @defgroup USB_DCD_INT_Exported_Types
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USB_DCD_INT_Exported_Macros
  * @{
  */ 

#define CLEAR_IN_EP_INTR(epnum,intr) \
  diepint.d32=0; \
  diepint.b.intr = 1; \
  USB_OTG_WRITE_REG32(&pdev->regs.INEP_REGS[epnum]->DIEPINT,diepint.d32);

#define CLEAR_OUT_EP_INTR(epnum,intr) \
  doepint.d32=0; \
  doepint.b.intr = 1; \
  USB_OTG_WRITE_REG32(&pdev->regs.OUTEP_REGS[(epnum)]->DOEPINT,doepint.d32);

/**
  * @}
  */ 

/** @defgroup USB_DCD_INT_Exported_Variables
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USB_DCD_INT_Exported_FunctionsPrototype
  * @{
  */ 

uint32_t USBD_OTG_ISR_Handler (USB_OTG_CORE_HANDLE *pdev);
uint32_t USBD_OTG_EP1OUT_ISR_Handler (USB_OTG_CORE_HANDLE *pdev);
uint32_t USBD_OTG_EP1IN_ISR_Handler (USB_OTG_CORE_HANDLE *pdev);
/**
  * @}
  */ 


#endif /* USB_DCD_INT_H__ */

/**
  * @}
  */ 

/**
  * @}
  */ 
/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/

