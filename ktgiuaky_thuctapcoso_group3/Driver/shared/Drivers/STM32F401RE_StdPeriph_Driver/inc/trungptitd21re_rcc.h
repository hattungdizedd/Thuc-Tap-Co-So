 /* File name:
 *
 * Description:
 *
 *
 * Last Changed By:  $Author: trungptit
 * Revision:         $Revision: 1.1
 * Last Changed:     $Date: 2024
 *
 * Code sample:
 ******************************************************************************/
// Enclosing macro to prevent multiple inclusion
#ifndef __STM32F4xx_RCC_H
#define __STM32F4xx_RCC_H
#ifdef __cplusplus
 extern "C" {
#endif
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "stm32f401re.h"
/******************************************************************************/
/*                     PRIVATE TYPES and DEFINITIONS                         */
/******************************************************************************/


/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/
typedef struct
{
    uint32_t SYSCLK_Frequency; /* SYSCLK clock frequency expressed in Hz */
    uint32_t HCLK_Frequency;   /* HCLK clock frequency expressed in Hz   */
    uint32_t PCLK1_Frequency;  /* PCLK1 clock frequency expressed in Hz  */
    uint32_t PCLK2_Frequency;  /* PCLK2 clock frequency expressed in Hz  */
} RCC_ClocksTypeDef;

/* Exported constants --------------------------------------------------------*/

 /** @defgroup RCC_Exported_Constants
   * @{
   */

 /** @defgroup RCC_HSE_configuration
   * @{
   */
#define RCC_HSE_OFF                      ((uint8_t)0x00)
#define RCC_HSE_ON                       ((uint8_t)0x01)
#define RCC_HSE_Bypass                   ((uint8_t)0x05)
#define IS_RCC_HSE(HSE) (((HSE) == RCC_HSE_OFF) || ((HSE) == RCC_HSE_ON) || ((HSE) == RCC_HSE_Bypass))

 /**
   * @}
   */

 /** @defgroup RCC_LSE_Dual_Mode_Selection
   * @{
   */
#define RCC_LSE_LOWPOWER_MODE	((uint8_t)0x00)
#define RCC_LSE_HIGHDRIVE_MODE	((uint8_t)0x01)
#define IS_RCC_LSE_MODE(MODE)	(((MODE) == RCC_LSE_LOWPOWER_MODE) || ((MODE) == RCC_LSE_HIGHDRIVE_MODE))

/**
  * @}
  */

/** @defgroup RCC_PLLSAIDivR_Factor
  * @{
  */
#define RCC_PLLSAIDivR_Div2				((uint32_t)0x00000000)
#define RCC_PLLSAIDivR_Div4				((uint32_t)0x00010000)
#define RCC_PLLSAIDivR_Div8				((uint32_t)0x00020000)
#define RCC_PLLSAIDivR_Div16			((uint32_t)0x00030000)
#define IS_RCC_PLLSAI_DIVR_VALUE(VALUE)	(((VALUE) == RCC_PLLSAIDivR_Div2) || ((VALUE) == RCC_PLLSAIDivR_Div4) || ((VALUE) == RCC_PLLSAIDivR_Div8) || ((VALUE) == RCC_PLLSAIDivR_Div16))

/**
  * @}
  */

/** @defgroup RCC_PLL_Clock_Source
  * @{
  */
#define RCC_PLLSource_HSI				((uint32_t)0x00000000)
#define RCC_PLLSource_HSE				((uint32_t)0x00400000)
#define IS_RCC_PLL_SOURCE(SOURCE)		(((SOURCE) == RCC_PLLSource_HSI) || ((SOURCE) == RCC_PLLSource_HSE))

#define IS_RCC_PLLM_VALUE(VALUE)		((VALUE) <= 63)
#define IS_RCC_PLLN_VALUE(VALUE)		((50 <= (VALUE)) && ((VALUE) <= 432))
#define IS_RCC_PLLP_VALUE(VALUE)		(((VALUE) == 2) || ((VALUE) == 4) || ((VALUE) == 6) || ((VALUE) == 8))
#define IS_RCC_PLLQ_VALUE(VALUE)		((4 <= (VALUE)) && ((VALUE) <= 15))

#define IS_RCC_PLLI2SN_VALUE(VALUE) ((50 <= (VALUE)) && ((VALUE) <= 432))
#define IS_RCC_PLLI2SR_VALUE(VALUE) ((2 <= (VALUE))  && ((VALUE) <= 7))
#define IS_RCC_PLLI2SM_VALUE(VALUE) ((2 <= (VALUE))  && ((VALUE) <= 63))
#define IS_RCC_PLLI2SQ_VALUE(VALUE) ((2 <= (VALUE))  && ((VALUE) <= 15))

#define IS_RCC_PLLSAIQ_VALUE(VALUE) ((2 <= (VALUE)) && ((VALUE) <= 15))
#define IS_RCC_PLLSAIR_VALUE(VALUE) ((2 <= (VALUE)) && ((VALUE) <= 7))

#define IS_RCC_PLLSAI_DIVQ_VALUE(VALUE) ((1 <= (VALUE)) && ((VALUE) <= 32))
#define IS_RCC_PLLI2S_DIVQ_VALUE(VALUE) ((1 <= (VALUE)) && ((VALUE) <= 32))

/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source
  * @{
  */
#define RCC_SYSCLKSource_HSI             ((uint32_t)0x00000000)
#define RCC_SYSCLKSource_HSE             ((uint32_t)0x00000001)
#define RCC_SYSCLKSource_PLLCLK          ((uint32_t)0x00000002)

/**
  * @}
  */

/** @defgroup RCC_AHB_Clock_Source
  * @{
  */
#define RCC_SYSCLK_Div1                  ((uint32_t)0x00000000)
#define RCC_SYSCLK_Div2                  ((uint32_t)0x00000080)
#define RCC_SYSCLK_Div4                  ((uint32_t)0x00000090)
#define RCC_SYSCLK_Div8                  ((uint32_t)0x000000A0)
#define RCC_SYSCLK_Div16                 ((uint32_t)0x000000B0)
#define RCC_SYSCLK_Div64                 ((uint32_t)0x000000C0)
#define RCC_SYSCLK_Div128                ((uint32_t)0x000000D0)
#define RCC_SYSCLK_Div256                ((uint32_t)0x000000E0)
#define RCC_SYSCLK_Div512                ((uint32_t)0x000000F0)

/**
  * @}
  */

/** @defgroup RCC_APB1_APB2_Clock_Source
  * @{
  */
#define RCC_HCLK_Div1                    ((uint32_t)0x00000000)
#define RCC_HCLK_Div2                    ((uint32_t)0x00001000)
#define RCC_HCLK_Div4                    ((uint32_t)0x00001400)
#define RCC_HCLK_Div8                    ((uint32_t)0x00001800)
#define RCC_HCLK_Div16                   ((uint32_t)0x00001C00)

/**
  * @}
  */

/** @defgroup RCC_Interrupt_Source
  * @{
  */
#define RCC_IT_LSIRDY                    ((uint8_t)0x01)
#define RCC_IT_LSERDY                    ((uint8_t)0x02)
#define RCC_IT_HSIRDY                    ((uint8_t)0x04)
#define RCC_IT_HSERDY                    ((uint8_t)0x08)
#define RCC_IT_PLLRDY                    ((uint8_t)0x10)
#define RCC_IT_PLLI2SRDY                 ((uint8_t)0x20)
#define RCC_IT_PLLSAIRDY                 ((uint8_t)0x40)
#define RCC_IT_CSS                       ((uint8_t)0x80)

#define IS_RCC_IT(IT) ((((IT) & (uint8_t)0x80) == 0x00) && ((IT) != 0x00))
#define IS_RCC_CLEAR_IT(IT)((IT) != 0x00)

/**
  * @}
  */

/** @defgroup RCC_LSE_Configuration
  * @{
  */
#define RCC_LSE_OFF                      ((uint8_t)0x00)
#define RCC_LSE_ON                       ((uint8_t)0x01)
#define RCC_LSE_Bypass                   ((uint8_t)0x04)
/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Source
  * @{
  */
#define RCC_RTCCLKSource_LSE             ((uint32_t)0x00000100)
#define RCC_RTCCLKSource_LSI             ((uint32_t)0x00000200)
#define RCC_RTCCLKSource_HSE_Div2        ((uint32_t)0x00020300)
#define RCC_RTCCLKSource_HSE_Div3        ((uint32_t)0x00030300)
#define RCC_RTCCLKSource_HSE_Div4        ((uint32_t)0x00040300)
#define RCC_RTCCLKSource_HSE_Div5        ((uint32_t)0x00050300)
#define RCC_RTCCLKSource_HSE_Div6        ((uint32_t)0x00060300)
#define RCC_RTCCLKSource_HSE_Div7        ((uint32_t)0x00070300)
#define RCC_RTCCLKSource_HSE_Div8        ((uint32_t)0x00080300)
#define RCC_RTCCLKSource_HSE_Div9        ((uint32_t)0x00090300)
#define RCC_RTCCLKSource_HSE_Div10       ((uint32_t)0x000A0300)
#define RCC_RTCCLKSource_HSE_Div11       ((uint32_t)0x000B0300)
#define RCC_RTCCLKSource_HSE_Div12       ((uint32_t)0x000C0300)
#define RCC_RTCCLKSource_HSE_Div13       ((uint32_t)0x000D0300)
#define RCC_RTCCLKSource_HSE_Div14       ((uint32_t)0x000E0300)
#define RCC_RTCCLKSource_HSE_Div15       ((uint32_t)0x000F0300)
#define RCC_RTCCLKSource_HSE_Div16       ((uint32_t)0x00100300)
#define RCC_RTCCLKSource_HSE_Div17       ((uint32_t)0x00110300)
#define RCC_RTCCLKSource_HSE_Div18       ((uint32_t)0x00120300)
#define RCC_RTCCLKSource_HSE_Div19       ((uint32_t)0x00130300)
#define RCC_RTCCLKSource_HSE_Div20       ((uint32_t)0x00140300)
#define RCC_RTCCLKSource_HSE_Div21       ((uint32_t)0x00150300)
#define RCC_RTCCLKSource_HSE_Div22       ((uint32_t)0x00160300)
#define RCC_RTCCLKSource_HSE_Div23       ((uint32_t)0x00170300)
#define RCC_RTCCLKSource_HSE_Div24       ((uint32_t)0x00180300)
#define RCC_RTCCLKSource_HSE_Div25       ((uint32_t)0x00190300)
#define RCC_RTCCLKSource_HSE_Div26       ((uint32_t)0x001A0300)
#define RCC_RTCCLKSource_HSE_Div27       ((uint32_t)0x001B0300)
#define RCC_RTCCLKSource_HSE_Div28       ((uint32_t)0x001C0300)
#define RCC_RTCCLKSource_HSE_Div29       ((uint32_t)0x001D0300)
#define RCC_RTCCLKSource_HSE_Div30       ((uint32_t)0x001E0300)
#define RCC_RTCCLKSource_HSE_Div31       ((uint32_t)0x001F0300)

/** @defgroup RCC_I2S_Clock_Source
  * @{
  */
#define RCC_I2S2CLKSource_PLLI2S             ((uint8_t)0x00)
#define RCC_I2S2CLKSource_Ext                ((uint8_t)0x01)

/**
  * @}
  */

/** @defgroup RCC_SAI_BlockA_Clock_Source
  * @{
  */
#define RCC_SAIACLKSource_PLLSAI             ((uint32_t)0x00000000)
#define RCC_SAIACLKSource_PLLI2S             ((uint32_t)0x00100000)
#define RCC_SAIACLKSource_Ext                ((uint32_t)0x00200000)

/**
  * @}
  */

/** @defgroup RCC_SAI_BlockB_Clock_Source
  * @{
  */
#define RCC_SAIBCLKSource_PLLSAI             ((uint32_t)0x00000000)
#define RCC_SAIBCLKSource_PLLI2S             ((uint32_t)0x00400000)
#define RCC_SAIBCLKSource_Ext                ((uint32_t)0x00800000)


/** @defgroup RCC_TIM_PRescaler_Selection
  * @{
  */
#define RCC_TIMPrescDesactivated             ((uint8_t)0x00)
#define RCC_TIMPrescActivated                ((uint8_t)0x01)


/** @defgroup RCC_AHB1_Peripherals
  * @{
  */
#define RCC_AHB1Periph_GPIOA             ((uint32_t)0x00000001)
#define RCC_AHB1Periph_GPIOB             ((uint32_t)0x00000002)
#define RCC_AHB1Periph_GPIOC             ((uint32_t)0x00000004)
#define RCC_AHB1Periph_GPIOD             ((uint32_t)0x00000008)
#define RCC_AHB1Periph_GPIOE             ((uint32_t)0x00000010)
#define RCC_AHB1Periph_GPIOF             ((uint32_t)0x00000020)
#define RCC_AHB1Periph_GPIOG             ((uint32_t)0x00000040)
#define RCC_AHB1Periph_GPIOH             ((uint32_t)0x00000080)
#define RCC_AHB1Periph_GPIOI             ((uint32_t)0x00000100)
#define RCC_AHB1Periph_GPIOJ             ((uint32_t)0x00000200)
#define RCC_AHB1Periph_GPIOK             ((uint32_t)0x00000400)
#define RCC_AHB1Periph_CRC               ((uint32_t)0x00001000)
#define RCC_AHB1Periph_FLITF             ((uint32_t)0x00008000)
#define RCC_AHB1Periph_SRAM1             ((uint32_t)0x00010000)
#define RCC_AHB1Periph_SRAM2             ((uint32_t)0x00020000)
#define RCC_AHB1Periph_BKPSRAM           ((uint32_t)0x00040000)
#define RCC_AHB1Periph_SRAM3             ((uint32_t)0x00080000)
#define RCC_AHB1Periph_CCMDATARAMEN      ((uint32_t)0x00100000)
#define RCC_AHB1Periph_DMA1              ((uint32_t)0x00200000)
#define RCC_AHB1Periph_DMA2              ((uint32_t)0x00400000)
#define RCC_AHB1Periph_DMA2D             ((uint32_t)0x00800000)
#define RCC_AHB1Periph_ETH_MAC           ((uint32_t)0x02000000)
#define RCC_AHB1Periph_ETH_MAC_Tx        ((uint32_t)0x04000000)
#define RCC_AHB1Periph_ETH_MAC_Rx        ((uint32_t)0x08000000)
#define RCC_AHB1Periph_ETH_MAC_PTP       ((uint32_t)0x10000000)
#define RCC_AHB1Periph_OTG_HS            ((uint32_t)0x20000000)
#define RCC_AHB1Periph_OTG_HS_ULPI       ((uint32_t)0x40000000)



/**
  * @}
  */

/** @defgroup RCC_AHB2_Peripherals
  * @{
  */
#define RCC_AHB2Periph_OTG_FS            ((uint32_t)0x00000080)

/**
  * @}
  */

/** @defgroup RCC_AHB3_Peripherals
  * @{
  */
/**
  * @}
  */

/** @defgroup RCC_APB1_Peripherals
  * @{
  */
#define RCC_APB1Periph_TIM2              ((uint32_t)0x00000001)
#define RCC_APB1Periph_TIM3              ((uint32_t)0x00000002)
#define RCC_APB1Periph_TIM4              ((uint32_t)0x00000004)
#define RCC_APB1Periph_TIM5              ((uint32_t)0x00000008)
#define RCC_APB1Periph_WWDG              ((uint32_t)0x00000800)
#define RCC_APB1Periph_SPI2              ((uint32_t)0x00004000)
#define RCC_APB1Periph_SPI3              ((uint32_t)0x00008000)
#define RCC_APB1Periph_USART2            ((uint32_t)0x00020000)
#define RCC_APB1Periph_I2C1              ((uint32_t)0x00200000)
#define RCC_APB1Periph_I2C2              ((uint32_t)0x00400000)
#define RCC_APB1Periph_I2C3              ((uint32_t)0x00800000)
#define RCC_APB1Periph_PWR               ((uint32_t)0x10000000)

/**
  * @}
  */

/** @defgroup RCC_APB2_Peripherals
  * @{
  */
#define RCC_APB2Periph_TIM1              ((uint32_t)0x00000001)
#define RCC_APB2Periph_USART1            ((uint32_t)0x00000010)
#define RCC_APB2Periph_USART6            ((uint32_t)0x00000020)
#define RCC_APB2Periph_ADC               ((uint32_t)0x00000100)
#define RCC_APB2Periph_ADC1              ((uint32_t)0x00000100)
#define RCC_APB2Periph_SDIO              ((uint32_t)0x00000800)
#define RCC_APB2Periph_SPI1              ((uint32_t)0x00001000)
#define RCC_APB2Periph_SPI4              ((uint32_t)0x00002000)
#define RCC_APB2Periph_SYSCFG            ((uint32_t)0x00004000)
#define RCC_APB2Periph_EXTIT             ((uint32_t)0x00008000)
#define RCC_APB2Periph_TIM9              ((uint32_t)0x00010000)
#define RCC_APB2Periph_TIM10             ((uint32_t)0x00020000)
#define RCC_APB2Periph_TIM11             ((uint32_t)0x00040000)



/**
  * @}
  */

/** @defgroup RCC_MCO1_Clock_Source_Prescaler
  * @{
  */
#define RCC_MCO1Source_HSI               ((uint32_t)0x00000000)
#define RCC_MCO1Source_LSE               ((uint32_t)0x00200000)
#define RCC_MCO1Source_HSE               ((uint32_t)0x00400000)
#define RCC_MCO1Source_PLLCLK            ((uint32_t)0x00600000)
#define RCC_MCO1Div_1                    ((uint32_t)0x00000000)
#define RCC_MCO1Div_2                    ((uint32_t)0x04000000)
#define RCC_MCO1Div_3                    ((uint32_t)0x05000000)
#define RCC_MCO1Div_4                    ((uint32_t)0x06000000)
#define RCC_MCO1Div_5                    ((uint32_t)0x07000000)

/**
  * @}
  */

/** @defgroup RCC_MCO2_Clock_Source_Prescaler
  * @{
  */
#define RCC_MCO2Source_SYSCLK            ((uint32_t)0x00000000)
#define RCC_MCO2Source_PLLI2SCLK         ((uint32_t)0x40000000)
#define RCC_MCO2Source_HSE               ((uint32_t)0x80000000)
#define RCC_MCO2Source_PLLCLK            ((uint32_t)0xC0000000)
#define RCC_MCO2Div_1                    ((uint32_t)0x00000000)
#define RCC_MCO2Div_2                    ((uint32_t)0x20000000)
#define RCC_MCO2Div_3                    ((uint32_t)0x28000000)
#define RCC_MCO2Div_4                    ((uint32_t)0x30000000)
#define RCC_MCO2Div_5                    ((uint32_t)0x38000000)

/**
  * @}
  */

/** @defgroup RCC_Flag
  * @{
  */
#define RCC_FLAG_HSIRDY                  ((uint8_t)0x21)
#define RCC_FLAG_HSERDY                  ((uint8_t)0x31)
#define RCC_FLAG_PLLRDY                  ((uint8_t)0x39)
#define RCC_FLAG_PLLI2SRDY               ((uint8_t)0x3B)
#define RCC_FLAG_PLLSAIRDY               ((uint8_t)0x3D)
#define RCC_FLAG_LSERDY                  ((uint8_t)0x41)
#define RCC_FLAG_LSIRDY                  ((uint8_t)0x61)
#define RCC_FLAG_BORRST                  ((uint8_t)0x79)
#define RCC_FLAG_PINRST                  ((uint8_t)0x7A)
#define RCC_FLAG_PORRST                  ((uint8_t)0x7B)
#define RCC_FLAG_SFTRST                  ((uint8_t)0x7C)
#define RCC_FLAG_IWDGRST                 ((uint8_t)0x7D)
#define RCC_FLAG_WWDGRST                 ((uint8_t)0x7E)
#define RCC_FLAG_LPWRRST                 ((uint8_t)0x7F)


#define IS_RCC_CALIBRATION_VALUE(VALUE) ((VALUE) <= 0x1F)
/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/

/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/
/* Function used to set the RCC clock configuration to the default reset state */
void        RCC_DeInit(void);

/* Internal/external clocks, PLL, CSS and MCO configuration functions *********/
void 		 RCC_HSEConfig(uint8_t RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void        RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
void        RCC_HSICmd(FunctionalState NewState);
void        RCC_LSEConfig(uint8_t RCC_LSE);
void        RCC_LSICmd(FunctionalState NewState);

void        RCC_PLLCmd(FunctionalState NewState);
void        RCC_PLLI2SCmd(FunctionalState NewState);


void        RCC_PLLSAICmd(FunctionalState NewState);
void        RCC_PLLSAIConfig(uint32_t PLLSAIN, uint32_t PLLSAIQ, uint32_t PLLSAIR);

void        RCC_ClockSecuritySystemCmd(FunctionalState NewState);
void        RCC_MCO1Config(uint32_t RCC_MCO1Source, uint32_t RCC_MCO1Div);
void        RCC_MCO2Config(uint32_t RCC_MCO2Source, uint32_t RCC_MCO2Div);

/* System, AHB and APB busses clocks configuration functions ******************/
void        RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
uint8_t     RCC_GetSYSCLKSource(void);
void        RCC_HCLKConfig(uint32_t RCC_SYSCLK);
void        RCC_PCLK1Config(uint32_t RCC_HCLK);
void        RCC_PCLK2Config(uint32_t RCC_HCLK);
void        RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);

/* Peripheral clocks configuration functions **********************************/
void        RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);
void        RCC_RTCCLKCmd(FunctionalState NewState);
void        RCC_BackupResetCmd(FunctionalState NewState);

void        RCC_SAIPLLI2SClkDivConfig(uint32_t RCC_PLLI2SDivQ);
void        RCC_SAIPLLSAIClkDivConfig(uint32_t RCC_PLLSAIDivQ);

void        RCC_LTDCCLKDivConfig(uint32_t RCC_PLLSAIDivR);
void        RCC_TIMCLKPresConfig(uint32_t RCC_TIMCLKPrescaler);

void        RCC_AHB1PeriphClockCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState);
void        RCC_AHB2PeriphClockCmd(uint32_t RCC_AHB2Periph, FunctionalState NewState);
void        RCC_AHB3PeriphClockCmd(uint32_t RCC_AHB3Periph, FunctionalState NewState);
void        RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void        RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);

