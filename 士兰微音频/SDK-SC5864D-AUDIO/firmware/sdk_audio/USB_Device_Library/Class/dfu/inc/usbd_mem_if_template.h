/**
  ******************************************************************************
  * @file    usbd_mem_if_template.h
  * @author  Audio Application Team
  * @version V1.2.0
  * @date    06-April-2020
  * @brief   Header for usbd_mem_if_template.c file.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MEM_IF_MAL_H
#define __MEM_IF_MAL_H

/* Includes ------------------------------------------------------------------*/
#include "usb_conf.h"

#include "usbd_dfu_mal.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define MEM_START_ADD                 0x00000000 /* Dummy start address */
#define MEM_END_ADD                   (uint32_t)(MEM_START_ADD + (5 * 1024)) /* Dummy Size = 5KB */

#define MEM_IF_STRING                 "@Dummy Memory   /0x00000000/01*002Kg,03*001Kg"

extern DFU_MAL_Prop_TypeDef DFU_Mem_cb;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MEM_IF_MAL_H */

/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/
