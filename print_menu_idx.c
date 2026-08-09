#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    const char *name;
    uint8_t menu_id;
} t_menu_item;

#define ENABLE_FEAT_F4HWN 1
#define ENABLE_NOAA 0
#define ENABLE_FEAT_F4HWN_RESCUE_OPS 0
#define ENABLE_VOX 0

// Dummy defines to make ui/menu.c compile enough to parse
#define MENU_F_LOCK 255
#define MENU_STEP 1
#define MENU_TXP 2
#define MENU_R_DCS 3
#define MENU_R_CTCS 4
#define MENU_T_DCS 5
#define MENU_T_CTCS 6
#define MENU_SFT_D 7
#define MENU_OFFSET 8
#define MENU_W_N 9
#define MENU_BCL 10
#define MENU_COMPAND 11
#define MENU_AM 12
#define MENU_TX_LOCK 13
#define MENU_S_ADD1 14
#define MENU_S_ADD2 15
#define MENU_S_ADD3 16
#define MENU_MEM_CH 17
#define MENU_DEL_CH 18
#define MENU_MEM_NAME 19
#define MENU_S_LIST 20
#define MENU_SLIST1 21
#define MENU_SLIST2 22
#define MENU_SLIST3 23
#define MENU_SC_REV 24
#define MENU_F1SHRT 25
#define MENU_F1LONG 26
#define MENU_F2SHRT 27
#define MENU_F2LONG 28
#define MENU_MLONG 29
#define MENU_AUTOLK 30
#define MENU_TOT 31
#define MENU_SAVE 32
#define MENU_BAT_TXT 33
#define MENU_MIC 34
#define MENU_MIC_BAR 35
#define MENU_MDF 36
#define MENU_PONMSG 37
#define MENU_ABR 38
#define MENU_ABR_MIN 39
#define MENU_ABR_MAX 40
#define MENU_ABR_ON_TX_RX 41
#define MENU_BEEP 42
#define MENU_ROGER 43
#define MENU_STE 44
#define MENU_RP_STE 45
#define MENU_1_CALL 46
#define MENU_UPCODE 47
#define MENU_DWCODE 48
#define MENU_PTT_ID 49
#define MENU_D_ST 50
#define MENU_D_PRE 51
#define MENU_D_LIVE_DEC 52
#define MENU_VOX 53
#define MENU_VOL 54
#define MENU_TDR 55
#define MENU_SQL 56
#define MENU_SET_PWR 57
#define MENU_SET_PTT 58
#define MENU_SET_TOT 59
#define MENU_SET_EOT 60
#define MENU_SET_CTR 61
#define MENU_SET_INV 62
#define MENU_SET_LCK 63
#define MENU_SET_MET 64
#define MENU_SET_GUI 65
#define MENU_SET_TMR 66
#define MENU_SET_OFF 67
#define MENU_SET_NFM 68
#define MENU_SET_VOL 69
#define MENU_350EN 70
#define MENU_F_CALI 71
#define MENU_BATCAL 72
#define MENU_BATTYP 73
#define MENU_RESET 74

