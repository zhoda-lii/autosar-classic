/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "S32K144.h"
#include "init.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SW2_PIN     12u
#define SW3_PIN     13u
#define IRQ_RISEDG  9u

#define PTC_PRIO    0u
#define FTM_PRIO    1u


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
FUNC(void, INIT_CODE) NVIC_Init( VAR(void, AUTOMATIC) )
{
    // Generate interrupt on rising edge on Port C
    PORTC->PCR[SW2_PIN] |= PORT_PCR_IRQC(IRQ_RISEDG);
    PORTC->PCR[SW3_PIN] |= PORT_PCR_IRQC(IRQ_RISEDG);
    // Set NVIC Priority
    NVIC_SetPriority(PORTC_IRQn, PTC_PRIO);
    NVIC_SetPriority(FTM0_Ch0_Ch1_IRQn, FTM_PRIO);
}


FUNC(void, INIT_CODE) NVIC_SetPriority(
    VAR(IRQn_Type, AUTOMATIC) IRQn,
    VAR(uint32, AUTOMATIC) priority
)
{
    S32_NVIC->ICPR[IRQn / 32u] = 1 << (IRQn % 32u); // Clear pending register
    S32_NVIC->ISER[IRQn / 32u] = 1 << (IRQn % 32u); // Set enable register
    S32_NVIC->ICPR[IRQn] = (priority << 4u);        // Interrupt prio egister
}