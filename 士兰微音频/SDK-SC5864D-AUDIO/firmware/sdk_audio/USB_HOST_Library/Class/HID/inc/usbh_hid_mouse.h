/**
  ******************************************************************************
  * @file    usbh_hid_mouse.h 
  * @author  Audio Application Team
  * @version V2.2.0
  * @date    06-April-2020
  * @brief   This file contains all the prototypes for the usbh_hid_mouse.c
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 


/* Define to prevent recursive  ----------------------------------------------*/
#ifndef __USBH_HID_MOUSE_H
#define __USBH_HID_MOUSE_H

/* Includes ------------------------------------------------------------------*/
#include "usbh_hid_core.h"

/** @addtogroup USBH_LIB
  * @{
  */

/** @addtogroup USBH_CLASS
  * @{
  */

/** @addtogroup USBH_HID_CLASS
  * @{
  */

/** @defgroup USBH_HID_MOUSE
  * @brief This file is the Header file for USBH_HID_MOUSE.c
  * @{
  */ 


/** @defgroup USBH_HID_MOUSE_Exported_Types
  * @{
  */ 
typedef struct _HID_MOUSE_Data
{
  uint8_t              x; 
  uint8_t              y;
  uint8_t              z;               /* Not Supported */ 
  uint8_t              button; 
}
HID_MOUSE_Data_TypeDef;

/**
  * @}
  */ 

/** @defgroup USBH_HID_MOUSE_Exported_Defines
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USBH_HID_MOUSE_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USBH_HID_MOUSE_Exported_Variables
  * @{
  */ 

extern HID_cb_TypeDef HID_MOUSE_cb;
extern HID_MOUSE_Data_TypeDef	 HID_MOUSE_Data;
/**
  * @}
  */ 

/** @defgroup USBH_HID_MOUSE_Exported_FunctionsPrototype
  * @{
  */ 
void  USR_MOUSE_Init (void);
void  USR_MOUSE_ProcessData (HID_MOUSE_Data_TypeDef *data);
/**
  * @}
  */ 

#endif /* __USBH_HID_MOUSE_H */

/**
  * @}
  */ 

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
