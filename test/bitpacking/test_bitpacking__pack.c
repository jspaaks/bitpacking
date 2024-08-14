#include <criterion/criterion.h>
#include <stdint.h>
#include "bitpacking/pack.h"

Test(bitpacking__pack, ones_only){
    // 00111111 00111111 00111111 00111111
    // 111111 111111 111111 111111
    // 11111111 11111111 11111111
    uint8_t unpacked[4] = {63, 63, 63, 63};
    uint8_t packed[3] = {0};
    bitpacking__pack(&unpacked, &packed);
    uint8_t expected[3] = {255, 255, 255};
    constexpr size_t n = sizeof(expected) / sizeof(expected[0]);
    for (size_t i = 0; i < n; ++i) {
        cr_assert(packed[i] == expected[i], "actual != expected at index %zu\n", i);
    }
}

Test(bitpacking__pack, bookends){
    // 00100000 00011000 00000110 00000001 
    // 100000 011000 000110 000001 
    // 10000001 10000001 10000001 
    uint8_t unpacked[4] = {32, 24, 6, 1};
    uint8_t packed[3] = {0};
    bitpacking__pack(&unpacked, &packed);
    uint8_t expected[3] = {129, 129, 129};
    constexpr size_t n = sizeof(expected) / sizeof(expected[0]);
    for (size_t i = 0; i < n; ++i) {
        cr_assert(packed[i] == expected[i], "actual != expected at index %zu\n", i);
    }
}
