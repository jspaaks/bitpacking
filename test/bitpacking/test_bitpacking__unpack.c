#include <criterion/criterion.h>
#include <stdint.h>
#include "bitpacking/unpack.h"

Test(bitpacking__unpack, ones_only){
    // 11111111 11111111 11111111
    // 111111 111111 111111 111111
    // 00111111 00111111 00111111 00111111
    uint8_t packed[3] = {255, 255, 255};
    uint8_t unpacked[4] = {0};
    bitpacking__unpack(&packed, &unpacked);
    uint8_t expected[4] = {63, 63, 63, 63};
    constexpr size_t n = sizeof(expected) / sizeof(expected[0]);
    for (size_t i = 0; i < n; ++i) {
        cr_assert(unpacked[i] == expected[i], "actual != expected at index %zu\n", i);
    }
}

Test(bitpacking__unpack, bookends){
    // 10000001 10000001 10000001 
    // 100000 011000 000110 000001 
    // 00100000 00011000 00000110 00000001 
    uint8_t packed[3] = {129, 129, 129};
    uint8_t unpacked[4] = {0};
    bitpacking__unpack(&packed, &unpacked);
    uint8_t expected[4] = {32, 24, 6, 1};
    constexpr size_t n = sizeof(expected) / sizeof(expected[0]);
    for (size_t i = 0; i < n; ++i) {
        cr_assert(unpacked[i] == expected[i], "actual != expected at index %zu\n", i);
    }
}
