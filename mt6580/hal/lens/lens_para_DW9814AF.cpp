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
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

#include "camera_custom_nvram.h"
#include "camera_custom_lens.h"


const NVRAM_LENS_PARA_STRUCT DW9814AF_LENS_PARA_DEFAULT_VALUE =
{
    //Version
    NVRAM_CAMERA_LENS_FILE_VERSION,

    // Focus Range NVRAM
    {0, 1023},

    // AF NVRAM
    {
        // ------------------------------ sAF_Coef -----------------------------------------
        {
            {
                55,  // i4Offset
                14,  // i4NormalNum
                14,  // i4MacroNum
                0,   // i4InfIdxOffset
                0,   // i4MacroIdxOffset
                {
                       0,  10,  30,  60,  95, 135, 175, 215, 255, 295,
                     340, 385, 401, 435,   0,   0,   0,   0,   0,   0,
                       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                }
        },
        15,  // i4THRES_MAIN
        10,  // i4THRES_SUB
        1,  // i4AFC_FAIL_CNT
        -1,  // i4FAIL_POS
        4,  // i4INIT_WAIT
        {500, 500, 500, 500, 500},  // i4FRAME_WAIT
        0,  // i4DONE_WAIT
        },
        // ------------------------------ sVAFC_Coef -----------------------------------------
        {
            {
                55,  // i4Offset
                14,  // i4NormalNum
                14,  // i4MacroNum
                0,   // i4InfIdxOffset
                0,   // i4MacroIdxOffset
                {
                       0,  10,  30,  60,  95, 135, 175, 215, 255, 295,
                     340, 385, 401, 435,   0,   0,   0,   0,   0,   0,
                       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                }
        },
        15,  // i4THRES_MAIN
        10,  // i4THRES_SUB
        1,  // i4AFC_FAIL_CNT
        -1,  // i4FAIL_POS
        4,  // i4INIT_WAIT
        {0, 500, 500, 500, 500},  // i4FRAME_WAIT
        0,  // i4DONE_WAIT
        },
        // -------------------- sAF_TH ---------------------
        {
            8,  // i4ISONum;
            {100, 200, 400, 800, 1200, 1600, 2400, 3200},
            // SGG1~7
            {
             {5, 21, 21, 20, 20, 19, 19, 9},
             {9, 30, 30, 30, 29, 29, 28, 16},
             {18, 44, 43, 43, 43, 42, 42, 28},
             {33, 63, 62, 62, 62, 61, 61, 47},
             {59, 89, 89, 89, 88, 88, 88, 75},
             {101, 127, 127, 127, 126, 126, 126, 115},
             {163, 181, 180, 180, 180, 180, 180, 173},
            },
            // horizontal FV baseline
            {0, 0, 0, 0, 0, 0, 0, 0},

            // horizontal FV min. threshold
            {2000, 2000, 2000, 1000, 1000, 1000, 800, 800},

            // horizontal FV threshold
            {3, 3, 4, 4, 5, 6, 6, 7},

            // vertical FV baseline
            {0, 0, 0, 0, 0, 0, 0, 0},

            // vertical FV min. threshold
            {0, 0, 0, 0, 0, 0, 0, 0},

            // vertical FV threshold
            {5, 6, 6, 7, 7, 8, 11, 11},

        },
        // -------------------- sZSD_AF_TH ---------------------
        {
            8,  // i4ISONum;
            {100, 200, 400, 800, 1200, 1600, 2000, 2400},
            // SGG1~7
            {
             {20, 20, 19, 18, 18, 18, 18, 18},
             {30, 29, 29, 27, 27, 27, 27, 28},
             {43, 43, 42, 41, 41, 41, 41, 41},
             {62, 62, 61, 60, 60, 60, 60, 60},
             {89, 88, 88, 87, 87, 87, 87, 87},
             {127, 126, 126, 125, 125, 125, 125, 125},
             {180, 180, 180, 179, 179, 179, 179, 179},
            },
            // horizontal FV baseline
            {0, 0, 0, 0, 0, 0, 0, 0},

            // horizontal FV min. threshold
            {5000, 5000, 5000, 5000, 5000, 4000, 4000, 3000},

            // horizontal FV threshold
            {3, 4, 4, 6, 5, 5, 5, 6},

            // vertical FV baseline
            {0, 0, 0, 0, 0, 0, 0, 0},

            // vertical FV min. threshold
            {0, 0, 0, 0, 0, 0, 0, 0},

            // vertical FV threshold
            {6, 7, 9, 10, 10, 10, 10, 10},
        },
        // ------------------- sVID_AF_TH -----------------------------------
        {
            0,  // i4ISONum;
            {0, 0, 0, 0, 0, 0, 0, 0},
            // SGG1~7
            {
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            },
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4HW_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0} // i4HW_TH2[ISO_MAX_NUM];
        },
        // -------------------- sVID1_AF_TH ---------------------
        {
            0,  // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];
            // SGG1~7
            {
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            },
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4HW_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0} // i4HW_TH2[ISO_MAX_NUM];
        },
        // -------------------- sVID2_AF_TH ---------------------
        {
            0,  // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];
            // SGG1~7
            {
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            },
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4HW_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0} // i4HW_TH2[ISO_MAX_NUM];
        },
        // -------------------- sIHDR_AF_TH ---------------------
        {
            0,  // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];
            // SGG1~7
            {
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            },
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4HW_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0} // i4HW_TH2[ISO_MAX_NUM];
        },
        // -------------------- sREV1_AF_TH ---------------------
        {
            0,  // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];
            // SGG1~7
            {
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            },
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4HW_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0} // i4HW_TH2[ISO_MAX_NUM];
        },
        // -------------------- sREV2_AF_TH ---------------------
        {
            0,  // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];
            // SGG1~7
            {
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            },
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4HW_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0} // i4HW_TH2[ISO_MAX_NUM];
        },
        // -------------------- sREV3_AF_TH ---------------------
        {
            0,  // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];
            // SGG1~7
            {
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            },
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4HW_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0} // i4HW_TH2[ISO_MAX_NUM];
        },
        // -------------------- sREV4_AF_TH ---------------------
        {
            0,  // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];
            // SGG1~7
            {
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            },
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4HW_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0} // i4HW_TH2[ISO_MAX_NUM];
        },
        // -------------------- sREV5_AF_TH ---------------------
        {
            0,  // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];
            // SGG1~7
            {
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
            },
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4HW_TH[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4FV_DC2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0} // i4HW_TH2[ISO_MAX_NUM];
        },
        // --- Common use ---        
        1,  // i4ReadOTP; 				// 0: disable, 1:enable
        3,  // i4StatGain;
        0,  // i4LV_THRES;
        360,  // i4InfPos;
        33,  // i4FRAME_TIME;
        {0, 100, 200, 350, 500}, // back jump
        500,//i4BackJumpPos
        20, // i4AFC_STEP_SIZE
        18, // i4SPOT_PERCENT_W;        // AFC window location
        24, // i4SPOT_PERCENT_H;        // AFC window location
        0, // i4CHANGE_CNT_DELTA
        1, // i4AFS_STEP_MIN_ENABLE
        4, // i4AFS_STEP_MIN_NORMAL
        4, // i4AFS_STEP_MIN_MACRO
        8, // i4FIRST_FV_WAIT
        12, // i4FV_1ST_STABLE_THRES
        10000, // i4FV_1ST_STABLE_OFFSET
        8, // i4FV_1ST_STABLE_NUM
        8, // i4FV_1ST_STABLE_CNT
        50, // i4FV_SHOCK_THRES
        30000, // i4FV_SHOCK_OFFSET
        5, // i4FV_VALID_CNT
        20, // i4FV_SHOCK_FRM_CNT
        5, // i4FV_SHOCK_CNT
        // --- FaceAF ---
        80, // i4FDWinPercent
        60, // i4FDSizeDiff
        15, // i4FD_DETECT_CNT
        5, // i4FD_NONE_CNT
        // --- AFv1.1/AFv1.2 ---
        1, // i4LeftSearchEnable
        0, // i4LeftJumpStep
        0, // No use
        0, // i4AfDoneDelay
        0, // i4VdoAfDoneDelay
        0, // i4ZoomInWinChg
        1, // i4SensorEnable
        0, // i4PostureComp
        3, // i4SceneMonitorLevel
        1, // i4VdoSceneMonitorLevel

        // Scene Monitor                                                  
        // {Type, Off, Thr{by level}, Cnt{by level}}                      
        // Type: 1 is &&, 0 is ||                                         
        // Off : value, min=0 is more sensitive                           
        // Thr : percentage(value for gyro/acce), min=0 is more sensitive 
        // Cnt : value, max=30 is more stable                             
        // preview params                                                 
        {1,                                       // FV 0:disable, 1:enable
         0, 10000, { 40, 40, 30}, { 13, 10,  8},   //    chg; chgT lower to sensitive, chgN bigger to stable  
         1,  5000, { 15, 15, 15}, { 20, 15,  6} }, //    stb; stbT should fix, stbN bigger to stable      
        {1,                                       // GS 0:disable, 1:enable
         0,    15, { 20, 20,  8}, { 28, 25,  8},   //    chg; chgT lower to sensitive, chgN bigger to stable  
         1,     5, {  5,  5, 10}, { 12, 10,  5} }, //    stb; stbT should fix, stbN bigger to stable      
        {1,                                       // AEB 0:disable, 1:enable
         0,    15, { 30, 30, 15}, { 33, 30, 10},   //    chg; chgT lower to sensitive, chgN bigger to stable  
         1,     5, { 10, 10, 15}, { 12, 10,  5} }, //    stb; stbT should fix, stbN bigger to stable      
        {0,                                       // GYRO 0:disable, 1:enable
         0,     0, { 40, 40, 15}, {  5,  3,  3},    //    chg; off=0, chgT lower to sensitive, chgN bigger to stable
         1,     0, { 10, 10, 10}, { 12, 10,  5} },    //    stb; off=0, stbT should fix, stbN bigger to stable
        {1,                                       // ACCE 0:disable, 1:enable
         0,     0, { 80, 80, 40}, { 15, 12,  6},   //    chg; off=0, chgT lower to sensitive, chgN bigger to stable
         1,     0, { 60, 60, 60}, { 12, 10,  5} }, //    stb; off=0, stbT should fix, stbN bigger to stable
        {1,                                       //   0:disable, 1:enable
         0,   100, { 40, 40, 30}, { 13, 10, 10},   //    chg; chgT lower to sensitive, chgN bigger to stable  
         1,  5000, { 15, 15, 15}, { 20, 15, 10} }, //    stb; stbT should fix, stbN bigger to stable      
        {1,                                       //   0:disable, 1:enable
         0,    15, { 20, 20, 15}, { 28, 25, 25},   //    chg; chgT lower to sensitive, chgN bigger to stable  
         1,     5, {  5,  5,  5}, { 15, 13, 10} }, //    stb; stbT should fix, stbN bigger to stable      
        {1,                                       //   0:disable, 1:enable
         0,    15, { 30, 30, 25}, { 33, 30, 30},   //    chg; chgT lower to sensitive, chgN bigger to stable  
         1,     5, { 10, 10, 10}, { 15, 13, 10} }, //    stb; stbT should fix, stbN bigger to stable      
        {1,                                       //   0:disable, 1:enable
         0,     0, { 40, 40, 20}, {  7,  5,  5},   //    chg; chgT lower to sensitive, chgN bigger to stable  
         1,     0, { 10, 10, 10}, { 15, 13, 10} }, //    stb; stbT should fix, stbN bigger to stable      
        {1,                                       //   0:disable, 1:enable
         0,     0, { 80, 80, 60}, { 15, 12, 12},   //    chg; chgT lower to sensitive, chgN bigger to stable  
         1,     0, { 50, 50, 50}, { 13, 13, 10} }, //    stb; stbT should fix, stbN bigger to stable      
        // --- AFv2.0 ---     
        1,  // i4FvExtractEnable;           // 0:disable, 1:enable (for faceAF)
        40, // i4FvExtractThr               // percentage, fixed
        0,  // i4DampingCompEnable;         // 0:disable, 1:enable
        {7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 0, 0, 0, 0, 0, },        // { step1, step2, ... , step 15(atmost) }
        {
            {  -2, -4, -4, -6, -5, -5, -13, -8, -10, -20, 0, 0, 0, 0, 0, },// prerun0:{rComp1, rComp2, ..., rComp15(atmost)}
            {  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }   // prerun1:{rComp1, rComp2, ..., rComp15(atmost)}
        },
        {
            {  2, 4, 4, 6, 5, 5, 13, 8, 10, 20, 0, 0, 0, 0, 0, },// prerun0:{rComp1, rComp2, ..., rComp15(atmost)}
            {  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }   // prerun1:{rComp1, rComp2, ..., rComp15(atmost)}
        },
        1,  // i4DirSelectEnable;           // 0:disable, 1:enable
        1, // i4InfDir;                    // 1:right, -1:left, 2:reverse, 0:keep
        -1, // i4MidDir;                    // 
        1, // i4MacDir;                    // 
        30, // i4RatioInf;                  // below 6350514f tableLength belongs to INF
        70, // i4RatioMac;                  // above 6350514f tableLength belongs to MAC ; should be larger than i4RatioInf          
        1,  // i4StartBoundEnable;          // 0:disable, 1:enable
        2,  // i4StartCamCAF;               // 0:keep current, -1:force to INF, X:set to boundary if within X steps
        2,  // i4StartCamTAF;               // 
        0,  // i4StartVdoCAF;               // 
        0,  // i4StartVdoTAF;               // 
        0,  // i4FpsRemapTblEnable;         // 0:disable, 1:enable
        {10, 12}, // i4FpsThres[2];        // two fps threshold {very-low, low}
        {0, 0},   // i4TableClipPt[2];     // clip pts at macro side
        {80, 90}, // i4TableRemapPt[2];    // percentage of new/org table length

        // --- Easytuning ---   

        {0},// i4EasyTuning[100]

        // --- DepthAF ---      
        {
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
        }, // i4DepthAF[500]

        // --- reserved ---     
        {    
		    // i4Coefs[0]  inclinePeak rejection;   0: is disable, 1: is enable
		    // i4Coefs[1]  fdOffMaxCnt;             fd turnOff maxCnt for exiting faceAF, 0: use default value 10
		    // i4Coefs[41]  isPLenable;             0: is disable, 1: is enable
		    // i4Coefs[42]  plFlashReject;          0: is default, 1: is reject PL when flash
		    // i4Coefs[43]  plThresNsLv;            lv for night scene
		    // i4Coefs[44]  plThresIdLv;            lv for indoor
		    // i4Coefs[45]  plRatioNs;              ratio 0~100, from detect rate high to false alarm low
		    // i4Coefs[46]  plRatioId;              ratio 0~100, from detect rate high to false alarm low
		    // i4Coefs[47]  plRev1;
		    // i4Coefs[48]  plRev2;
		    // i4Coefs[49]  plRev3;
		    // i4Coefs[50]  plRev4;
		    0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   // [0]~[10]
		    0,0, 0, 0, 0, 0, 0, 0, 0, 0,     // [11]~[20]
		    0,0, 0, 0, 0, 0, 0, 0, 0, 0,     // [21]~[30]
		    0,0, 0, 0, 0, 0, 0, 0, 0, 0,     // [31]~[40]
		    0,0, 0, 0, 0, 0, 0, 0, 0, 0,     // [41]~[50]
        } // i4Coefs[100];    
    },                          
    {//PD_NVRAM_T
        {//PD_CALIBRATION_DATA_T
            {0},
            0,
        },
        {//PD_ALGO_TUNING_T
            0,
            0,
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
            },
            0,
            0,
            0,
            {0},
        },
    },
    {0}                         
};                              
UINT32 DW9814AF_getDefaultData(VOID *pDataBuf, UINT32 size)
{
    UINT32 dataSize = sizeof(NVRAM_LENS_PARA_STRUCT);

    if ((pDataBuf == NULL) || (size < dataSize))
    {
        return 1;
    }

    // copy from Buff to global struct
    memcpy(pDataBuf, &DW9814AF_LENS_PARA_DEFAULT_VALUE, dataSize);
    return 0;
}
PFUNC_GETLENSDEFAULT pDW9814AF_getDefaultData = DW9814AF_getDefaultData;


