#include "bitpacking/pack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

static const uint8_t b00110000 = 48;
static const uint8_t b00111100 = 60;
static const uint8_t b00111111 = 63;

void bitpacking__pack (const uint8_t (*unpacked)[4], uint8_t (*packed)[3]) {

    uint8_t a = (*unpacked)[0];
    uint8_t b = (*unpacked)[1];
    uint8_t c = (*unpacked)[2];
    uint8_t d = (*unpacked)[3];

    (*packed)[0] = (a << 2) | ((b & b00110000) >> 4);
    (*packed)[1] = (b << 4) | ((c & b00111100) >> 2);
    (*packed)[2] = (c << 6) | (d & b00111111);
}
