/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "S32K144.h"
#include "init.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define WDOG_UNLOCK 0xD928C520
#define WDOG_TOVAL ( ( 128000u / 256u ) * 1u )  // WDOG_FREQ = LPO_FREQ / PRES
                                                // TOVAL = WDOG_FREQ x 1s


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
FUNC(void, INIT_CODE) wdog_init( VAR(void, AUTOMATIC) )
{
    WDOG->CNT = WDOG_UNLOCK;         // Unlock Watchdog
    WDOG->TOVAL = WDOG_TOVAL;        // Set timeout value @ 1s
    WDOG->CS = WDOG_CS_EN(1u)        // Enable Watchdog
             | WDOG_CS_CLK(1u)       // Clock source LPO @ 128kHz
             | WDOG_CS_PRES(1u)      // Enable 256 Prescaler
             | WDOG_CS_UPDATE(0u);   // Disable Update (Write-Once)

    while (TRUE)                     // Wait until config is successful
    {
    }
}
