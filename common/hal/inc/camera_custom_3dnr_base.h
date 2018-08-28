/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2017. All rights reserved.
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
#ifndef _3DNR_CUSTOM_BASE_H_
#define _3DNR_CUSTOM_BASE_H_

#include <cutils/properties.h>

typedef int           MINT32;
typedef unsigned char MUINT8;
typedef unsigned int  MUINT32;
typedef float         MFLOAT;
typedef int           MBOOL;

enum NR3D_MODE
{
    NR3D_MODE_OFF = 0,
    NR3D_MODE_3DNR_10,
    NR3D_MODE_3DNR_20,
    NR3D_MODE_3DNR_30,
    NR3D_MODE_3DNR_40,
};

#define NR3D_MODE_ENABLE_3DNR_10(x)           (x)|=(1<<NR3D_MODE_3DNR_10)
#define NR3D_MODE_IS_3DNR_10_ENABLED(x)       ((x& (1<<NR3D_MODE_3DNR_10))?true:false)

#define NR3D_MODE_ENABLE_3DNR_20(x)           (x)|=(1<<NR3D_MODE_3DNR_20)
#define NR3D_MODE_IS_3DNR_20_ENABLED(x)       ((x& (1<<NR3D_MODE_3DNR_20))?true:false)

#define NR3D_MODE_ENABLE_3DNR_30(x)           (x)|=(1<<NR3D_MODE_3DNR_30)
#define NR3D_MODE_IS_3DNR_30_ENABLED(x)       ((x& (1<<NR3D_MODE_3DNR_30))?true:false)

#define NR3D_MODE_ENABLE_3DNR_40(x)           (x)|=(1<<NR3D_MODE_3DNR_40)
#define NR3D_MODE_IS_3DNR_40_ENABLED(x)       ((x& (1<<NR3D_MODE_3DNR_40))?true:false)

// ISO value must higher then threshold to turn on 3DNR
#define DEFAULT_NR3D_OFF_ISO_THRESHOLD          400

// gmv ConfThreshold
#define NR3D_GMVX_CONF_LOW_THRESHOLD              20
#define NR3D_GMVX_CONF_HIGH_THRESHOLD             30

#define NR3D_GMVY_CONF_LOW_THRESHOLD              20
#define NR3D_GMVY_CONF_HIGH_THRESHOLD             30


class NR3DCustomBase
{
protected:
    // DO NOT create instance
    NR3DCustomBase()
    {
    }

public:
    /* Get 3DNR Mode
     */
    static MUINT32 get3DNRMode(MUINT32 mask)
    {
        (void)mask;
        return NR3D_MODE_OFF;
    }

    /* EIS version support
     */
    static MBOOL isEnabled3DNR10()
    {
        return false;
    }

    static MBOOL isEnabled3DNR20()
    {
        return false;
    }

    static MBOOL isEnabled3DNR30()
    {
        return false;
    }

    static MBOOL isEnabled3DNR40()
    {
        return false;
    }

    static MINT32 get_3dnr_off_iso_threshold(MUINT8 ispProfile = 0, MBOOL useAdbValue = 0)
    {
        (void)ispProfile; // unused
        (void)useAdbValue; // unused
        return DEFAULT_NR3D_OFF_ISO_THRESHOLD;
    }

    // === algo related ===
    // return value: 0 (no adjustment), 1 (adjusted)
    static int adjust_3dnr_gmv_by_conf(int force3DNR, const int confX, const int confY, int &outGmvX, int &outGmvY)
    {
        int confXThrL = NR3D_GMVX_CONF_LOW_THRESHOLD;
        int confXThrH = NR3D_GMVX_CONF_HIGH_THRESHOLD;
        int confYThrL = NR3D_GMVY_CONF_LOW_THRESHOLD;
        int confYThrH = NR3D_GMVY_CONF_HIGH_THRESHOLD;

        if (force3DNR)
        {
            confXThrL = ::property_get_int32("debug.nr3d.confXL", NR3D_GMVX_CONF_LOW_THRESHOLD);
            confXThrH = ::property_get_int32("debug.nr3d.confXH", NR3D_GMVX_CONF_HIGH_THRESHOLD);
            confYThrL = ::property_get_int32("debug.nr3d.confYL", NR3D_GMVY_CONF_LOW_THRESHOLD);
            confYThrH = ::property_get_int32("debug.nr3d.confYH", NR3D_GMVY_CONF_HIGH_THRESHOLD);
        }

        if (confX <= confXThrL && confY <= confYThrH)
        {
            outGmvX = outGmvY = 0;
            return 1;
        }

        if (confY <= confYThrL && confX <= confXThrH)
        {
            outGmvX = outGmvY = 0;
            return 1;
        }

        return 0;
    }
};
#endif /* _3DNR_CUSTOM_BASE_H_ */

