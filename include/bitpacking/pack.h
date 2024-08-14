#ifndef BITPACKING_PACK_H
#define BITPACKING_PACK_H
#include <stdint.h>

void bitpacking__pack (const uint8_t (*unpacked)[4], uint8_t (*packed)[3]);

#endif
