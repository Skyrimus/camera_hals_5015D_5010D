/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/

#include <utils/Log.h>
#include <utils/Errors.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

#include "MediaTypes.h"

//#include "lens_custom_cfg.h"
//#include "msdk_lens_exp.h"
#include "camera_custom_lens.h"
#include "kd_imgsensor.h"

extern PFUNC_GETLENSDEFAULT pDummy_getDefaultData;

#if defined(SENSORDRIVE)
extern PFUNC_GETLENSDEFAULT pSensorDrive_getDefaultData;
#endif
#if defined(FM50AF)
extern PFUNC_GETLENSDEFAULT pFM50AF_getDefaultData;
#endif
#if defined(AD5820AF)
extern PFUNC_GETLENSDEFAULT pAD5820AF_getDefaultData;
#endif

#if defined(DW9714AF)
extern PFUNC_GETLENSDEFAULT pDW9714AF_getDefaultData;
#endif
#if defined(DW9718AF)
extern PFUNC_GETLENSDEFAULT pDW9718AF_getDefaultData;
#endif

#if defined(BU64745GWZAF)
extern PFUNC_GETLENSDEFAULT pBU64745GWZAF_getDefaultData;
#endif

#if defined(LC898122AF)
extern PFUNC_GETLENSDEFAULT pLC898122AF_getDefaultData;
#endif

#if defined(DW9814AF)
extern PFUNC_GETLENSDEFAULT pDW9814AF_getDefaultData;
#endif

extern PFUNC_GETLENSDEFAULT pGAF001AF_getDefaultData;
extern PFUNC_GETLENSDEFAULT pGAF002AF_getDefaultData;
extern PFUNC_GETLENSDEFAULT pGAF008AF_getDefaultData;

//ME14@@undef
#undef AD5820AF




