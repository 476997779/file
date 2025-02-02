/**
  ******************************************************************************
  * @file    usbh_msc_core.h
  * @author  Audio Application Team
  * @version V2.2.0
  * @date    06-April-2020
  * @brief   This file contains all the prototypes for the usbh_msc_core.c
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive  ----------------------------------------------*/
#ifndef __USBH_MSC_CORE_H
#define __USBH_MSC_CORE_H

/* Includes ------------------------------------------------------------------*/
#include "usbh_core.h"
#include "usbh_stdreq.h"
#include "usb_bsp.h"
#include "usbh_ioreq.h"
#include "usbh_hcs.h"
#include "usbh_msc_core.h"
#include "usbh_msc_scsi.h"
#include "usbh_msc_bot.h"

/** @addtogroup USBH_LIB
  * @{
  */

/** @addtogroup USBH_CLASS
  * @{
  */

/** @addtogroup USBH_MSC_CLASS
  * @{
  */
  
/** @defgroup USBH_MSC_CORE
  * @brief This file is the Header file for usbh_msc_core.c
  * @{
  */ 


/** @defgroup USBH_MSC_CORE_Exported_Types
  * @{
  */ 


/* Structure for MSC process */
typedef struct _MSC_Process
{
  uint8_t              hc_num_in; 
  uint8_t              hc_num_out; 
  uint8_t              MSBulkOutEp;
  uint8_t              MSBulkInEp;
  uint16_t             MSBulkInEpSize;
  uint16_t             MSBulkOutEpSize;
  uint8_t              buff[USBH_MSC_MPS_SIZE];
  uint8_t              maxLun;
}
MSC_Machine_TypeDef; 


/**
  * @}
  */ 



/** @defgroup USBH_MSC_CORE_Exported_Defines
  * @{
  */

#define USB_REQ_BOT_RESET                0xFF
#define USB_REQ_GET_MAX_LUN              0xFE
    

/**
  * @}
  */ 

/** @defgroup USBH_MSC_CORE_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USBH_MSC_CORE_Exported_Variables
  * @{
  */ 
extern USBH_Class_cb_TypeDef  USBH_MSC_cb;
extern MSC_Machine_TypeDef    MSC_Machine;
extern uint8_t MSCErrorCount;

/**
  * @}
  */ 

/** @defgroup USBH_MSC_CORE_Exported_FunctionsPrototype
  * @{
  */ 



/**
  * @}
  */ 

#endif  /* __USBH_MSC_CORE_H */


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



