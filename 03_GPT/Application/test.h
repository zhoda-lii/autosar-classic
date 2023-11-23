#ifndef TEST_H_
#define TEST_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Dio.h"
#include "Gpt.h"
#include "Gpt_Cfg.h"
#include "Det.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TEST_VAR
#define TEST_CODE

typedef enum 
{
    LED_R,
    LED_G,
    LED_B
} led_type;


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
// Test Functions for Development Errors
FUNC(void, TEST_CODE) test_GPT_E_UNINIT( VAR(void, AUTOMATIC) );
FUNC(void, TEST_CODE) test_GPT_E_ALREADY_INITIALIZED( VAR(void, AUTOMATIC) );
FUNC(void, TEST_CODE) test_GPT_E_INIT_FAILED( VAR(void, AUTOMATIC) );
FUNC(void, TEST_CODE) test_GPT_E_PARAM_CHANNEL( VAR(void, AUTOMATIC) );
FUNC(void, TEST_CODE) test_GPT_E_PARAM_VALUE( VAR(void, AUTOMATIC) );
FUNC(void, TEST_CODE) test_GPT_E_PARAM_POINTER( VAR(void, AUTOMATIC) );
FUNC(void, TEST_CODE) test_GPT_E_PARAM_MODE( VAR(void, AUTOMATIC) );
FUNC(void, TEST_CODE) test_GPT_E_PARAM_PREDEF_TIMER( VAR(void, AUTOMATIC) );
// Test Functions for Runtime Errors
FUNC(void, TEST_CODE) test_GPT_E_BUSY( VAR(void, AUTOMATIC) );
FUNC(void, TEST_CODE) test_GPT_E_MODE( VAR(void, AUTOMATIC) );

FUNC(void, TEST_CODE) test_confirm
(
    VAR(uint8, TEST_VAR) t_actual,
    VAR(uint8, TEST_VAR) t_expected
);

FUNC(void, TEST_CODE) led_set
(
    VAR(led_type, TEST_VAR) led_option
);
FUNC(void, TEST_CODE) led_all
(
    VAR(Dio_LevelType, TEST_VAR) led_state
);

#endif /* TEST_H_ */