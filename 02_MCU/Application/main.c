/*******************************************************************************
 * @author      zdl
 * @brief       AUTOSAR Second  Activity: MCU Module
 * @date        
 * 
 ******************************************************************************/


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "device_registers.h"
#include "clocks_and_modes.h"
#include "system_S32K144.h"
#include "init.h"
#include "Port.h"
#include "Dio.h"
#include "Mcu.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define MAIN_VAR
#define MAIN_CODE
#define NORM_RESET_TYPE TRUE    // MCU Reset Type: TRUE = NORM, FALSE = RAW
#define SW2_STS Dio_ReadChannel( (Dio_ChannelType)DioConf_DioChannel_SW_2 )
#define SW3_STS Dio_ReadChannel( (Dio_ChannelType)DioConf_DioChannel_SW_3 )

typedef enum 
{
    LED_R,
    LED_G,
    LED_B
} led_type;

   
/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
FUNC(void, MAIN_CODE) led_all
(
    VAR(Dio_LevelType, MAIN_VAR) led_state
);
FUNC(void, MAIN_CODE) led_set
(
    VAR(led_type, MAIN_VAR) led_option
);


/*******************************************************************************
 * Code
 ******************************************************************************/
FUNC(void, MAIN_CODE) main( VAR(void, AUTOMATIC) )
{
    // Initialization
    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuClockSettingConfig_0);
    Mcu_InitRamSection(SEC_1);
    Mcu_InitRamSection(SEC_2);
    Port_Init(&Port_Config);
    led_all(STD_HIGH);  // Turn OFF all LEDs

    while (TRUE)
    {
        // Perform Software Reset on SW2
        if (SW2_STS == STD_HIGH)
        {
            Mcu_PerformReset();
        }
        // Perform Watchdog Reset on SW3
        if (SW3_STS == STD_HIGH)
        {
            wdog_init();
        }

#if ( NORM_RESET_TYPE == TRUE )
        // Reset Circumstances
        VAR(Mcu_ResetType, MAIN_VAR) reset_type = Mcu_GetResetReason();

        switch (reset_type)
        {
            case MCU_POWER_ON_RESET:        // Power On Reset
                led_all(STD_LOW);           // White
                break;
            case MCU_SW_RESET:              // Software Reset
                led_set(LED_R);             // Red
                break;
            case MCU_EXTERNAL_PIN_RESET:    // External Pin Reset
                led_set(LED_G);             // Green
                break;
            case MCU_WATCHDOG_RESET:        // Watchdog Reset
                led_set(LED_B);             // Blue
                break;
            default:
                break;
        }
#else // NORM_RESET_TYPE == FALSE (RAW_RESET)
        // Reset Circumstances
        VAR(Mcu_RawResetType, MAIN_VAR) raw_reset_type = Mcu_GetResetRawValue();

        if ( (raw_reset_type & MCU_RAW_RESET_POR) == MCU_RAW_RESET_POR )
        {                               // Power On Reset
            led_all(STD_LOW);           // White
        }
        else if ( (raw_reset_type & MCU_RAW_RESET_SW) == MCU_RAW_RESET_SW )
        {                               // Software Reset
            led_set(LED_R);             // Red
        }
        else if ( (raw_reset_type & MCU_RAW_RESET_PIN) == MCU_RAW_RESET_PIN )
        {                               // External Pin Reset
            led_set(LED_G);             // Green
        }
        else if ( (raw_reset_type & MCU_RAW_RESET_WDOG) == MCU_RAW_RESET_WDOG )
        {                               // Watchdog Reset
            led_set(LED_B);             // Blue
        }
#endif
        
    }
}


FUNC(void, MAIN_CODE) led_all
(
    VAR(Dio_LevelType, MAIN_VAR) led_state
)
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_R, led_state);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_G, led_state);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_B, led_state);
}


FUNC(void, MAIN_CODE) led_set
(
    VAR(led_type, MAIN_VAR) led_option
)
{
    VAR(Dio_LevelType, MAIN_VAR) led_r = STD_HIGH;
    VAR(Dio_LevelType, MAIN_VAR) led_g = STD_HIGH;
    VAR(Dio_LevelType, MAIN_VAR) led_b = STD_HIGH;
    
    switch (led_option)
    {
        case LED_R:
          led_r = STD_LOW;      // LED R ON
          break;
        case LED_G:
          led_g = STD_LOW;      // LED G ON
          break;
        case LED_B:
          led_b = STD_LOW;      // LED B ON
          break;
        default:
          break;
    }
    
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_R, led_r);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_G, led_g);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_B, led_b);
}