void        RCC_AHB1PeriphResetCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState);
void        RCC_AHB2PeriphResetCmd(uint32_t RCC_AHB2Periph, FunctionalState NewState);
void        RCC_AHB3PeriphResetCmd(uint32_t RCC_AHB3Periph, FunctionalState NewState);
void        RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void        RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);

void        RCC_AHB1PeriphClockLPModeCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState);
void        RCC_AHB2PeriphClockLPModeCmd(uint32_t RCC_AHB2Periph, FunctionalState NewState);
void        RCC_AHB3PeriphClockLPModeCmd(uint32_t RCC_AHB3Periph, FunctionalState NewState);
void        RCC_APB1PeriphClockLPModeCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void        RCC_APB2PeriphClockLPModeCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);

void        RCC_LSEModeConfig(uint8_t RCC_Mode);

/* Interrupts and flags management functions **********************************/
void        RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);
FlagStatus  RCC_GetFlagStatus(uint8_t RCC_FLAG);
void        RCC_ClearFlag(void);
ITStatus    RCC_GetITStatus(uint8_t RCC_IT);
void        RCC_ClearITPendingBit(uint8_t RCC_IT);
/******************************************************************************/



#ifdef __cplusplus
}
#endif
#endif /* __STM32F4xx_RCC_H */
/******************************************************************************/
