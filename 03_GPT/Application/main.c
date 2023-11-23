/*******************************************************************************
 * @author      zdl
 * @brief       AUTOSAR Third Activity: GPT Module
 * @date        
 * @details     v2.0: Added GptPredefTimerFunctionality
 *              v1.0: Initial Release
 * 
 ******************************************************************************/


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "device_registers.h"
#include "clocks_and_modes.h"
#include "system_S32K144.h"

#include "Port.h"
#include "Dio.h"
#include "Mcu.h"
#include "Gpt.h"
#include "Gpt_Ftm.h"

#include "init.h"
#include "test.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define MAIN_CONST
#define MAIN_VAR
#define MAIN_CODE

#define SW2_STS Dio_ReadChannel( (Dio_ChannelType)DioConf_DioChannel_SW_2 )
#define SW3_STS Dio_ReadChannel( (Dio_ChannelType)DioConf_DioChannel_SW_3 )


#define MS_1000     (uint16)(62500u - 1u)   // 1 second = 0 to 999,999 ticks
#define MS_500      (uint16)((MS_1000 / 2u) - 1u)
#define MS_100      (uint16)((MS_1000 / 10u) - 1u)
#define MS_50       (uint16)((MS_100 / 2u) - 1u)
#define MS_10       (uint16)((MS_100 / 10u) - 1u)
#define MS_5        (uint16)((MS_10 / 2u) - 1u)
#define MS_1        (uint16)((MS_10 / 10u) - 1u)

typedef enum
{
    ms_1000,
    ms_500,
    ms_100,
    ms_50,
    ms_10,
    ms_5,
    ms_1
} ms_states;


/*******************************************************************************
 * Variables
 ******************************************************************************/
__IO VAR(sint8, MAIN_VAR) ms_index = (sint8)ms_1000;
__IO VAR(uint16, MAIN_VAR) ticks = MS_1000;
CONST(uint16, MAIN_CONST) ms_state_array[] = {
    MS_1000,
    MS_500,
    MS_100,
    MS_50,
    MS_10,      // Not visible to naked eye
    MS_5,       // Not visible to naked eye
    MS_1        // Not visible to naked eye
};


/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
FUNC(void, MAIN_CODE) main( VAR(void, AUTOMATIC) )
{
    /* Initialization */
    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuClockSettingConfig_0);
    Port_Init(&Port_Config);
    led_all(STD_HIGH);  // Turn OFF all LEDs
    
    /* Test Cases for DET Errors */        // Error Value
    /* Development Error */
    // test_GPT_E_UNINIT();                // 0x0A
    // test_GPT_E_INIT_FAILED();           // 0x0E
    // test_GPT_E_PARAM_CHANNEL();         // 0x14
    // test_GPT_E_PARAM_VALUE();           // 0x15 (0x0D)
    // test_GPT_E_PARAM_POINTER();         // 0x16 (0x0D)
    // test_GPT_E_PARAM_PREDEF_TIMER();    // 0x17 (0x0D)
    // test_GPT_E_PARAM_MODE();            // 0x1F (0x0D)
    // test_GPT_E_ALREADY_INITIALIZED();   // 0x0D
    /* Runtime Error */
    // test_GPT_E_BUSY();                  // 0x0B
    // test_GPT_E_MODE();                  // 0x0C

    /* GPT Notification Implementation */
    Gpt_Init(&Gpt_Config);
    NVIC_Init();
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GPT_FTM_Config);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GPT_FTM_Config, MS_1000);

    while (TRUE)
    {
    }
}


FUNC(void, MAIN_CODE) FTM0_Ch0_Ch1_IRQHandler( VAR(void, AUTOMATIC) )
{
    // Generic ISR Handler, calls the GPT Notification
    Gpt_Ftm_ProcessCommonInterrupt(FTM_0_CH_0);
}


FUNC(void, MAIN_CODE) GptNotification_FTM0( VAR(void, AUTOMATIC) )
{
    // Toggle Blue LED
    Dio_FlipChannel(DioConf_DioChannel_LED_B);
}


FUNC(void, MAIN_CODE) PORTC_IRQHandler( VAR(void, AUTOMATIC) )
{
    if (SW2_STS == STD_HIGH)            // Next duration when SW2
    {
        ms_index++;
        if (ms_index > ms_1)            // Guard to maximum value
        {
            ms_index = ms_1;
        }
    }   
    else if (SW3_STS == STD_HIGH)       // Previous duration when SW3
    {
        ms_index--;
        if (ms_index < ms_1000)         // Guard to minimum value
        {
            ms_index = ms_1000;
        }
    }

    ticks = ms_state_array[ms_index];   // Update ticks

    // Restart GPT
    Gpt_StopTimer(GptConf_GptChannelConfiguration_GPT_FTM_Config);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GPT_FTM_Config, ticks);

    // Clear all Interrupt Status Flag Register on Port C
    PORTC->ISFR = PORT_ISFR_ISF_MASK;
}
