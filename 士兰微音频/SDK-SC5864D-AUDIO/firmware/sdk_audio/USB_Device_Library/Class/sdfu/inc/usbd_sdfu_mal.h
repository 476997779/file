/**
  ******************************************************************************
  * @file    usbd_dfu_mal.h
  * @author  Audio Application Team
  * @version V1.2.0
  * @date    06-April-2020
  * @brief   Header for usbd_dfu_mal.c file.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DFU_MAL_H
#define __DFU_MAL_H

/* Includes ------------------------------------------------------------------*/
#include "usb_conf.h"

#include "usbd_conf.h"
#include "usbd_sdfu_core.h"

/* Exported types ------------------------------------------------------------*/
typedef struct _DFU_MAL_PROP
{
  const uint8_t* pStrDesc;
  uint16_t (*pMAL_Init)     (void);   
  uint16_t (*pMAL_DeInit)   (void);   
  uint16_t (*pMAL_Erase)    (uint32_t Add, uint32_t Len);
  uint16_t (*pMAL_Write)    (uint32_t Add, uint32_t Len);
  uint8_t  *(*pMAL_Read)    (uint32_t Add, uint32_t Len);
  uint16_t (*pMAL_CheckAdd) (uint32_t Add, uint32_t Len);
  const uint32_t EraseTiming;
  const uint32_t WriteTiming;
}
DFU_MAL_Prop_TypeDef;


/* Exported constants --------------------------------------------------------*/
#define MAL_OK                          0
#define MAL_FAIL                        1

/* useful macro ---------------------------------------------------------------*/
#define _1st_BYTE(x)  (uint8_t)((x)&0xFF)             /* 1st addressing cycle */
#define _2nd_BYTE(x)  (uint8_t)(((x)&0xFF00)>>8)      /* 2nd addressing cycle */
#define _3rd_BYTE(x)  (uint8_t)(((x)&0xFF0000)>>16)   /* 3rd addressing cycle */
#define _4th_BYTE(x)  (uint8_t)(((x)&0xFF000000)>>24) /* 4th addressing cycle */

/* Exported macro ------------------------------------------------------------*/
#define SET_POLLING_TIMING(x)   buffer[1] = _1st_BYTE(x);\
                                buffer[2] = _2nd_BYTE(x);\
                                buffer[3] = _3rd_BYTE(x);  

/* Exported functions ------------------------------------------------------- */

uint16_t MAL_Init (void);
uint16_t MAL_DeInit (void);
uint16_t MAL_Erase (uint32_t SectorAddress, uint32_t DataLength);
uint16_t MAL_Write (uint32_t SectorAddress, uint32_t DataLength);
uint8_t *MAL_Read  (uint32_t SectorAddress, uint32_t DataLength);
uint16_t MAL_GetStatus(uint32_t SectorAddress ,uint8_t Cmd, uint8_t *buffer);

extern uint8_t  MAL_Buffer[XFERSIZE]; /* RAM Buffer for Downloaded Data */
#endif /* __DFU_MAL_H */

/************************ (C) COPYRIGHT Silan Microelectronics *****END OF FILE****/
