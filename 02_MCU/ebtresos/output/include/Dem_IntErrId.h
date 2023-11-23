/**
*   @file    Dem_IntErrId.h
*   @version 1.0.4
*
*   @brief   AUTOSAR Dem -  module error codes
*   @details This file contains error IDs of the AUTOSAR Dem
*            This file contains sample code only. It is not part of the production code deliverables
*    
*   @addtogroup DEM_MODULE
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
#ifndef DEM_INTERRID_H
#define DEM_INTERRID_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dem_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DEM_INTERRID_VENDOR_ID 43

#define DEM_INTERRID_AR_RELEASE_MAJOR_VERSION       4
#define DEM_INTERRID_AR_RELEASE_MINOR_VERSION       3
#define DEM_INTERRID_AR_RELEASE_REVISION_VERSION    1
#define DEM_INTERRID_SW_MAJOR_VERSION               1
#define DEM_INTERRID_SW_MINOR_VERSION               0
#define DEM_INTERRID_SW_PATCH_VERSION               4

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#if (DEM_INTERRID_VENDOR_ID != DEM_TYPES_VENDOR_ID)
#error "Dem_IntErrid.h and Dem_Types.h have different vendor ids"
#endif

#if ((DEM_INTERRID_AR_RELEASE_MAJOR_VERSION != DEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (DEM_INTERRID_AR_RELEASE_MINOR_VERSION != DEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (DEM_INTERRID_AR_RELEASE_REVISION_VERSION != DEM_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dem_IntErrid.h and Dem_Types.h are different"
#endif

#if ((DEM_INTERRID_SW_MAJOR_VERSION != DEM_TYPES_SW_MAJOR_VERSION) || \
     (DEM_INTERRID_SW_MINOR_VERSION != DEM_TYPES_SW_MINOR_VERSION) || \
     (DEM_INTERRID_SW_PATCH_VERSION != DEM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Dem_IntErrid.h and Dem_Types.h are different"
#endif


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
      
  
/** @brief Identifier for DEM error DemEventParameter_0*/
#define DemConf_DemEventParameter_DemEventParameter_0   ((Dem_EventIdType) 0x1)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif

#endif /* DEM_INTERRID_H */
