#include "adc.h"

void ADCCfg(uint16_t ACHEn,  // [31:16]   ACH enable
            uint8_t  Cont,   // [    7]   Continuous mode
            uint8_t  ClkDiv, // [ 6: 4]   Clock divider
            uint8_t  SmpD    // [ 3: 0]   Sample delay
           )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->cfg.b.SmpD   = SmpD  ;
   adc_cfg_regs->cfg.b.ClkDiv = ClkDiv;
   adc_cfg_regs->cfg.b.Cont   = Cont  ;
   adc_cfg_regs->cfg.b.ACHEn  = ACHEn ;
}

void ADCEn(uint8_t  ADCEn     // [   31]   ADC unit enable
          )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->en.b.ADCEn    = ADCEn   ;
}

void ADCTEn(uint8_t  TStartEn // [19:16]   Tigger start enable
           )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->en.b.TStartEn = TStartEn;
}

void ADCChEn(uint16_t ChEn    // [15: 0]   Channel enable
            )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->en.b.ChEn     = ChEn    ;
}

void ADCDMALen(uint8_t Ch,    // channel
               uint8_t DMALen // [ 4: 0]   Number of group (8 samples) to be transfered for channel 0-3 (N+1)
              )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->dmalen.b.dmalen_u[Ch] = DMALen & 0x1f;
}

void ADCFSStart(uint8_t Ch   // channel
               )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->sstart.d32 = (0x1<<Ch) | (0x1<<(16+Ch));
}

void ADCFSStartGroup(uint8_t mask, // [19:16] fast channels software start mask
                     uint8_t FSS   // [ 3: 0] Fast channels software control
                    )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->sstart.d32 = (FSS&0xf) | ((mask&0xf)<<16);
}

void ADCSSStart( uint8_t SSS  // [    4] slow channels software control
               )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->sstart.d32 = ((SSS&0x1)<<4) | (0x1<<20);
}

void ADCAwd(uint8_t  Unit, // AWD unit
            uint8_t  Ch,   // [31:28]   Analog watchdog A channel select
            uint16_t LB,   // [11: 0]   Analog watchdog A lower boundary
            uint16_t UB    // [27:16]   Analog watchdog A upper boundary
           )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->awd[Unit].b.Ch = Ch;
   adc_cfg_regs->awd[Unit].b.LB = LB;
   adc_cfg_regs->awd[Unit].b.UB = UB;
}

void ADCIntEn(ADCIntSel intr // interrupt
             )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->inten.d32 = 0x1<<intr;
}

uint8_t ADCGetIntStat(ADCIntSel intr // interrupt
                     )
{
   uint8_t stat;

   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   stat = (adc_cfg_regs->intstat.d32>>intr) & 0x1;

   return stat;
}

void ADCIntClr(ADCIntSel intr // interrupt
              )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->intstat.d32 = 0x1<<intr;
}

uint16_t ADCGetData(uint8_t Ch // channel
                   )
{
   uint16_t data;

   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   data = adc_cfg_regs->data[Ch/2].b.Data[Ch%2] & 0xfff;

   return data;
}

uint8_t ADCGetDataFlag(uint8_t Ch // channel
                      )
{
   uint8_t stat;

   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   stat = (adc_cfg_regs->data[Ch/2].b.Data[Ch%2]>>15) & 0x1;

   return stat;
}

void ADCDataFlagClr(uint8_t Ch // channel
                   )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->data[Ch/2].b.Data[Ch%2] = (0x1<<15);
}

void ADCOffset(uint8_t Off, // [ 7: 0] ADC offset
               uint8_t Gain // [13: 8] ADC gain
              )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->offset.b.Off  = Off ;
   adc_cfg_regs->offset.b.Gain = Gain;
}

void ADCBase(uint8_t  Ch,  // channel
             uint32_t Addr // address
            )
{
   adc_cfg_regs_t* adc_cfg_regs = (adc_cfg_regs_t*)(ADC_CFG());
   adc_cfg_regs->addr[Ch] = Addr;
}

void DACEn(uint8_t  Enable // [    8]   DAC enable
          )
{
   dac_cfg_regs_t* dac_cfg_regs = (dac_cfg_regs_t*)(DAC_CFG());
   dac_cfg_regs->en.b.Enable = Enable;
}

void DACChEn(uint8_t  En   // [ 3: 0]   DAC channel enable
            )
{
   dac_cfg_regs_t* dac_cfg_regs = (dac_cfg_regs_t*)(DAC_CFG());
   dac_cfg_regs->en.b.En     = En    ;
}

void DACCD(uint16_t CD      // [25:16]   DAC clock divider
          )
{
   dac_cfg_regs_t* dac_cfg_regs = (dac_cfg_regs_t*)(DAC_CFG());
   dac_cfg_regs->en.b.CD     = CD    ;
}

void DACData(uint8_t  Ch,  // [ 3: 0]   DAC channel enable
             uint8_t  Data // [    8]   DAC enable
            )
{
   dac_cfg_regs_t* dac_cfg_regs = (dac_cfg_regs_t*)(DAC_CFG());
   dac_cfg_regs->data = Data<<(Ch*8);
}
