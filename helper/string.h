#ifndef HELPER_STRING_H
#define HELPER_STRING_H

#include <stdint.h>
#include <stddef.h>

void itoa_pad(char *str, uint32_t val, uint8_t pad);
void itoa_int(char *str, int32_t val, uint8_t pad);
void itoa_hex(char *str, uint32_t val, uint8_t pad);
void itoa_oct(char *str, uint32_t val, uint8_t pad);

#define sprintf sprintf_
int sprintf_(char* buffer, const char* format, ...);

#endif
