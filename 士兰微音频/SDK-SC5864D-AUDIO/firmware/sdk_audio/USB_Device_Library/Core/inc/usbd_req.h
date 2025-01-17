/**
  ******************************************************************************
  * @file    usbd_req.h
  * @author  Audio Application Team
  * @version V1.2.0
  * @date    06-April-2020
  * @brief   header file for the usbd_req.c file
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __USB_REQUEST_H_
#define __USB_REQUEST_H_

/* Includes ------------------------------------------------------------------*/
#include  "usbd_def.h"
#include  "usbd_core.h"
#include  "usbd_conf.h"


/** @addtogroup AP_USB_OTG_DEVICE_LIBRARY
  * @{
  */
  
/** @defgroup USBD_REQ
  * @brief header file for the usbd_ioreq.c file
  * @{
  */ 

/** @defgroup USBD_REQ_Exported_Defines
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup USBD_REQ_Exported_Types
  * @{
  */
/**
  * @}
  */ 



/** @defgroup USBD_REQ_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USBD_REQ_Exported_Variables
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USBD_REQ_Exported_FunctionsPrototype
  * @{
  */ 

USBD_Status  USBD_StdDevReq (USB_OTG_CORE_HANDLE  *pdev, USB_SETUP_REQ  *req);
USBD_Status  USBD_StdItfReq (USB_OTG_CORE_HANDLE  *pdev, USB_SETUP_REQ  *req);
USBD_Status  USBD_StdEPReq (USB_OTG_CORE_HANDLE  *pdev, USB_SETUP_REQ  *req);
void USBD_ParseSetupRequest( USB_OTG_CORE_HANDLE  *pdev,
                                    USB_SETUP_REQ *req);

void USBD_CtlError( USB_OTG_CORE_HANDLE  *pdev,
                            USB_SETUP_REQ *req);

void USBD_GetString(uint8_t *desc, uint8_t *unicode, uint16_t *len);
/**
  * @}
  */ 

#endif /* __USB_REQUEST_H_ */

/**
  * @}
  */ 

/**
* @}
*/ 


/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/
