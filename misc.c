/* Copyright 2023 Dual Tachyon
 * https://github.com/DualTachyon
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#include <string.h>

#include "misc.h"
#include "settings.h"

const uint32_t    gDefaultAesKey[4]                = {0x4AA5CC60, 0x0312CC5F, 0xFFD2DABB, 0x6BBA7F92};

const uint8_t     gMicGain_dB2[5]                  = {3, 8, 16, 24, 31};

#ifndef ENABLE_FEAT_F4HWN
    bool              gSetting_350TX;
#endif

#ifdef ENABLE_DTMF_CALLING
bool              gSetting_KILLED;
#endif

#ifndef ENABLE_FEAT_F4HWN
bool              gSetting_200TX;
bool              gSetting_500TX;
#endif
bool              gSetting_350EN;
uint8_t           gSetting_F_LOCK;
bool              gSetting_ScrambleEnable;

enum BacklightOnRxTx_t gSetting_backlight_on_tx_rx;

#ifdef ENABLE_AM_FIX
    bool          gSetting_AM_fix = true;
#endif

#ifdef ENABLE_FEAT_F4HWN_SLEEP 
    uint8_t       gSetting_set_off = 1;
    bool          gWakeUp = false;
#endif

#ifdef ENABLE_FEAT_F4HWN
    uint8_t       gSetting_set_pwr = 1;
    bool          gSetting_set_ptt = 0;
    uint8_t       gSetting_set_tot = 0;
    uint8_t       gSetting_set_ctr = 10;
    bool          gSetting_set_inv = false;
    uint8_t       gSetting_set_eot = 0;
    bool          gSetting_set_lck = false;
    bool          gSetting_set_met = 0;
    bool          gSetting_set_gui = 0;
    #ifdef ENABLE_FEAT_F4HWN_NARROWER
        bool          gSetting_set_nfm = 0;
    #endif
    bool          gSetting_set_tmr = 0;
    bool          gSetting_set_ptt_session;
    #ifdef ENABLE_FEAT_F4HWN_DEBUG
        uint8_t       gDebug;
    #endif
    uint8_t       gDW = 0;
    uint8_t       gCB = 0;
    bool          gSaveRxMode = false;
    uint8_t       crc[15] = { 0 };
    uint8_t       lErrorsDuringAirCopy = 0;
    uint8_t       gAircopyStep = 0;
    #ifdef ENABLE_FEAT_F4HWN_RESCUE_OPS
        bool          gPowerHigh = false;
        bool          gRemoveOffset = false;
    #endif
#endif

#ifdef ENABLE_AUDIO_BAR
    bool          gSetting_mic_bar;
#endif
bool              gSetting_live_DTMF_decoder;
uint8_t           gSetting_battery_text;

bool              gMonitor = false;           // true opens the squelch

uint32_t          gCustomAesKey[4];
bool              bHasCustomAesKey;
uint32_t          gChallenge[4];
uint8_t           gTryCount;

uint16_t          gEEPROM_RSSI_CALIB[7][4];

uint16_t          gEEPROM_1F8A;
uint16_t          gEEPROM_1F8C;

ChannelAttributes_t gMR_ChannelAttributes[FREQ_CHANNEL_LAST + 1];
bool                gMR_ChannelExclude[FREQ_CHANNEL_LAST + 1];

volatile uint16_t gBatterySaveCountdown_10ms = battery_save_count_10ms;

volatile bool     gPowerSaveCountdownExpired;
volatile bool     gSchedulePowerSave;

volatile bool     gScheduleDualWatch = true;

volatile uint16_t gDualWatchCountdown_10ms;
bool              gDualWatchActive           = false;

volatile uint8_t  gSerialConfigCountDown_500ms;

volatile bool     gNextTimeslice_500ms;

volatile uint16_t gTxTimerCountdown_500ms;
volatile bool     gTxTimeoutReached;

#ifdef ENABLE_FEAT_F4HWN
    volatile uint16_t gTxTimerCountdownAlert_500ms;
    volatile bool     gTxTimeoutReachedAlert;
    volatile uint16_t gTxTimeoutToneAlert = 800;
    #ifdef ENABLE_FEAT_F4HWN_RX_TX_TIMER
        volatile uint16_t gRxTimerCountdown_500ms;
    #endif
    #ifdef ENABLE_FEAT_F4HWN_SCREENSHOT
         volatile uint8_t  gUART_LockScreenshot = 0; // lock screenshot if Chirp is used
    #endif
#endif

volatile uint16_t gTailNoteEliminationCountdown_10ms;

volatile uint8_t    gVFOStateResumeCountdown_500ms;

#ifdef ENABLE_NOAA
    volatile uint16_t gNOAA_Countdown_10ms;
#endif

bool              gEnableSpeaker;
uint8_t           gKeyInputCountdown = 0;
uint8_t           gKeyLockCountdown;
uint8_t           gRTTECountdown_10ms;
bool              bIsInLockScreen;
uint8_t           gUpdateStatus;
uint8_t           gFoundCTCSS;
uint8_t           gFoundCDCSS;
bool              gEndOfRxDetectedMaybe;

int16_t           gVFO_RSSI[2];
uint8_t           gVFO_RSSI_bar_level[2];

uint8_t           gReducedService;
uint8_t           gBatteryVoltageIndex;
bool              gCssBackgroundScan;

volatile bool     gScheduleScanListen = true;
volatile uint16_t gScanPauseDelayIn_10ms;

#if defined(ENABLE_ALARM) || defined(ENABLE_TX1750)
    AlarmState_t  gAlarmState;
#endif
uint16_t          gMenuCountdown;
bool              gPttWasReleased;
bool              gPttWasPressed;
uint8_t           gKeypadLocked;
bool              gFlagReconfigureVfos;
uint8_t           gVfoConfigureMode;
bool              gFlagResetVfos;
bool              gRequestSaveVFO;
uint8_t           gRequestSaveChannel;
bool              gRequestSaveSettings;
#ifdef ENABLE_FMRADIO
    bool          gRequestSaveFM;
#endif
bool              gFlagPrepareTX;

bool              gFlagAcceptSetting;
bool              gFlagRefreshSetting;

#ifdef ENABLE_FMRADIO
    bool          gFlagSaveFM;
#endif
bool              g_CDCSS_Lost;
uint8_t           gCDCSSCodeType;
bool              g_CTCSS_Lost;
bool              g_CxCSS_TAIL_Found;
#ifdef ENABLE_VOX
    bool          g_VOX_Lost;
    bool          gVOX_NoiseDetected;
    uint16_t      gVoxResumeCountdown;
    uint16_t      gVoxPauseCountdown;
#endif
bool              g_SquelchLost;

volatile uint16_t gFlashLightBlinkCounter;

bool              gFlagEndTransmission;
uint8_t           gNextMrChannel;
ReceptionMode_t   gRxReceptionMode;

bool              gRxVfoIsActive;
#ifdef ENABLE_ALARM
    uint8_t       gAlarmToneCounter;
    uint16_t      gAlarmRunningCounter;
#endif
bool              gKeyBeingHeld;
bool              gPttIsPressed;
uint8_t           gPttDebounceCounter;
uint8_t           gMenuListCount;
uint8_t           gBackup_CROSS_BAND_RX_TX;
uint8_t           gScanDelay_10ms;
uint8_t           gFSKWriteIndex;

#ifdef ENABLE_NOAA
    bool          gIsNoaaMode;
    uint8_t       gNoaaChannel;
#endif

bool              gUpdateDisplay;

bool              gF_LOCK = false;

uint8_t           gShowChPrefix;

volatile bool     gNextTimeslice;
volatile uint8_t  gFoundCDCSSCountdown_10ms;
volatile uint8_t  gFoundCTCSSCountdown_10ms;
#ifdef ENABLE_VOX
    volatile uint16_t gVoxStopCountdown_10ms;
#endif
volatile bool     gNextTimeslice40ms;
#ifdef ENABLE_NOAA
    volatile uint16_t gNOAACountdown_10ms = 0;
    volatile bool     gScheduleNOAA       = true;
#endif
volatile bool     gFlagTailNoteEliminationComplete;
#ifdef ENABLE_FMRADIO
    volatile bool gScheduleFM;
#endif

volatile uint8_t  boot_counter_10ms;

uint8_t           gIsLocked = 0xFF;


#ifdef ENABLE_FEAT_F4HWN
    bool          gK5startup = true;
    bool          gBackLight = false;
    bool          gMute = false;
    uint8_t       gBacklightTimeOriginal;
    uint8_t       gBacklightBrightnessOld;
    uint8_t       gPttOnePushCounter = 0;
    uint32_t      gBlinkCounter = 0;
#endif

inline void FUNCTION_NOP() { ; }


int32_t NUMBER_AddWithWraparound(int32_t Base, int32_t Add, int32_t LowerLimit, int32_t UpperLimit)
{
    Base += Add;

    if (Base == 0x7fffffff || Base < LowerLimit)
        return UpperLimit;

    if (Base > UpperLimit)
        return LowerLimit;

    return Base;
}

unsigned long StrToUL(const char * str)
{
    unsigned long ul = 0;
    for (const char *p = str; *p; p++) {
        if (*p < '0' || *p > '9')
            break;
        ul = ul * 10 + (uint8_t)(*p - '0');
    }
    return ul;
}
