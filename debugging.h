#ifndef DEBUGGING_H
#define DEBUGGING_H

#ifdef ENABLE_UART

#include "driver/uart.h"
#include "driver/bk4819.h"
#include "string.h"
#include "helper/string.h"
#include "am_fix.h"

static inline void LogUart(const char *const str)
{
    UART_Send(str, strlen(str));
}

static inline void LogRegUart(uint16_t reg)
{
    uint16_t regVal = BK4819_ReadRegister(reg);
    char buf[32];
    char temp[8];
    strcpy(buf, "reg");
    itoa_hex(temp, reg, 2);
    strcat(buf, temp);
    strcat(buf, ": ");
    itoa_hex(temp, regVal, 4);
    strcat(buf, temp);
    strcat(buf, "\n");
    LogUart(buf);
}

static inline void LogPrint()
{
    uint16_t rssi = BK4819_GetRSSI();
    uint16_t reg7e = BK4819_ReadRegister(0x7E);
    char buf[64];
    char temp[8];
    
    strcpy(buf, "reg7E: ");
    itoa_pad(temp, (reg7e >> 15), 1);
    strcat(buf, temp);
    strcat(buf, "  ");
    
    itoa_pad(temp, (reg7e >> 12) & 0b111, 2);
    strcat(buf, temp);
    strcat(buf, "  ");
    
    itoa_pad(temp, (reg7e >> 5) & 0b1111111, 6);
    strcat(buf, temp);
    strcat(buf, "  ");
    
    itoa_pad(temp, (reg7e >> 2) & 0b111, 2);
    strcat(buf, temp);
    strcat(buf, "  ");
    
    itoa_pad(temp, (reg7e >> 0) & 0b11, 1);
    strcat(buf, temp);
    strcat(buf, "   rssi: ");
    
    itoa_pad(temp, rssi, 1);
    strcat(buf, temp);
    strcat(buf, "\n");
    
    LogUart(buf);
}

#endif

#endif
