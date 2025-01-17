;/*
; *-----------------------------------------------------------------------------
; * The confidential and proprietary information contained in this file may
; * only be used by a person authorised under and to the extent permitted
; * by a subsisting licensing agreement from ARM Limited.
; *
; *            (C) COPYRIGHT 2010-2011 ARM Limited.
; *                ALL RIGHTS RESERVED
; *
; * This entire notice must be reproduced on all copies of this file
; * and copies of this file may only be made by a person if such person is
; * permitted to do so under the terms of a subsisting license agreement
; * from ARM Limited.
; *
; *      SVN Information
; *
; *      Checked In          : $Date: 2011-03-17 11:25:01 +0000 (Thu, 17 Mar 2011) $
; *
; *      Revision            : $Revision: 164919 $
; *
; *      Release Information : BP200-r0p0-00rel0
; *-----------------------------------------------------------------------------
; */

;/*****************************************************************************/
;/* Startup.s: Startup file for ARM Cortex-M0 Device Family                   */
;/*****************************************************************************/

AP_INIT_SP		EQU		0x01004000

;// <h> Stack Configuration
;//   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
;// </h>

Stack_Size      EQU     0x01000

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


;// <h> Heap Configuration
;//   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
;// </h>

Heap_Size       EQU     0x400

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     AP_INIT_SP                ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler
				
          
				DCD     0           
                DCD     0          
                DCD     SARADC_Handler           
                DCD     SPIFLASH_Handler          
                DCD     UART_Handler          
                DCD     PDM_Handler           		; PDM Handler
                DCD     GPIO1_Handler        		; GPIO Port 0 Combined Handler
                DCD     GPIO2_Handler        		; GPIO Port 1 Combined Handler
                DCD     TIMER_Handler            	; TIMER  handler
                DCD     SDMAC_Handler            	; SDMAC 1 handler
                DCD     SDIF0_DriverIRQHandler
                DCD     IIR_Handler      
                DCD     SDIF1_DriverIRQHandler          
                DCD     USB_OTG_FS_ISR_Handler          
                DCD     USB_OTG_HS_ISR_Handler         
                DCD     CXC_Handler               
                DCD    	ADMAC_Handler           
                DCD     SPDIF_Handler         
                DCD     PCM_Handler           
                DCD     IIS_Handler         
                DCD     RTC_Handler         
                DCD     PMU_Handler           
                DCD     DMAC_Handler        
	            SPACE   9*4							;9 no use interrupt
					
                SPACE	(256-16-32)*4				;16 m0 exception, 32 interrupt
RISC_VECTOR		DCD		0x02180100
				SPACE   1020;risc reset vectors, 1KB
DSP_VECTOR      DCD     0xF03DF03D
				DCD     0x0000A232
				DCD     0xA4321143
				DCD     0x11334000
				DCD     0x04A0443A
				DCD     0x00F03D00
				SPACE   1000
				;INCBIN   dsp_reset.bin

__Vectors_End

__Vectors_Size         EQU     __Vectors_End - __Vectors
                AREA    |.text|, CODE, READONLY


; Reset Handler
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  __main
                IMPORT  SystemInit				
				
				LDR     R0, =SystemInit
                BLX     R0
				LDR		R1, =__initial_sp
				MSR		MSP, R1
				LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
               EXPORT  SysTick_Handler            [WEAK]
               B       .
               ENDP
Default_Handler PROC


                EXPORT SARADC_Handler            	[WEAK]
                EXPORT ECAP_EQEP_Handler            [WEAK]
                EXPORT EPWM_Handler            		[WEAK]
                EXPORT SPIFLASH_Handler            	[WEAK]
                EXPORT UART_Handler            		[WEAK]
                EXPORT PDM_Handler           		[WEAK]
                EXPORT GPIO1_Handler        		[WEAK]
                EXPORT GPIO2_Handler        		[WEAK]
                EXPORT TIMER_Handler          		[WEAK]
                EXPORT SDMAC_Handler           		[WEAK]
                EXPORT SDIF0_DriverIRQHandler       [WEAK]
                EXPORT IIR_Handler                  [WEAK]
                EXPORT SDIF1_DriverIRQHandler       [WEAK]
                EXPORT USB_OTG_FS_ISR_Handler       [WEAK]
				EXPORT USB_OTG_HS_ISR_Handler       [WEAK]
                EXPORT CXC_Handler                	[WEAK]
                EXPORT ADMAC_Handler           		[WEAK]
                EXPORT SPDIF_Handler            	[WEAK]
                EXPORT PCM_Handler            		[WEAK]
                EXPORT IIS_Handler            		[WEAK]
                EXPORT RTC_Handler            		[WEAK]
                EXPORT PMU_Handler                  [WEAK]
                EXPORT DMAC_Handler            		[WEAK]
				
SARADC_Handler
ECAP_EQEP_Handler
EPWM_Handler
SPIFLASH_Handler
UART_Handler
PDM_Handler
GPIO1_Handler
GPIO2_Handler
TIMER_Handler
SDMAC_Handler
SDIF0_DriverIRQHandler
IIR_Handler
SDIF1_DriverIRQHandler
USB_OTG_FS_ISR_Handler
USB_OTG_HS_ISR_Handler
CXC_Handler
ADMAC_Handler
SPDIF_Handler
PCM_Handler
IIS_Handler
RTC_Handler
PMU_Handler
DMAC_Handler

               B       .
               ENDP

                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END

