/**
*   @file    Gpt_PBcfg.c
*   @version 1.0.4
*   @brief   AUTOSAR Gpt -  GPT driver configuration source file.
*   @details GPT driver source file, containing C and XPath constructs for generating Gpt
*            configuration source file for the Post-build configuration variant.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
*   Dependencies         : none
*
*   Autosar Version      : 4.3.1
*   Autosar Revision     : ASR_REL_4_3_REV_0001
*   Autosar Conf.Variant :
*   SW Version           : 1.0.4
*   Build Version        : S32K1XX_MCAL_1_0_4_RTM_ASR_REL_4_3_REV_0001_04-Apr-22
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2022 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
* @section GPT_PBCFG_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include'. This is an Autosar requirement about
* the memory management.
*
* @section GPT_PBCFG_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. This is an Autosar requirement
* about the memory management.
*
* @section GPT_PBCFG_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_PBCFG_C_REF_4
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The respective code could not be made static because of layers architecture design of the
* driver.
*
* @section GPT_PBCFG_C_REF_5
* Violates MISRA 2004 Required Rule 8.8, an external variable or function should only be declared
* in one file. The variable can not be included in only one file because of the arhitecture of the
* ASR 4.2 driver
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Cfg.h"
#include "Gpt.h"

#if (GPT_LPIT_ENABLE_EXT_TRIGGERS==STD_ON)
#include "Reg_eSys_LPit.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_PBCFG_VENDOR_ID_C                      43
#define GPT_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define GPT_PBCFG_AR_RELEASE_MINOR_VERSION_C       3
/** @violates @ref GPT_PBCFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_PBCFG_AR_RELEASE_REVISION_VERSION_VERSION_C    1
#define GPT_PBCFG_SW_MAJOR_VERSION_C                       1
#define GPT_PBCFG_SW_MINOR_VERSION_C                       0
#define GPT_PBCFG_SW_PATCH_VERSION_C                       4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_PBCFG_VENDOR_ID_C != GPT_VENDOR_ID_CFG)
    #error "Gpt_PBcfg.c and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_PBCFG_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_PBCFG_AR_RELEASE_REVISION_VERSION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Gpt_PBcfg.c and Gpt_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_PBCFG_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_PBCFG_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_PBCFG_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION_CFG)    \
    )
    #error "Software Version Numbers of Gpt_PBcfg.c and Gpt_Cfg.h are different"
#endif

/* Check if Gpt_PBcfg.c file and Gpt.h header file are of the same vendor */
#if (GPT_PBCFG_VENDOR_ID_C != GPT_VENDOR_ID)
    #error "Gpt_PBcfg.c and Gpt.h have different vendor ids"
#endif
/* Check if Gpt_PBcfg.c file and Gpt.h header file are of the same Autosar version */
#if ((GPT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PBCFG_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PBCFG_AR_RELEASE_REVISION_VERSION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_PBcfg.c and Gpt.h are different"
#endif
/* Check if Gpt_PBcfg.c file and Gpt.h header file are of the same Software version */
#if ((GPT_PBCFG_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_PBCFG_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_PBCFG_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_PBcfg.c and Gpt.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (GPT_LPIT_ENABLE_EXT_TRIGGERS==STD_ON)
    /* Check if Gpt_PBcfg.c file and Reg_eSys_LPit.h header file are of the same Autosar version */
        #if ((GPT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_MAJOR_VERSION) || \
             (GPT_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_PBcfg.c and Reg_eSys_LPit.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT_PBCFG_C_REF_1 Only preprocessor statements and comments before '#include' */
/** @violates @ref GPT_PBCFG_C_REF_2 Precautions to prevent the contents of a header file being included twice.*/
#include "Gpt_MemMap.h"
/**
* @{
* @brief The callback functions defined by the user to be called as channel notifications
*/
/** @violates @ref GPT_PBCFG_C_REF_5 External variables and functions should only appear in one file*/
extern void GptNotification_FTM0(void);
/** @} */
#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_PBCFG_C_REF_1 Only preprocessor statements and comments before '#include' */
/** @violates @ref GPT_PBCFG_C_REF_2 Precautions to prevent the contents of a header file being included twice.*/
#include "Gpt_MemMap.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref GPT_PBCFG_C_REF_1 Only preprocessor statements and comments before '#include' */
/** @violates @ref GPT_PBCFG_C_REF_2 Precautions to prevent the contents of a header file being included twice.*/
#include "Gpt_MemMap.h"




#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/* configuration predef timers here */
/** @violates @ref GPT_PBCFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
static CONST(Gpt_HwPredefChannelConfigType, GPT_CONST) Gpt_pInitPredefTimer_1us_16bitPB=
{
    (uint8)(FTM_0_CH_1), /* GPT physical channel no. */
    (uint8)(GPT_FTM_MODULE), /* hardware module ID */
    (boolean)TRUE, /* Freeze Enable */
    (Gpt_PrescalerType)(0U), /* FTM Clock divider */
    (Gpt_ClockSourceType)(3U) /* FTM clock source EXTERNAL_CLOCK*/ 
};

