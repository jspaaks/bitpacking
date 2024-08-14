#ifndef BITPACKING_UNPACK_H
#define BITPACKING_UNPACK_H
#include <stdint.h>

void bitpacking__unpack (const uint8_t (*packed)[3], uint8_t (*unpacked)[4]);

#endif