MSDK_LENS_INIT_FUNCTION_STRUCT LensList_main[MAX_NUM_OF_SUPPORT_LENS] =
{
    {DUMMY_SENSOR_ID, DUMMY_LENS_ID, "Dummy", pDummy_getDefaultData},
    #if defined(SENSORDRIVE)
        //{OV3640_SENSOR_ID, SENSOR_DRIVE_LENS_ID, "kd_camera_hw", pSensorDrive_getDefaultData},
    #endif
    #if defined(FM50AF)
        //{DUMMY_SENSOR_ID, FM50AF_LENS_ID, "FM50AF", pFM50AF_getDefaultData},
    #endif
    #if defined(DW9714AF)
        //{IMX135_SENSOR_ID, DW9714AF_LENS_ID, "DW9714AF", pDW9714AF_getDefaultData},
        {IMX179_SENSOR_ID, DW9714AF_LENS_ID, "DW9714AF", pDW9714AF_getDefaultData},
        {IMX219_SENSOR_ID, DW9714AF_LENS_ID, "DW9714AF", pDW9714AF_getDefaultData},
        {OV8858_SENSOR_ID, DW9714AF_LENS_ID, "DW9714AF", pDW9714AF_getDefaultData},
        {S5K4H5YC_SENSOR_ID, DW9714AF_LENS_ID, "DW9714AF", pDW9714AF_getDefaultData},
    #endif
    #if defined(DW9718AF)
        {IMX135_SENSOR_ID, DW9718AF_LENS_ID, "DW9718AF", pDW9718AF_getDefaultData},
    #endif
    #if defined(AD5820AF)
        {OV5648MIPI_SENSOR_ID, AD5820AF_LENS_ID, "AD5820AF", pAD5820AF_getDefaultData},
    #endif
    #if defined(BU64745GWZAF)
        {S5K2P8_SENSOR_ID, BU64745GWZAF_LENS_ID, "BU64745GWZAF", pBU64745GWZAF_getDefaultData},
    #endif
    #if defined(LC898122AF)
        {IMX214_SENSOR_ID, LC898122AF_LENS_ID, "LC898122AF", pLC898122AF_getDefaultData},
    #endif

    #if defined(LC898122AF)
       {IMX215_SENSOR_ID, LC898122AF_LENS_ID, "LC898122AF", pLC898122AF_getDefaultData},
    #endif

    #if defined(DW9814AF)
       {OV5670MIPI_SENSOR_ID, DW9814AF_LENS_ID, "DW9814AF", pDW9814AF_getDefaultData},
    #endif
    {S5K5E8YX_SENSOR_ID, DUMMY_LENS_ID, "Dummy", pDummy_getDefaultData},
    {OV5648MIPI_SENSOR_ID, GAF001AF_LENS_ID, "0x9714", pGAF001AF_getDefaultData},
    //{OV5648MIPI_SENSOR_ID_TRULY, GAF002AF_LENS_ID, "0x9714", pGAF002AF_getDefaultData},

};
MSDK_LENS_INIT_FUNCTION_STRUCT LensList_sub[MAX_NUM_OF_SUPPORT_LENS] =
{
    {DUMMY_SENSOR_ID, DUMMY_LENS_ID, "Dummy", pDummy_getDefaultData},
    #if defined(SENSORDRIVE)
        //{OV3640_SENSOR_ID, SENSOR_DRIVE_LENS_ID, "kd_camera_hw", pSensorDrive_getDefaultData},
    #endif
    #if defined(FM50AF)
        //{DUMMY_SENSOR_ID, FM50AF_LENS_ID, "FM50AF", pFM50AF_getDefaultData},
    #endif
    #if defined(DW9714AF)
        {IMX135_SENSOR_ID, DW9714AF_LENS_ID, "DW9714AF", pDW9714AF_getDefaultData},
    #endif
    #if defined(AD5820AF)
        {OV5648MIPI_SENSOR_ID, AD5820AF_LENS_ID, "AD5820AF", pAD5820AF_getDefaultData},
    #endif
    {C2590MIPI_SENSOR_ID, DUMMY_LENS_ID, "Dummy", pDummy_getDefaultData},


};
MSDK_LENS_INIT_FUNCTION_STRUCT LensList_main2[MAX_NUM_OF_SUPPORT_LENS] =
{
    {DUMMY_SENSOR_ID, DUMMY_LENS_ID, "Dummy", pDummy_getDefaultData},
    #if defined(SENSORDRIVE)
        //{OV3640_SENSOR_ID, SENSOR_DRIVE_LENS_ID, "kd_camera_hw", pSensorDrive_getDefaultData},
    #endif
    #if defined(FM50AF)
        //{DUMMY_SENSOR_ID, FM50AF_LENS_ID, "FM50AF", pFM50AF_getDefaultData},
    #endif
    #if defined(DW9714AF)
        {IMX135_SENSOR_ID, DW9714AF_LENS_ID, "DW9714AF", pDW9714AF_getDefaultData},
    #endif
    #if defined(AD5820AF)
        {OV5648MIPI_SENSOR_ID, AD5820AF_LENS_ID, "AD5820AF", pAD5820AF_getDefaultData},
    #endif
    #if defined(BU64745GWZAF)
        {S5K2P8_SENSOR_ID, BU64745GWZAF_LENS_ID, "BU64745GWZAF", pBU64745GWZAF_getDefaultData},
    #endif
    #if defined(LC898122AF)
        {IMX214_SENSOR_ID, LC898122AF_LENS_ID, "LC898122AF", pLC898122AF_getDefaultData},
    #endif

    #if defined(LC898122AF)
       {IMX215_SENSOR_ID, LC898122AF_LENS_ID, "LC898122AF", pLC898122AF_getDefaultData},
    #endif

    #if defined(DW9814AF)
       {OV5670FFMIPI_SENSOR_ID, DW9814AF_LENS_ID, "DW9814AF", pDW9814AF_getDefaultData},
    #endif

    {OV5648MIPI_SENSOR_ID, GAF001AF_LENS_ID, "0x9714", pGAF001AF_getDefaultData},
    //{OV5648MIPI_SENSOR_ID_TRULY, GAF002AF_LENS_ID, "0x9714", pGAF002AF_getDefaultData},
};



UINT32 GetLensInitFuncList(PMSDK_LENS_INIT_FUNCTION_STRUCT pLensList, unsigned int a_u4CurrSensorDev)
{
    if(a_u4CurrSensorDev==2) //sub
        memcpy(pLensList, &LensList_sub[0], sizeof(MSDK_LENS_INIT_FUNCTION_STRUCT)* MAX_NUM_OF_SUPPORT_LENS);
    else if(a_u4CurrSensorDev==4) //main 2
        memcpy(pLensList, &LensList_main2[0], sizeof(MSDK_LENS_INIT_FUNCTION_STRUCT)* MAX_NUM_OF_SUPPORT_LENS);
    else  // main or others
        memcpy(pLensList, &LensList_main[0], sizeof(MSDK_LENS_INIT_FUNCTION_STRUCT)* MAX_NUM_OF_SUPPORT_LENS);

    return MHAL_NO_ERROR;
}
