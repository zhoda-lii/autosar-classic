/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "S32K144.h"
#include "init.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
FUNC(void, INIT_CODE) portclocks_init(void)
{
    // Enable clocks for Port A to E
    PCC->PCCn[PCC_PORTA_INDEX] = PCC_PCCn_CGC_MASK;
    PCC->PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK;
    PCC->PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK;
    PCC->PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK;
    PCC->PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK;
}


FUNC(void, INIT_CODE) systick_init
(
    VAR(uint32, INIT_VAR) ticks
)
{
    S32_SysTick->CSR = 0u;
    S32_SysTick->RVR = ticks - 1u;
    S32_SysTick->CVR = 0u;
    S32_SysTick->CSR = S32_SysTick_CSR_ENABLE(1u) |
                       S32_SysTick_CSR_TICKINT(1u) |
                       S32_SysTick_CSR_CLKSOURCE(1u);
}