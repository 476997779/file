#ifndef __ADC_H
#define __ADC_H

#include "ls2p500.h"
#include "type.h"

typedef enum {AWDAL = 0, AWDAU = 1, AWDBL = 2, AWDBU = 3, DMA0 = 4, DMA1 = 5, DMA2 = 6, DMA3 = 7, SD = 8} ADCIntSel;

uint64_t ADC_CFG ();
uint64_t DAC_CFG ();

void     ADCCfg         (uint16_t  ACHEn, uint8_t   Cont,  uint8_t  ClkDiv,   uint8_t  SmpD);
void     ADCEn          (uint8_t   ADCEn);
void     ADCTEn         (uint8_t   TStartEn);
void     ADCChEn        (uint16_t  ChEn);
void     ADCDMALen      (uint8_t   Ch,    uint8_t  DMALen);
void     ADCFSStart     (uint8_t   Ch);
void     ADCFSStartGroup(uint8_t   mask,  uint8_t  FSS);
void     ADCSSStart     (uint8_t   SSS);
void     ADCAwd         (uint8_t   Unit,  uint8_t  Ch,     uint16_t LB,  uint16_t UB);
void     ADCIntEn       (ADCIntSel intr);
uint8_t  ADCGetIntStat  (ADCIntSel intr);
void     ADCIntClr      (ADCIntSel intr);
uint16_t ADCGetData     (uint8_t   Ch);
uint8_t  ADCGetDataFlag (uint8_t   Ch);
void     ADCDataFlagClr (uint8_t   Ch);
void     ADCOffset      (uint8_t   Off,   uint8_t  Gain);
void     ADCBase        (uint8_t   Ch,    uint32_t Addr);

void     DACEn          (uint8_t   Enable);
void     DACChEn        (uint8_t   En);
void     DACCD          (uint16_t  CD);
void     DACData        (uint8_t   Ch,    uint8_t  Data);

typedef union adc_cfg {
   uint32_t d32;
   struct {
      unsigned SmpD:4;   // [ 3: 0]   Sample delay
      unsigned ClkDiv:3; // [ 6: 4]   Clock divider
      unsigned Cont:1;   // [    7]   Continuous mode
      unsigned reserved_8_15:8;
      unsigned ACHEn:16; // [31:16]   ACH enable
   } b;
} adc_cfg_t;

typedef union adc_en {
   uint32_t d32;
   struct {
      unsigned ChEn:16;    // [15: 0]   Channel enable
      unsigned TStartEn:4; // [19:16]   Tigger start enable
      unsigned reserved_20_30:11;
      unsigned ADCEn:1;    // [   31]   ADC unit enable
   } b;
} adc_en_t;

// DMALen:5;      [ 4: 0]   Number of group (8 samples) to be transfered for channel 0-3 (N+1)
// reserved_5_7:3;

typedef union adc_dmalen {
   uint32_t d32;
   struct {
      uint8_t dmalen_u[4];
   } b;
} adc_dmalen_t;

typedef union adc_sstart {
   uint32_t d32;
   struct {
      unsigned FSS:4;   // [ 3: 0]*/ Fast channels software control
      unsigned SSS:1;   // [    4]*/ Slow channels software control
      unsigned reserved_5_31:27;
   } b;
} adc_sstart_t;

typedef union adc_awd {
   uint32_t d32;
   struct {
      unsigned LB:12;   // [11: 0]   Analog watchdog A lower boundary
      unsigned reserved_12_15:4;
      unsigned UB:12;   // [27:16]   Analog watchdog A upper boundary
      unsigned Ch:4;    // [31:28]   Analog watchdog A channel select
   } b;
} adc_awd_t;

typedef union adc_inten {
   uint32_t d32;
   struct {
      unsigned AWD:4;   // [  0]   AWD A lower boundary interrupt enable
                        // [  1]   AWD A upper boundary interrupt enable
                        // [  2]   AWD B lower boundary interrupt enable
                        // [  3]   AWD B upper boundary interrupt enable
      unsigned DMA:4;   // [7:4]   Channel 3-0 DMA done interrupt enable
      unsigned SD:1;    // [  8]   Sequence done interrupt enable
   } b;
} adc_inten_t;

typedef union adc_intstat {
   uint32_t d32;
      unsigned AWD:4;   // [  0]   AWD A lower boundary interrupt enable
                        // [  1]   AWD A upper boundary interrupt enable
                        // [  2]   AWD B lower boundary interrupt enable
                        // [  3]   AWD B upper boundary interrupt enable
      unsigned DMA:4;   // [7:4]   Channel 3-0 DMA done interrupt enable
      unsigned SD:1;    // [  8]   Sequence done interrupt enable
   struct {
   } b;
} adc_intstat_t;

// Data:12;  [11: 0] Data
// DV:1;     [   15] Data valid
typedef union adc_data {
   uint32_t d32;
   struct {
      uint16_t Data[2];
   } b;
} adc_data_t;

typedef union adc_offset {
   uint32_t d32;
   struct {
      unsigned Off:8;   // [ 7: 0] ADC offset
      unsigned Gain:6;  // [13: 8] ADC gain
      unsigned reserved_14_31:18;
   } b;
} adc_offset_t;

typedef struct adc_cfg_regs {
   volatile adc_cfg_t      cfg           ;   // 8'h00
   volatile adc_en_t       en            ;   // 8'h04
   volatile adc_dmalen_t   dmalen        ;   // 8'h08
   volatile adc_sstart_t   sstart        ;   // 8'h0c
   volatile adc_awd_t      awd[2]        ;   // 8'h10-8'h17
   volatile adc_inten_t    inten         ;   // 8'h18
   volatile adc_intstat_t  intstat       ;   // 8'h1c
   volatile adc_data_t     data[8]       ;   // 8'h20-8'h3f
   volatile adc_offset_t   offset        ;   // 8'h40
   volatile uint32_t       reserved_a [3];   // 8'h44-8'h4f
   volatile uint32_t       addr[4]       ;   // 8'h50-8'h5c
} adc_cfg_regs_t;

typedef union dac_en {
   uint32_t d32;
   struct {
      unsigned En:4;       // [ 3: 0]   DAC channel enable
      unsigned reserved_4_7:4;
      unsigned Enable:1;   // [    8]   DAC enable
      unsigned reserved_9_15:7;
      unsigned CD:10;      // [25:16]   DAC clock divider
      unsigned reserved_26_31:6;
   } b;
} dac_en_t;

typedef struct dac_cfg_regs {
   volatile dac_en_t    en  ;   // 8'h80
   volatile uint32_t    data;   // 8'h84
} dac_cfg_regs_t;


#endif
