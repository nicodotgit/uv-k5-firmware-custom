#include "helper/string.h"

static void itoa_pad_char(char *str, uint32_t val, uint8_t pad, char pad_char, char sign) {
    char buf[12];
    uint8_t i = 0;
    
    // Convert to string in reverse
    do {
        buf[i++] = (val % 10) + '0';
        val /= 10;
    } while (val > 0);
    
    if (sign && pad_char != '0') {
        buf[i++] = sign;
        sign = '\0';
    }

    // Add padding if needed
    while (i < pad && i < 11) {
        buf[i++] = pad_char;
    }
    
    if (sign && pad_char == '0') {
        buf[i++] = sign;
    }

    // Reverse and copy to output
    for (uint8_t j = 0; j < i; j++) {
        str[j] = buf[i - 1 - j];
    }
    str[i] = '\0';
}

void itoa_pad(char *str, uint32_t val, uint8_t pad) {
    itoa_pad_char(str, val, pad, '0', '\0');
}

void itoa_int(char *str, int32_t val, uint8_t pad) {
    char sign = '\0';
    if (val < 0) {
        sign = '-';
        val = -val;
    }
    itoa_pad_char(str, (uint32_t)val, pad, '0', sign);
}

void itoa_hex(char *str, uint32_t val, uint8_t pad) {
    char buf[9];
    uint8_t i = 0;
    
    do {
        uint8_t nibble = val & 0xF;
        if (nibble < 10) {
            buf[i++] = nibble + '0';
        } else {
            buf[i++] = nibble - 10 + 'A';
        }
        val >>= 4;
    } while (val > 0);
    
    while (i < pad && i < 8) {
        buf[i++] = '0';
    }
    
    for (uint8_t j = 0; j < i; j++) {
        str[j] = buf[i - 1 - j];
    }
    str[i] = '\0';
}

void itoa_oct(char *str, uint32_t val, uint8_t pad) {
    char buf[12];
    uint8_t i = 0;
    
    do {
        buf[i++] = (val & 7) + '0';
        val >>= 3;
    } while (val > 0);
    
    while (i < pad && i < 11) {
        buf[i++] = '0';
    }
    
    for (uint8_t j = 0; j < i; j++) {
        str[j] = buf[i - 1 - j];
    }
    str[i] = '\0';
}

#include <stdarg.h>
#include <string.h>

int sprintf_(char* buffer, const char* format, ...) {
    va_list va;
    va_start(va, format);
    char *out = buffer;
    while (*format) {
        if (*format == '%') {
            format++;
            int pad = 0;
            char pad_char = ' ';
            if (*format == ' ') { format++; } // skip space flag
            if (*format == '+') { format++; } // skip plus flag
            if (*format == '0') {
                pad_char = '0';
                format++;
            }
            int precision = -1;
            if (*format == '*') {
                pad = va_arg(va, int);
                format++;
            } else {
                while (*format >= '0' && *format <= '9') {
                    pad = pad * 10 + (*format - '0');
                    format++;
                }
            }
            if (*format == '.') {
                format++;
                if (*format == '*') {
                    precision = va_arg(va, int);
                    format++;
                } else {
                    precision = 0;
                    while (*format >= '0' && *format <= '9') {
                        precision = precision * 10 + (*format - '0');
                        format++;
                    }
                }
            }
            if (*format == '%') {
                *out++ = '%';
            } else if (*format == 's') {
                char *s = va_arg(va, char*);
                int len = 0;
                while (s[len]) len++;
                if (precision >= 0 && len > precision) len = precision;
                while (pad > len) { *out++ = pad_char; pad--; }
                int p = 0;
                while (*s && (precision < 0 || p < precision)) { *out++ = *s++; p++; }
            } else if (*format == 'd' || *format == 'i' || *format == 'u') {
                int val = va_arg(va, int);
                char temp[16];
                char sign = '\0';
                if (*format != 'u' && val < 0) {
                    sign = '-';
                    val = -val;
                }
                itoa_pad_char(temp, (uint32_t)val, pad, pad_char, sign);
                char *s = temp;
                while (*s) { *out++ = *s++; }
            } else if (*format == 'o') {
                int val = va_arg(va, int);
                char temp[12];
                itoa_oct(temp, (uint32_t)val, pad);
                char *s = temp;
                while (*s) { *out++ = *s++; }
            } else if (*format == 'c') {
                *out++ = (char)va_arg(va, int);
            } else if (*format == 'X' || *format == 'x') {
                int val = va_arg(va, int);
                char temp[9];
                itoa_hex(temp, (uint32_t)val, pad);
                char *s = temp;
                while (*s) { *out++ = *s++; }
            } else {
                *out++ = '%';
                *out++ = *format;
            }
        } else {
            *out++ = *format;
        }
        format++;
    }
    *out = '\0';
    va_end(va);
    return out - buffer;
}
