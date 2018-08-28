/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
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
#ifndef _CAMERA_CUSTOM_MFLL_H_
#define _CAMERA_CUSTOM_MFLL_H_

/**************************************************************************
 *                      D E F I N E S / M A C R O S                       *
 **************************************************************************/
// For MFLL Customer Parameters
//
// [SW Workaround Solution]
//     - When CUST_MFLL_ENABLE_SWWKN_FIX_MIX==0,
//          Use software Workaround for hardware MIX3.
//          Some hardware "MIXER3" may have hardware limitation, we have to perform
//          this SW Workaround solution but performance may be slow down.
//          (12M Pixel costs 70~80 ms)
//     - When CUST_MFLL_ENABLE_SWWKN_FIX_MIX==1,
//          Do not use software Workaround for hardware MIX3.
//          If the software Workaround is disabled, the image quality may have
//          a little problem. However, MIX3 problem is not in all chips.
#define CUST_MFLL_ENABLE_SWWKN_FIX_MIX  0

//
// [Content-Aware AIS]
//     CUST_MFLL_ENABLE_CONTENT_AWARE_AIS is a bitwise flag for enable/disable
//     content-aware AIS by sensor index.
//     - When the i-th bits of CUST_MFLL_ENABLE_CONTENT_AWARE_AIS==0,
//          Disable content-aware AIS at the i-th sensor,
//
//     - When the i-th bits of CUST_MFLL_ENABLE_CONTENT_AWARE_AIS==1,
//          Enable content-aware AIS at the i-th sensor.
#define CUST_MFLL_ENABLE_CONTENT_AWARE_AIS 0xFFFFFFFF

// [Best Shot Selection (BSS)]
//     - When CUST_MFLL_ENABLE_BSS_FOR_MFLL==0,
//          Use the first image as base image for blending.
//          The advantage is shutter lag has been minimized.
//          The drawback is final image has higher motion blur (cause by handshack)possibility .
//     - When CUST_MFLL_ENABLE_BSS_FOR_MFLL==1 (recommended),
//          Use the image with the highest sharpness as base image.
//          The advantage is the motion blur (cause by handshack) has been minimized.
//          The drawback is a longer shutter lag (average ~+100ms)
#define CUST_MFLL_ENABLE_BSS_FOR_MFLL   1

//     - When CUST_MFLL_ENABLE_BSS_FOR_AIS==0,
//          Use the first image as base image for blending.
//          The advantage is shutter lag has been minimized.
//          The drawback is final image has higher motion blur (cause by handshack)possibility .
//     - When CUST_MFLL_ENABLE_BSS_FOR_AIS==1 (recommended),
//          Use the image with the highest sharpness as base image.
//          The advantage is the motion blur (cause by handshack) has been minimized.
//          The drawback is a longer shutter lag (average ~+100ms)
#define CUST_MFLL_ENABLE_BSS_FOR_AIS    1

//     - how many rows are skipped during processing
//          recommand range: >=8
//          recommand value: 8
//          larger scale factor cause less accurate but faster execution time.
#define CUST_MFLL_BSS_SCALE_FACTOR      8

//     - minimum edge response
//          recommand range: 10~30
//          recommand value: 20
//          larger th0 cause better noise resistence but may miss real edges.
#define CUST_MFLL_BSS_CLIP_TH0          20

//     - maximum edge response
//          recommand range: 50~120
//          recommand value: 100
//          larger th1 will suppress less high contrast edges
#define CUST_MFLL_BSS_CLIP_TH1          100

//     - tri-pod/static scene detection
//          recommand range: 0~10
//          recommand value: 10
//          larger zero cause more scene will be considered as static
#define CUST_MFLL_BSS_ZERO              10

//     - brightness difference threshold
//          recommand range: 0~31
//          recommand value: 12
#define CUST_MFLL_BSS_ADF_TH            18

//     - sharpness difference threshold
//          recommand range: 0~90
//          recommand value: 70
#define CUST_MFLL_BSS_SDF_TH            50

// [MFNR auto mode setting]
//     - config MFLL mode when App trigger auto mode
//          recommand range: 0~2 (0:disable, 1:MFNR, 2:AIS)
//          recommand value: 1 or 2
#define CUST_MFLL_AUTO_MODE             1

#endif  // _CAMERA_CUSTOM_MFLL_H_
