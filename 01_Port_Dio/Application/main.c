/*******************************************************************************
 * @author      zdl
 * @brief       AUTOSAR First Activity: Port and DIO Modules
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


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define MAIN_VAR
#define MAIN_CODE
#define DURATION_MS 1500u       // Delay duration @ 1.5s
#define SYSCLK 80000000u        // System Clock @ 80MHz
#define BTN1_STS Dio_ReadChannel((Dio_ChannelType)DioConf_DioChannel_SW_2)
#define BTN2_STS Dio_ReadChannel((Dio_ChannelType)DioConf_DioChannel_SW_3)

typedef enum 
{
    LED_R,
    LED_G,
    LED_B
} led_type;

   
/*******************************************************************************
 * Variables
 ******************************************************************************/
__IO VAR(uint16, MAIN_VAR) systick_ctr;
__IO VAR(led_type, MAIN_VAR) current_state;
__IO VAR(led_type, MAIN_VAR) next_state;


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
FUNC(void, MAIN_CODE) led_blink
(
    VAR(led_type, MAIN_VAR) led_option
);
FUNC(void, MAIN_CODE) delay_ms
(
    VAR(uint16, MAIN_VAR) delayticks
);


/*******************************************************************************
 * Code
 ******************************************************************************/
FUNC(void, MAIN_CODE) main(void)
{
    // Initialization
    SOSC_init_8MHz();
    SPLL_init_160MHz();
    NormalRUNmode_80MHz();
    portclocks_init();
    Port_Init(&Port_Config);
    systick_init(SYSCLK / 1000u); // Interrupt every 1ms
    
    // Initialize LED to RED state
    current_state = LED_R;
    led_blink(current_state);
    
    // Wait for Button 1
    while (BTN1_STS == STD_LOW)
    {
    }
    
    // When Button 1 is pressed (no hold), direction R -> G -> B
    while (TRUE)
    {
        do {
            led_blink(current_state);
            delay_ms(DURATION_MS);
        } while (BTN2_STS == STD_HIGH); // Keep as current state when Button 2
        
        current_state = next_state;     // Assign next state
    }
    
}


#pragma default_function_attributes = @ ".flash_blinkled"
FUNC(void, MAIN_CODE) led_blink
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
          next_state = LED_G;   // R -> G
          break;
        case LED_G:
          led_g = STD_LOW;      // LED G ON
          next_state = LED_B;   // G -> B
          break;
        case LED_B:
          led_b = STD_LOW;      // LED B ON
          next_state = LED_R;   // B -> R
          break;
        default:
          break;
    }
    
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_R, led_r);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_G, led_g);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_B, led_b);
}
#pragma default_function_attributes =


FUNC(void, MAIN_CODE) delay_ms
(
    VAR(uint16, MAIN_VAR) delayticks
)
{
    systick_ctr = delayticks;
    while (systick_ctr != 0u)
    {
    }
}


FUNC(void, MAIN_CODE) SysTick_Handler(void)
{
    if (systick_ctr != 0u)
    {
        systick_ctr--;
    }
}