/**
  ******************************************************************************
  * @file    usbd_shid_core.h
  * @author  Audio Application Team
  * @version V1.2.0
  * @date    06-April-2020
  * @brief   header file for the usbd_shid_core.c file.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/

#ifndef __USB_SHID_CORE_H_
#define __USB_SHID_CORE_H_

#include  "usbd_ioreq.h"
/** @addtogroup AP_USB_OTG_DEVICE_LIBRARY
  * @{
  */
  
/** @defgroup USBD_CUSTOMHID
  * @brief This file is the Header file for usbd_customhid_core.c
  * @{
  */ 


/** @defgroup USBD_CUSTOMHID_Exported_Defines
  * @{
  */ 
#define USBD_SHID_REPORT_DESC_SIZE     72

#define USB_SHID_CONFIG_DESC_SIZ       34
#define USB_SHID_DESC_SIZ              9

#define HID_DESCRIPTOR_TYPE           0x21
#define HID_REPORT_DESC               0x22


#define HID_REQ_SET_PROTOCOL          0x0B
#define HID_REQ_GET_PROTOCOL          0x03

#define HID_REQ_SET_IDLE              0x0A
#define HID_REQ_GET_IDLE              0x02

#define HID_REQ_SET_REPORT            0x09
#define HID_REQ_GET_REPORT            0x01

#define HID_REPORT_TYPE_INPUT                0x01
#define HID_REPORT_TYPE_OUTPUT               0x02
#define HID_REPORT_TYPE_FEATURE              0x03

#define SDFU_SETADDR                         0x01
#define SDFU_ERASE                           0x02
#define SDFU_WDATA                           0x03
#define SDFU_RDATA                           0x04
#define SDFU_GETSTATUS                       0x05
#define SDFU_GETINFO                         0x06

#define SDFU_STATUS_IDLE			         0
#define SDFU_STATUS_BUSY			         1

/**
  * @}
  */ 


/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */
/**
  * @}
  */ 



/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */ 

/**
  * @}
  */ 

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */ 
extern USBD_Class_cb_TypeDef  SHID_cb;
/**
  * @}
  */ 

/** @defgroup USB_CORE_Exported_Functions
  * @{
  */ 
uint8_t USBD_SHID_SendReport (USB_OTG_CORE_HANDLE  *pdev, 
                                 uint8_t *report,
                                 uint16_t len);
int32_t USBD_SHID_Process(void);
/**
  * @}
  */ 

#endif  /* __USB_CUSTOMHID_CORE_H_ */
/**
  * @}
  */ 

/**
  * @}
  */ 
  
/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/
