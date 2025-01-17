/**
  ******************************************************************************
  * @file    usbd_dfu_core.h
  * @author  Audio Application Team
  * @version V1.2.0
  * @date    06-April-2020
  * @brief   header file for the usbd_dfu_core.c file.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/

#ifndef __USB_DFU_CORE_H_
#define __USB_DFU_CORE_H_

#include  "usbd_ioreq.h"
#include  "usbd_sdfu_mal.h"

/** @addtogroup AP_USB_OTG_DEVICE_LIBRARY
  * @{
  */
  
/** @defgroup usbd_dfu
  * @brief This file is the Header file for USBD_dfu.c
  * @{
  */ 


/** @defgroup usbd_dfu_Exported_Defines
  * @{
  */ 
#define USB_SDFU_CONFIG_DESC_SIZ       (18 + (9 * USBD_ITF_MAX_NUM))
#define USB_SDFU_DESC_SIZ              9

#define SDFU_DESCRIPTOR_TYPE           0x21


/*---------------------------------------------------------------------*/
/* SDFU definitions                                                    */
/*---------------------------------------------------------------------*/



/**************************************************/
/* SDFU Requests  SDFU states                      */
/**************************************************/


/**************************************************/
/* SDFU Requests  SDFU status                     */
/**************************************************/
#define SDFU_STATUS_IDLE			0
#define SDFU_STATUS_BUSY			1

/**************************************************/
/* SDFU Requests  SDFU states Manifestation State */
/**************************************************/


/**
  * @}
  */ 


/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */
/**************************************************/
/* SDFU Requests                                  */
/**************************************************/

typedef enum _SDFU_REQUESTS {
  SDFU_SETADDR = 1,
  SDFU_ERASE = 2,
  SDFU_WDATA = 3,
  SDFU_RDATA = 4,
  SDFU_GETSTATUS = 5,
  SDFU_GETINFO = 6
} SDFU_REQUESTS;

typedef  void (*pFunction)(void);
/**
  * @}
  */ 



/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */ 
/**********  Descriptor of DFU interface 0 Alternate setting n ****************/  
#define USBD_SDFU_IF_DESC(n)   0x09,   /* bLength: Interface Descriptor size */ \
                              USB_INTERFACE_DESCRIPTOR_TYPE,   /* bDescriptorType */ \
                              0x00,   /* bInterfaceNumber: Number of Interface */ \
                              (n),      /* bAlternateSetting: Alternate setting */ \
                              0x00,   /* bNumEndpoints*/ \
                              0xFF,   /* bInterfaceClass: User */ \
                              0x00,   /* bInterfaceSubClass : Code */ \
                              0x00,   /* nInterfaceProtocol: protocol */ \
                              USBD_IDX_INTERFACE_STR + (n) + 1 /* iInterface: Index of string descriptor */ \
                              /* 18 */
  
/**
  * @}
  */ 

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */ 

extern USBD_Class_cb_TypeDef  SDFU_cb;
/**
  * @}
  */ 

/** @defgroup USB_CORE_Exported_Functions
  * @{
  */
int32_t usbd_sdfu_process(void);

#endif /* __USB_DFU_CORE_H_ */
/**
  * @}
  */ 

/**
  * @}
  */ 
  
/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/