const t_menu_item MenuList[] =
{
    {"Step",        MENU_STEP          },
    {"Power",       MENU_TXP           }, // was "TXP"
    {"RxDCS",       MENU_R_DCS         }, // was "R_DCS"
    {"RxCTCS",      MENU_R_CTCS        }, // was "R_CTCS"
    {"TxDCS",       MENU_T_DCS         }, // was "T_DCS"
    {"TxCTCS",      MENU_T_CTCS        }, // was "T_CTCS"
    {"TxODir",      MENU_SFT_D         }, // was "SFT_D"
    {"TxOffs",      MENU_OFFSET        }, // was "OFFSET"
    {"W/N",         MENU_W_N           },
#ifndef ENABLE_FEAT_F4HWN
    {"Scramb",      MENU_SCR           }, // was "SCR"
#endif
    {"BusyCL",      MENU_BCL           }, // was "BCL"
    {"Compnd",      MENU_COMPAND       },
    {"Mode",        MENU_AM            }, // was "AM"
#ifdef ENABLE_FEAT_F4HWN
    {"TXLock",      MENU_TX_LOCK       }, 
#endif
    {"ScAdd1",      MENU_S_ADD1        },
    {"ScAdd2",      MENU_S_ADD2        },
    {"ScAdd3",      MENU_S_ADD3        },
    {"ChSave",      MENU_MEM_CH        }, // was "MEM-CH"
    {"ChDele",      MENU_DEL_CH        }, // was "DEL-CH"
    {"ChName",      MENU_MEM_NAME      },

    {"SList",       MENU_S_LIST        },
    {"SList1",      MENU_SLIST1        },
    {"SList2",      MENU_SLIST2        },
    {"SList3",      MENU_SLIST3        },
    {"ScnRev",      MENU_SC_REV        },
#ifndef ENABLE_FEAT_F4HWN
    #ifdef ENABLE_NOAA
        {"NOAA-S",      MENU_NOAA_S    },
    #endif
#endif
    {"F1Shrt",      MENU_F1SHRT        },
    {"F1Long",      MENU_F1LONG        },
    {"F2Shrt",      MENU_F2SHRT        },
    {"F2Long",      MENU_F2LONG        },
    {"M Long",      MENU_MLONG         },

    {"KeyLck",      MENU_AUTOLK        }, // was "AUTOLk"
    {"TxTOut",      MENU_TOT           }, // was "TOT"
    {"BatSav",      MENU_SAVE          }, // was "SAVE"
    {"BatTxt",      MENU_BAT_TXT       },
    {"Mic",         MENU_MIC           },
    {"MicBar",      MENU_MIC_BAR       },
    {"ChDisp",      MENU_MDF           }, // was "MDF"
    {"POnMsg",      MENU_PONMSG        },
    {"BLTime",      MENU_ABR           }, // was "ABR"
    {"BLMin",       MENU_ABR_MIN       },
    {"BLMax",       MENU_ABR_MAX       },
    {"BLTxRx",      MENU_ABR_ON_TX_RX  },
    {"Beep",        MENU_BEEP          },
#ifdef ENABLE_VOICE
    {"Voice",       MENU_VOICE         },
#endif
    {"Roger",       MENU_ROGER         },
    {"STE",         MENU_STE           },
    {"RP STE",      MENU_RP_STE        },
    {"1 Call",      MENU_1_CALL        },
#ifdef ENABLE_ALARM
    {"AlarmT",      MENU_AL_MOD        },
#endif
#ifdef ENABLE_DTMF_CALLING
    {"ANI ID",      MENU_ANI_ID        },
#endif
    {"UPCode",      MENU_UPCODE        },
    {"DWCode",      MENU_DWCODE        },
    {"PTT ID",      MENU_PTT_ID        },
    {"D ST",        MENU_D_ST          },
#ifdef ENABLE_DTMF_CALLING
    {"D Resp",      MENU_D_RSP         },
    {"D Hold",      MENU_D_HOLD        },
#endif
    {"D Prel",      MENU_D_PRE         },
#ifdef ENABLE_DTMF_CALLING
    {"D Decd",      MENU_D_DCD         },
    {"D List",      MENU_D_LIST        },
#endif
    {"D Live",      MENU_D_LIVE_DEC    }, // live DTMF decoder
#ifndef ENABLE_FEAT_F4HWN
    #ifdef ENABLE_AM_FIX
        {"AM Fix",      MENU_AM_FIX        },
    #endif
#endif
    {"VOX",         MENU_VOX           },
#ifdef ENABLE_FEAT_F4HWN
    {"About",       MENU_VOL           }, // was "VOL"
#else
    {"BatVol",      MENU_VOL           }, // was "VOL"
#endif
    {"RxMode",      MENU_TDR           },
    {"Sql",         MENU_SQL           },
#ifdef ENABLE_FEAT_F4HWN
    {"SetPwr",      MENU_SET_PWR       },
    {"SetPTT",      MENU_SET_PTT       },
    {"SetTOT",      MENU_SET_TOT       },
    {"SetEOT",      MENU_SET_EOT       },
    {"SetCtr",      MENU_SET_CTR       },
    {"SetInv",      MENU_SET_INV       },
    {"SetLck",      MENU_SET_LCK       },
    {"SetMet",      MENU_SET_MET       },
    {"SetGUI",      MENU_SET_GUI       },
    {"SetTmr",      MENU_SET_TMR       },
#ifdef ENABLE_FEAT_F4HWN_SLEEP
    {"SetOff",       MENU_SET_OFF      },
#endif
#ifdef ENABLE_FEAT_F4HWN_NARROWER
    {"SetNFM",      MENU_SET_NFM       },
#endif
#ifdef ENABLE_FEAT_F4HWN_VOL
    {"SetVol",      MENU_SET_VOL       },
#endif
#ifdef ENABLE_FEAT_F4HWN_RESCUE_OPS
    {"SetKey",      MENU_SET_KEY       },
#endif
#ifdef ENABLE_NOAA
    {"SetNWR",      MENU_NOAA_S    },
#endif
#endif
    // hidden menu items from here on
    // enabled if pressing both the PTT and upper side button at power-on
    {"F Lock",      MENU_F_LOCK        },
};

int main() {
    int i = 0;
    while (MenuList[i].menu_id != MENU_F_LOCK) i++;
    printf("MENU_F_LOCK index: %d\n", i);
    return 0;
}
