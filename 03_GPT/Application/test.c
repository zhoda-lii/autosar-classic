/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "test.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

   
/*******************************************************************************
 * Variables
 ******************************************************************************/
extern VAR(uint8, DET_VAR) Det_ErrorId[DET_MAX_NUMBER_OF_EVENTS];
extern VAR(uint8, DET_VAR) Det_RuntimeErrorId[DET_MAX_NUMBER_OF_EVENTS];


/*******************************************************************************
 * Code
 ******************************************************************************/
FUNC(void, TEST_CODE) test_GPT_E_BUSY( VAR(void, AUTOMATIC) )
{
    VAR(uint8, TEST_VAR) actual;
    VAR(uint8, TEST_VAR) expected;
    
    // Function to confirm DET
    Gpt_Init(&Gpt_Config);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GPT_FTM_Config, 62500u);
    Gpt_DeInit();

    // Main confirmation
    actual   = Det_RuntimeErrorId[0];
    expected = GPT_E_BUSY;    // 0x0B
    test_confirm(actual, expected);
}


FUNC(void, TEST_CODE) test_GPT_E_PARAM_MODE( VAR(void, AUTOMATIC) )
{
    VAR(uint8, TEST_VAR) actual;
    VAR(uint8, TEST_VAR) expected;

    // Function to confirm DET
    Gpt_Init(&Gpt_Config);
    Gpt_SetMode((Gpt_ModeType)2u); // Valid Modes are 0 and 1 only

    // Main confirmation
    actual   = Det_ErrorId[0];
    expected = GPT_E_PARAM_MODE;    // 0x1F
    test_confirm(actual, expected);
}


FUNC(void, TEST_CODE) test_GPT_E_PARAM_POINTER( VAR(void, AUTOMATIC) )
{
    VAR(uint8, TEST_VAR) actual;
    VAR(uint8, TEST_VAR) expected;
    
    // Function to confirm DET
    Gpt_Init(&Gpt_Config);
    Gpt_GetVersionInfo(NULL_PTR);

    // Main confirmation
    actual   = Det_ErrorId[0];
    expected = GPT_E_PARAM_POINTER;    // 0x16
    test_confirm(actual, expected);
}


FUNC(void, TEST_CODE) test_GPT_E_PARAM_VALUE( VAR(void, AUTOMATIC) )
{
    VAR(uint8, TEST_VAR) actual;
    VAR(uint8, TEST_VAR) expected;
    
    // Function to confirm DET
    Gpt_Init(&Gpt_Config);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GPT_FTM_Config, -1);

    // Main confirmation
    actual   = Det_ErrorId[0];
    expected = GPT_E_PARAM_VALUE;    // 0x15
    test_confirm(actual, expected);
}


FUNC(void, TEST_CODE) test_GPT_E_PARAM_CHANNEL( VAR(void, AUTOMATIC) )
{
    VAR(uint8, TEST_VAR) actual;
    VAR(uint8, TEST_VAR) expected;
    
    // Function to confirm DET
    Gpt_Init(&Gpt_Config);
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GPT_FTM_Config + 1);

    // Main confirmation
    actual   = Det_ErrorId[0];
    expected = GPT_E_PARAM_CHANNEL;    // 0x14
    test_confirm(actual, expected);
}


FUNC(void, TEST_CODE) test_GPT_E_INIT_FAILED( VAR(void, AUTOMATIC) )
{
    VAR(uint8, TEST_VAR) actual;
    VAR(uint8, TEST_VAR) expected;
    
    // Function to confirm DET
    Gpt_Init(NULL_PTR);

    // Main confirmation
    actual   = Det_ErrorId[0];
    expected = GPT_E_INIT_FAILED;    // 0x0E
    test_confirm(actual, expected);
}


FUNC(void, TEST_CODE) test_GPT_E_ALREADY_INITIALIZED( VAR(void, AUTOMATIC) )
{
    VAR(uint8, TEST_VAR) actual;
    VAR(uint8, TEST_VAR) expected;
    
    // Function to confirm DET
    Gpt_Init(&Gpt_Config);
    Gpt_Init(&Gpt_Config);

    // Main confirmation
    actual   = Det_ErrorId[0];
    expected = GPT_E_ALREADY_INITIALIZED;    // 0x0D
    test_confirm(actual, expected);
}


FUNC(void, TEST_CODE) test_GPT_E_UNINIT( VAR(void, AUTOMATIC) )
{
    VAR(uint8, TEST_VAR) actual;
    VAR(uint8, TEST_VAR) expected;
    
    // Function to confirm DET
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GPT_FTM_Config);

    // Main confirmation
    actual   = Det_ErrorId[0];
    expected = GPT_E_UNINIT;    // 0x0A
    test_confirm(actual, expected);
}


FUNC(void, TEST_CODE) test_GPT_E_PARAM_PREDEF_TIMER( VAR(void, AUTOMATIC) )
{
    VAR(uint8, TEST_VAR) actual;
    VAR(uint8, TEST_VAR) expected;
    VAR(uint32, TEST_VAR) time_value = 0u;
    
    // Function to confirm DET
    Gpt_Init(&Gpt_Config);
    Gpt_GetPredefTimerValue(GPT_PREDEF_TIMER_100US_32BIT + 1, &time_value);

    // Main confirmation
    actual   = Det_ErrorId[0];
    expected = GPT_E_PARAM_PREDEF_TIMER;    // 0x17
    test_confirm(actual, expected);
}


FUNC(void, TEST_CODE) test_GPT_E_MODE( VAR(void, AUTOMATIC) )
{
    VAR(uint8, TEST_VAR) actual;
    VAR(uint8, TEST_VAR) expected;
    VAR(uint32, TEST_VAR) time_value = 0u;
    
    // Function to confirm DET
    Gpt_Init(&Gpt_Config);
    Gpt_SetMode(GPT_MODE_SLEEP);
    Gpt_GetPredefTimerValue(GPT_PREDEF_TIMER_1US_16BIT, &time_value);

    // Main confirmation
    actual   = Det_RuntimeErrorId[0];
    expected = GPT_E_MODE;    // 0x0C
    test_confirm(actual, expected);
}


FUNC(void, TEST_CODE) test_confirm
(
    VAR(uint8, TEST_VAR) t_actual,
    VAR(uint8, TEST_VAR) t_expected
)
{
    if (t_actual == t_expected)
    {
        led_set(LED_G); // Green - Pass
    }
    else
    {
        led_set(LED_R); // Red - Fail
    }
}


FUNC(void, TEST_CODE) led_all
(
    VAR(Dio_LevelType, TEST_VAR) led_state
)
{
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_R, led_state);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_G, led_state);
    Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_LED_B, led_state);
}


FUNC(void, TEST_CODE) led_set
(
    VAR(led_type, TEST_VAR) led_option
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
