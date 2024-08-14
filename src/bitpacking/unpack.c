#include "bitpacking/unpack.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static const uint8_t b00000011 = 3;
static const uint8_t b00001111 = 15;
static const uint8_t b00111111 = 63;
static const uint8_t b11000000 = 192;
static const uint8_t b11110000 = 240;
static const uint8_t b11111100 = 252;

void bitpacking__unpack (const uint8_t (*packed)[3], uint8_t (*unpacked)[4]) {

    uint8_t a = (*packed)[0];
    uint8_t b = (*packed)[1];
    uint8_t c = (*packed)[2];

    (*unpacked)[0] = (a & b11111100) >> 2;
    (*unpacked)[1] = (a & b00000011) << 4 | (b & b11110000) >> 4;
    (*unpacked)[2] = (b & b00001111) << 2 | (c & b11000000) >> 6;
    (*unpacked)[3] = (c & b00111111);
}