/** @violates @ref GPT_PBCFG_C_REF_4 MISRA 2004 Required Rule 8.10, could be made static */
/** @violates @ref GPT_PBCFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
static CONSTP2CONST(Gpt_HwPredefChannelConfigType, GPT_CONST, GPT_APPL_CONST) Gpt_pInitPredefTimerChannelPB[GPT_HW_PREDEFTIMER_NUM]=
{
    &Gpt_pInitPredefTimer_1us_16bitPB,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};
#endif /*GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON*/

static CONST(Gpt_ChannelConfigType, GPT_CONST) Gpt_InitChannelPB[1] =
{
    {   /*GPT_FTM_Config configuration data*/
        (boolean)FALSE, /* Wakeup capability */
        &GptNotification_FTM0, /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        {
            (uint8)(FTM_0_CH_0), /* GPT physical channel no. */
            (uint8)(GPT_FTM_MODULE), /* hardware module ID */
            (boolean)TRUE, /* Freeze Enable */
            (uint8)(3U), /* FTM clock source */
            (Gpt_PrescalerType)(4U), /* FTM Clock divider */ 
            (uint8)(0U), /* LPTMR Clock divider, LPTMR is not USED */
            (Gpt_PrescalerType)(0U),  /* LPTMR Clock Select, LPTMR is not USED */ 
#if (GPT_SET_CLOCK_MODE == STD_ON)
            (Gpt_PrescalerType)(4U), /* FTM alternate Clock divider */ 
            (Gpt_PrescalerType)(0U), /* LPTMR alternate Clock divider, LPTMR is not USED */ 
#endif /*GPT_SET_CLOCK_MODE == STD_ON*/
            (uint8)(0U),             /* SRTC Clock Select, SRTC is not USED */ 
#if (GPT_LPIT_ENABLE_EXT_TRIGGERS==STD_ON)
            /* LPIT External/Internal Trigger Configuration */
            (uint32)0U,             /* Not used for FTM_0_CH_0 */
#endif
#if (GPT_CHAIN_MODE == STD_ON)

            (boolean)FALSE /* Chain Mode not used for STM, EMIOS, FTM or ETIMER */

#endif
 
        }
    }



};

/*PostBuild configuration structure.*/
/** @violates @ref GPT_PBCFG_C_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static*/
CONST(Gpt_ConfigType, GPT_CONST)  Gpt_Config =
{
    (Gpt_ChannelType)1U,
    &Gpt_InitChannelPB,
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    Gpt_pInitPredefTimerChannelPB,
#endif
    /*Hardware to logic channel mapping.*/
    {
        GptConf_GptChannelConfiguration_GPT_FTM_Config, /*mapping of FTM_0_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of FTM_0_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of FTM_0_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of FTM_0_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of FTM_0_CH_4*/
        GPT_CHN_NOT_USED, /*mapping of FTM_0_CH_5*/
        GPT_CHN_NOT_USED, /*mapping of FTM_0_CH_6*/
        GPT_CHN_NOT_USED, /*mapping of FTM_0_CH_7*/
        GPT_CHN_NOT_USED, /*mapping of FTM_1_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of FTM_1_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of FTM_1_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of FTM_1_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of FTM_1_CH_4*/
        GPT_CHN_NOT_USED, /*mapping of FTM_1_CH_5*/
        GPT_CHN_NOT_USED, /*mapping of FTM_1_CH_6*/
        GPT_CHN_NOT_USED, /*mapping of FTM_1_CH_7*/
        GPT_CHN_NOT_USED, /*mapping of FTM_2_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of FTM_2_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of FTM_2_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of FTM_2_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of FTM_2_CH_4*/
        GPT_CHN_NOT_USED, /*mapping of FTM_2_CH_5*/
        GPT_CHN_NOT_USED, /*mapping of FTM_2_CH_6*/
        GPT_CHN_NOT_USED, /*mapping of FTM_2_CH_7*/
        GPT_CHN_NOT_USED, /*mapping of FTM_3_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of FTM_3_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of FTM_3_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of FTM_3_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of FTM_3_CH_4*/
        GPT_CHN_NOT_USED, /*mapping of FTM_3_CH_5*/
        GPT_CHN_NOT_USED, /*mapping of FTM_3_CH_6*/
        GPT_CHN_NOT_USED, /*mapping of FTM_3_CH_7*/
        GPT_CHN_NOT_USED, /*mapping of LPIT_0_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of LPIT_0_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of LPIT_0_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of LPIT_0_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of LPTMR_0_CH_0*/
        GPT_CHN_NOT_USED /*mapping of SRTC_0_CH_0*/
    }
};


#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref GPT_PBCFG_C_REF_1 Only preprocessor statements and comments before '#include' */
/** @violates @ref GPT_PBCFG_C_REF_2 Precautions to prevent the contents of a header file being included twice.*/
#include "Gpt_MemMap.h"


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
