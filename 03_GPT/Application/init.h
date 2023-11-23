#ifndef INIT_H_
#define INIT_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Std_Types.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define INIT_VAR
#define INIT_CODE


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
FUNC(void, INIT_CODE) NVIC_Init( VAR(void, AUTOMATIC) );
FUNC(void, INIT_CODE) NVIC_SetPriority(
    VAR(IRQn_Type, AUTOMATIC) IRQn,
    VAR(uint32, AUTOMATIC) priority
);

#endif /* INIT_H_ */
