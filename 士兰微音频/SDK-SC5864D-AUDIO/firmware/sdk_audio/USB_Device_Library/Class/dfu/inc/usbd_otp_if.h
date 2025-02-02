/**
  ******************************************************************************
  * @file    usbd_otp_if.h
  * @author  Audio Application Team
  * @version V1.2.0
  * @date    06-April-2020
  * @brief   Header for usbd_otp_if.c file.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __OTP_IF_MAL_H
#define __OTP_IF_MAL_H

/* Includes ------------------------------------------------------------------*/
#include "usbd_dfu_mal.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define OTP_START_ADD                  0x1FFF7800             
#define OTP_END_ADD                    (uint32_t)(OTP_START_ADD + 528) 

#define OTP_IF_STRING                  "@OTP Area   /0x1FFF7800/01*512 g,01*016 g"

extern DFU_MAL_Prop_TypeDef DFU_Otp_cb;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __OTP_IF_MAL_H */

/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/
