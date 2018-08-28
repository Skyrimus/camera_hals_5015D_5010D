/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#pragma once

/******************************************************************************
 *
 ******************************************************************************/
#include "../dbg_exif_def.h"

namespace dbg_cam_mf_param_2 {
/******************************************************************************
 *
 ******************************************************************************/

// MF debug info
enum { MF_DEBUG_TAG_VERSION = 2 };
enum { MF_DEBUG_TAG_SUBVERSION = 0 };

//MF Parameter Structure
typedef enum
{
    MF_TAG_VERSION = 0,             //sw info. n, for 3.n
    MF_TAG_MFB_MODE,                // 0: disable, 1: MFLL, 2: AIS
    MF_TAG_MAX_FRAME_NUMBER,        // capture number
    MF_TAG_PROCESSING_NUMBER,       // blended number
    MF_TAG_EXPOSURE,
    MF_TAG_ISO,
    MF_TAG_MFNR_ISO_TH,             // threshold to trigger MFNR
    MF_TAG_ISO_HI_TH,               // non-use now
    MF_TAG_ISO_LOW_TH,              // non-use now
    MF_TAG_RAW_WIDTH,
    MF_TAG_RAW_HEIGHT,
    MF_TAG_BSS_ENABLE,
    MF_TAG_BSS_ROI_WIDTH,
    MF_TAG_BSS_ROI_HEIGHT,
    MF_TAG_BSS_ROI_X0,
    MF_TAG_BSS_ROI_Y0,
    MF_TAG_BSS_SCALE_FACTOR,
    MF_TAG_BSS_CLIP_TH0,
    MF_TAG_BSS_CLIP_TH1,
    MF_TAG_BSS_ZERO,
    MF_TAG_BSS_BEST_IDX,            // selected frame
    MF_TAG_GMV_00,                  // Global motion vector frame 0 ~ 11
    MF_TAG_GMV_01,
    MF_TAG_GMV_02,
    MF_TAG_GMV_03,
    MF_TAG_GMV_04,
    MF_TAG_GMV_05,
    MF_TAG_GMV_06,
    MF_TAG_GMV_07,
    MF_TAG_GMV_08,
    MF_TAG_GMV_09,
    MF_TAG_GMV_10,
    MF_TAG_GMV_11,
    MF_TAG_MEMC_WIDTH,
    MF_TAG_MEMC_HEIGHT,
    MF_TAG_MEMC_INPUT_FORMAT,
    MF_TAG_MEMC_OUTPUT_FORMAT,
    MF_TAG_MEMC_SKIP,
    MF_TAG_MEMC_MCFULLSIZE,         // 1: full size MC, 0: quarter size MC
    MF_TAG_MEMC_BAD_MB_COUNT0,
    MF_TAG_MEMC_BAD_MB_COUNT1,
    MF_TAG_MEMC_BAD_MB_COUNT2,
    MF_TAG_MEMC_BAD_MB_TH,
    MF_TAG_MEMC_BAD_MV_RANGE,
    MF_TAG_AIS_EXPOSURE,
    MF_TAG_AIS_ISO,
    MF_TAG_AIS_CALCULATED_EXPOSURE,
    MF_TAG_AIS_CALCULATED_ISO,
    MF_TAG_AIS_EXPOSURE_TH0,
    MF_TAG_AIS_ISO_TH0,
    MF_TAG_AIS_EXPOSURE_TH1,
    MF_TAG_AIS_ADVANCED_ENABLE,
    MF_TAG_AIS_ADVANCED_MAX_EXPOSURE,
    MF_TAG_AIS_ADVANCED_MAX_ISO,

    /* golden YUV */
    MF_TAG_SINGLE_DIP_X_ANR_CON1,
    MF_TAG_SINGLE_DIP_X_ANR_CON2,
    MF_TAG_SINGLE_DIP_X_ANR_YAD1,
    MF_TAG_SINGLE_DIP_X_ANR_YAD2,
    MF_TAG_SINGLE_DIP_X_ANR_Y4LUT1,
    MF_TAG_SINGLE_DIP_X_ANR_Y4LUT2,
    MF_TAG_SINGLE_DIP_X_ANR_Y4LUT3,
    MF_TAG_SINGLE_DIP_X_ANR_C4LUT1,
    MF_TAG_SINGLE_DIP_X_ANR_C4LUT2,
    MF_TAG_SINGLE_DIP_X_ANR_C4LUT3,
    MF_TAG_SINGLE_DIP_X_ANR_A4LUT2,
    MF_TAG_SINGLE_DIP_X_ANR_A4LUT3,
    MF_TAG_SINGLE_DIP_X_ANR_L4LUT1,
    MF_TAG_SINGLE_DIP_X_ANR_L4LUT2,
    MF_TAG_SINGLE_DIP_X_ANR_L4LUT3,
    MF_TAG_SINGLE_DIP_X_ANR_PTY,
    MF_TAG_SINGLE_DIP_X_ANR_CAD,
    MF_TAG_SINGLE_DIP_X_ANR_PTC,
    MF_TAG_SINGLE_DIP_X_ANR_LCE,
    MF_TAG_SINGLE_DIP_X_ANR_MED1,
    MF_TAG_SINGLE_DIP_X_ANR_MED2,
    MF_TAG_SINGLE_DIP_X_ANR_MED3,
    MF_TAG_SINGLE_DIP_X_ANR_MED4,
    MF_TAG_SINGLE_DIP_X_ANR_HP1,
    MF_TAG_SINGLE_DIP_X_ANR_HP2,
    MF_TAG_SINGLE_DIP_X_ANR_HP3,
    MF_TAG_SINGLE_DIP_X_ANR_ACT1,
    MF_TAG_SINGLE_DIP_X_ANR_ACT2,
    MF_TAG_SINGLE_DIP_X_ANR_ACT3,
    MF_TAG_SINGLE_DIP_X_ANR_ACTYH,
    MF_TAG_SINGLE_DIP_X_ANR_ACTC,
    MF_TAG_SINGLE_DIP_X_ANR_ACTYL,
    MF_TAG_SINGLE_DIP_X_ANR_YLAD,
    MF_TAG_SINGLE_DIP_X_ANR_PTYL,
    MF_TAG_SINGLE_DIP_X_ANR_LCOEF,
    MF_TAG_SINGLE_DIP_X_ANR2_CON1,
    MF_TAG_SINGLE_DIP_X_ANR2_CON2,
    MF_TAG_SINGLE_DIP_X_ANR2_YAD1,
    MF_TAG_SINGLE_DIP_X_ANR2_Y4LUT1,
    MF_TAG_SINGLE_DIP_X_ANR2_Y4LUT2,
    MF_TAG_SINGLE_DIP_X_ANR2_Y4LUT3,
    MF_TAG_SINGLE_DIP_X_ANR2_L4LUT1,
    MF_TAG_SINGLE_DIP_X_ANR2_L4LUT2,
    MF_TAG_SINGLE_DIP_X_ANR2_L4LUT3,
    MF_TAG_SINGLE_DIP_X_ANR2_CAD,
    MF_TAG_SINGLE_DIP_X_ANR2_PTC,
    MF_TAG_SINGLE_DIP_X_ANR2_LCE,
    MF_TAG_SINGLE_DIP_X_ANR2_MED1,
    MF_TAG_SINGLE_DIP_X_ANR2_MED2,
    MF_TAG_SINGLE_DIP_X_ANR2_MED3,
    MF_TAG_SINGLE_DIP_X_ANR2_MED4,
    MF_TAG_SINGLE_DIP_X_ANR2_ACTY,
    MF_TAG_SINGLE_DIP_X_ANR2_ACTC,

    /* YUV base (No EE) */
    MF_TAG_BEFORE_DIP_X_UDM_INTP_CRS,
    MF_TAG_BEFORE_DIP_X_UDM_INTP_NAT,
    MF_TAG_BEFORE_DIP_X_UDM_INTP_AUG,
    MF_TAG_BEFORE_DIP_X_UDM_LUMA_LUT1,
    MF_TAG_BEFORE_DIP_X_UDM_LUMA_LUT2,
    MF_TAG_BEFORE_DIP_X_UDM_SL_CTL,
    MF_TAG_BEFORE_DIP_X_UDM_HFTD_CTL,
    MF_TAG_BEFORE_DIP_X_UDM_NR_STR,
    MF_TAG_BEFORE_DIP_X_UDM_NR_ACT,
    MF_TAG_BEFORE_DIP_X_UDM_HF_STR,
    MF_TAG_BEFORE_DIP_X_UDM_HF_ACT1,
    MF_TAG_BEFORE_DIP_X_UDM_HF_ACT2,
    MF_TAG_BEFORE_DIP_X_UDM_CLIP,
    MF_TAG_BEFORE_DIP_X_UDM_DSB,
    MF_TAG_BEFORE_DIP_X_UDM_TILE_EDGE,
    MF_TAG_BEFORE_DIP_X_UDM_DSL,
    MF_TAG_BEFORE_DIP_X_UDM_SPARE_1,
    MF_TAG_BEFORE_DIP_X_UDM_SPARE_2,
    MF_TAG_BEFORE_DIP_X_UDM_SPARE_3,
    MF_TAG_BEFORE_DIP_X_ANR_CON1,
    MF_TAG_BEFORE_DIP_X_ANR_CON2,
    MF_TAG_BEFORE_DIP_X_ANR_YAD1,
    MF_TAG_BEFORE_DIP_X_ANR_YAD2,
    MF_TAG_BEFORE_DIP_X_ANR_Y4LUT1,
    MF_TAG_BEFORE_DIP_X_ANR_Y4LUT2,
    MF_TAG_BEFORE_DIP_X_ANR_Y4LUT3,
    MF_TAG_BEFORE_DIP_X_ANR_C4LUT1,
    MF_TAG_BEFORE_DIP_X_ANR_C4LUT2,
    MF_TAG_BEFORE_DIP_X_ANR_C4LUT3,
    MF_TAG_BEFORE_DIP_X_ANR_A4LUT2,
    MF_TAG_BEFORE_DIP_X_ANR_A4LUT3,
    MF_TAG_BEFORE_DIP_X_ANR_L4LUT1,
    MF_TAG_BEFORE_DIP_X_ANR_L4LUT2,
    MF_TAG_BEFORE_DIP_X_ANR_L4LUT3,
    MF_TAG_BEFORE_DIP_X_ANR_PTY,
    MF_TAG_BEFORE_DIP_X_ANR_CAD,
    MF_TAG_BEFORE_DIP_X_ANR_PTC,
    MF_TAG_BEFORE_DIP_X_ANR_LCE,
    MF_TAG_BEFORE_DIP_X_ANR_MED1,
    MF_TAG_BEFORE_DIP_X_ANR_MED2,
    MF_TAG_BEFORE_DIP_X_ANR_MED3,
    MF_TAG_BEFORE_DIP_X_ANR_MED4,
    MF_TAG_BEFORE_DIP_X_ANR_HP1,
    MF_TAG_BEFORE_DIP_X_ANR_HP2,
    MF_TAG_BEFORE_DIP_X_ANR_HP3,
    MF_TAG_BEFORE_DIP_X_ANR_ACT1,
    MF_TAG_BEFORE_DIP_X_ANR_ACT2,
    MF_TAG_BEFORE_DIP_X_ANR_ACT3,
    MF_TAG_BEFORE_DIP_X_ANR_ACTYH,
    MF_TAG_BEFORE_DIP_X_ANR_ACTC,
    MF_TAG_BEFORE_DIP_X_ANR_ACTYL,
    MF_TAG_BEFORE_DIP_X_ANR_YLAD,
    MF_TAG_BEFORE_DIP_X_ANR_PTYL,
    MF_TAG_BEFORE_DIP_X_ANR_LCOEF,
    MF_TAG_BEFORE_DIP_X_ANR2_CON1,
    MF_TAG_BEFORE_DIP_X_ANR2_CON2,
    MF_TAG_BEFORE_DIP_X_ANR2_YAD1,
    MF_TAG_BEFORE_DIP_X_ANR2_Y4LUT1,
    MF_TAG_BEFORE_DIP_X_ANR2_Y4LUT2,
    MF_TAG_BEFORE_DIP_X_ANR2_Y4LUT3,
    MF_TAG_BEFORE_DIP_X_ANR2_L4LUT1,
    MF_TAG_BEFORE_DIP_X_ANR2_L4LUT2,
    MF_TAG_BEFORE_DIP_X_ANR2_L4LUT3,
    MF_TAG_BEFORE_DIP_X_ANR2_CAD,
    MF_TAG_BEFORE_DIP_X_ANR2_PTC,
    MF_TAG_BEFORE_DIP_X_ANR2_LCE,
    MF_TAG_BEFORE_DIP_X_ANR2_MED1,
    MF_TAG_BEFORE_DIP_X_ANR2_MED2,
    MF_TAG_BEFORE_DIP_X_ANR2_MED3,
    MF_TAG_BEFORE_DIP_X_ANR2_MED4,
    MF_TAG_BEFORE_DIP_X_ANR2_ACTY,
    MF_TAG_BEFORE_DIP_X_ANR2_ACTC,
    MF_TAG_BEFORE_DIP_X_SEEE_CTRL,
    MF_TAG_BEFORE_DIP_X_SEEE_CLIP_CTRL_1,
    MF_TAG_BEFORE_DIP_X_SEEE_CLIP_CTRL_2,
    MF_TAG_BEFORE_DIP_X_SEEE_CLIP_CTRL_3,
    MF_TAG_BEFORE_DIP_X_SEEE_BLND_CTRL_1,
    MF_TAG_BEFORE_DIP_X_SEEE_BLND_CTRL_2,
    MF_TAG_BEFORE_DIP_X_SEEE_GN_CTRL,
    MF_TAG_BEFORE_DIP_X_SEEE_LUMA_CTRL_1,
    MF_TAG_BEFORE_DIP_X_SEEE_LUMA_CTRL_2,
    MF_TAG_BEFORE_DIP_X_SEEE_LUMA_CTRL_3,
    MF_TAG_BEFORE_DIP_X_SEEE_LUMA_CTRL_4,
    MF_TAG_BEFORE_DIP_X_SEEE_SLNK_CTRL_1,
    MF_TAG_BEFORE_DIP_X_SEEE_SLNK_CTRL_2,
    MF_TAG_BEFORE_DIP_X_SEEE_GLUT_CTRL_1,
    MF_TAG_BEFORE_DIP_X_SEEE_GLUT_CTRL_2,
    MF_TAG_BEFORE_DIP_X_SEEE_GLUT_CTRL_3,
    MF_TAG_BEFORE_DIP_X_SEEE_GLUT_CTRL_4,
    MF_TAG_BEFORE_DIP_X_SEEE_GLUT_CTRL_5,
    MF_TAG_BEFORE_DIP_X_SEEE_GLUT_CTRL_6,
    MF_TAG_BEFORE_DIP_X_SEEE_OUT_EDGE_CTRL,
    MF_TAG_BEFORE_DIP_X_SEEE_SE_Y_CTRL,
    MF_TAG_BEFORE_DIP_X_SEEE_SE_EDGE_CTRL_1,
    MF_TAG_BEFORE_DIP_X_SEEE_SE_EDGE_CTRL_2,
    MF_TAG_BEFORE_DIP_X_SEEE_SE_EDGE_CTRL_3,
    MF_TAG_BEFORE_DIP_X_SEEE_SE_SPECL_CTRL,
    MF_TAG_BEFORE_DIP_X_SEEE_SE_CORE_CTRL_1,
    MF_TAG_BEFORE_DIP_X_SEEE_SE_CORE_CTRL_2,

    /* mix */
    MF_TAG_AFTER_DIP_X_ANR_CON1,
    MF_TAG_AFTER_DIP_X_ANR_CON2,
    MF_TAG_AFTER_DIP_X_ANR_YAD1,
    MF_TAG_AFTER_DIP_X_ANR_YAD2,
    MF_TAG_AFTER_DIP_X_ANR_Y4LUT1,
    MF_TAG_AFTER_DIP_X_ANR_Y4LUT2,
    MF_TAG_AFTER_DIP_X_ANR_Y4LUT3,
    MF_TAG_AFTER_DIP_X_ANR_C4LUT1,
    MF_TAG_AFTER_DIP_X_ANR_C4LUT2,
    MF_TAG_AFTER_DIP_X_ANR_C4LUT3,
    MF_TAG_AFTER_DIP_X_ANR_A4LUT2,
    MF_TAG_AFTER_DIP_X_ANR_A4LUT3,
    MF_TAG_AFTER_DIP_X_ANR_L4LUT1,
    MF_TAG_AFTER_DIP_X_ANR_L4LUT2,
    MF_TAG_AFTER_DIP_X_ANR_L4LUT3,
    MF_TAG_AFTER_DIP_X_ANR_PTY,
    MF_TAG_AFTER_DIP_X_ANR_CAD,
    MF_TAG_AFTER_DIP_X_ANR_PTC,
    MF_TAG_AFTER_DIP_X_ANR_LCE,
    MF_TAG_AFTER_DIP_X_ANR_MED1,
    MF_TAG_AFTER_DIP_X_ANR_MED2,
    MF_TAG_AFTER_DIP_X_ANR_MED3,
    MF_TAG_AFTER_DIP_X_ANR_MED4,
    MF_TAG_AFTER_DIP_X_ANR_HP1,
    MF_TAG_AFTER_DIP_X_ANR_HP2,
    MF_TAG_AFTER_DIP_X_ANR_HP3,
    MF_TAG_AFTER_DIP_X_ANR_ACT1,
    MF_TAG_AFTER_DIP_X_ANR_ACT2,
    MF_TAG_AFTER_DIP_X_ANR_ACT3,
    MF_TAG_AFTER_DIP_X_ANR_ACTYH,
    MF_TAG_AFTER_DIP_X_ANR_ACTC,
    MF_TAG_AFTER_DIP_X_ANR_ACTYL,
    MF_TAG_AFTER_DIP_X_ANR_YLAD,
    MF_TAG_AFTER_DIP_X_ANR_PTYL,
    MF_TAG_AFTER_DIP_X_ANR_LCOEF,
    MF_TAG_AFTER_DIP_X_ANR2_CON1,
    MF_TAG_AFTER_DIP_X_ANR2_CON2,
    MF_TAG_AFTER_DIP_X_ANR2_YAD1,
    MF_TAG_AFTER_DIP_X_ANR2_Y4LUT1,
    MF_TAG_AFTER_DIP_X_ANR2_Y4LUT2,
    MF_TAG_AFTER_DIP_X_ANR2_Y4LUT3,
    MF_TAG_AFTER_DIP_X_ANR2_L4LUT1,
    MF_TAG_AFTER_DIP_X_ANR2_L4LUT2,
    MF_TAG_AFTER_DIP_X_ANR2_L4LUT3,
    MF_TAG_AFTER_DIP_X_ANR2_CAD,
    MF_TAG_AFTER_DIP_X_ANR2_PTC,
    MF_TAG_AFTER_DIP_X_ANR2_LCE,
    MF_TAG_AFTER_DIP_X_ANR2_MED1,
    MF_TAG_AFTER_DIP_X_ANR2_MED2,
    MF_TAG_AFTER_DIP_X_ANR2_MED3,
    MF_TAG_AFTER_DIP_X_ANR2_MED4,
    MF_TAG_AFTER_DIP_X_ANR2_ACTY,
    MF_TAG_AFTER_DIP_X_ANR2_ACTC,
    MF_TAG_AFTER_DIP_X_SEEE_CTRL,
    MF_TAG_AFTER_DIP_X_SEEE_CLIP_CTRL_1,
    MF_TAG_AFTER_DIP_X_SEEE_CLIP_CTRL_2,
    MF_TAG_AFTER_DIP_X_SEEE_CLIP_CTRL_3,
    MF_TAG_AFTER_DIP_X_SEEE_BLND_CTRL_1,
    MF_TAG_AFTER_DIP_X_SEEE_BLND_CTRL_2,
    MF_TAG_AFTER_DIP_X_SEEE_GN_CTRL,
    MF_TAG_AFTER_DIP_X_SEEE_LUMA_CTRL_1,
    MF_TAG_AFTER_DIP_X_SEEE_LUMA_CTRL_2,
    MF_TAG_AFTER_DIP_X_SEEE_LUMA_CTRL_3,
    MF_TAG_AFTER_DIP_X_SEEE_LUMA_CTRL_4,
    MF_TAG_AFTER_DIP_X_SEEE_SLNK_CTRL_1,
    MF_TAG_AFTER_DIP_X_SEEE_SLNK_CTRL_2,
    MF_TAG_AFTER_DIP_X_SEEE_GLUT_CTRL_1,
    MF_TAG_AFTER_DIP_X_SEEE_GLUT_CTRL_2,
    MF_TAG_AFTER_DIP_X_SEEE_GLUT_CTRL_3,
    MF_TAG_AFTER_DIP_X_SEEE_GLUT_CTRL_4,
    MF_TAG_AFTER_DIP_X_SEEE_GLUT_CTRL_5,
    MF_TAG_AFTER_DIP_X_SEEE_GLUT_CTRL_6,
    MF_TAG_AFTER_DIP_X_SEEE_OUT_EDGE_CTRL,
    MF_TAG_AFTER_DIP_X_SEEE_SE_Y_CTRL,
    MF_TAG_AFTER_DIP_X_SEEE_SE_EDGE_CTRL_1,
    MF_TAG_AFTER_DIP_X_SEEE_SE_EDGE_CTRL_2,
    MF_TAG_AFTER_DIP_X_SEEE_SE_EDGE_CTRL_3,
    MF_TAG_AFTER_DIP_X_SEEE_SE_SPECL_CTRL,
    MF_TAG_AFTER_DIP_X_SEEE_SE_CORE_CTRL_1,
    MF_TAG_AFTER_DIP_X_SEEE_SE_CORE_CTRL_2,
    MF_TAG_AFTER_DIP_X_MIX3_CTRL_0,
    MF_TAG_AFTER_DIP_X_MIX3_CTRL_1,
    MF_TAG_AFTER_DIP_X_MIX3_SPARE,

    /* blending */
    MF_TAG_BLEND_DIP_X_MFB_CON,
    MF_TAG_BLEND_DIP_X_MFB_LL_CON1,
    MF_TAG_BLEND_DIP_X_MFB_LL_CON2,
    MF_TAG_BLEND_DIP_X_MFB_LL_CON4,

    /* image */
    MF_TAG_IMAGE_HDR,

    /* indicates to size */
    MF_DEBUG_TAG_SIZE,
} DEBUG_MF_TAG_T;

typedef struct DEBUG_MF_INFO_S
{
    debug_exif_field Tag[MF_DEBUG_TAG_SIZE];
} DEBUG_MF_INFO_T;


/******************************************************************************
 *
 ******************************************************************************/
};  //namespace

