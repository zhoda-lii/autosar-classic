/**
*   @file    EcuM_Cfg.h
*   @version 1.0.4
*
*   @brief   AUTOSAR EcuM - module configuration parameters file
*   @details This file contains the generated configuration parameters for the AUTOSAR EcuM.
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup ECUM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : 
*   Dependencies         : 
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
#ifndef ECUM_CFG_H
#define ECUM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ECUM_CFG_VENDOR_ID 43
#define ECUM_CFG_MODULE_ID 10

#define ECUM_CFG_AR_RELEASE_MAJOR_VERSION 4
#define ECUM_CFG_AR_RELEASE_MINOR_VERSION 3
#define ECUM_CFG_AR_RELEASE_REVISION_VERSION 1
#define ECUM_CFG_SW_MAJOR_VERSION 1
#define ECUM_CFG_SW_MINOR_VERSION 0
#define ECUM_CFG_SW_PATCH_VERSION 4

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
 *                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* ========= user defined wakeup sources ========= */


#if (defined EcuMConf_EcuMWakeupSource_EcuMWakeupSource_0) /* to prevent double declaration */
#error EcuMConf_EcuMWakeupSource_EcuMWakeupSource_0 already defined
#endif
/** @brief Identifier for wakeup source EcuMWakeupSource_0*/
#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_0 ((uint32)((uint32)1U<<0))



/* ======== Sleep modes ======== */


#if (defined EcuMConf_EcuMSleepMode_EcuMSleepMode_0) /* to prevent double declaration */
#error EcuMConf_EcuMSleepMode_EcuMSleepMode_0 already defined
#endif
/** @brief Identifier for wakeup source EcuMSleepMode_0*/
#define EcuMConf_EcuMSleepMode_EcuMSleepMode_0 0x0U


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint32 EcuM_WakeupSourceType; /**< @brief variable type for ECU Manager wakeup sources*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* ECUM_CFG_H */

/** @} */
