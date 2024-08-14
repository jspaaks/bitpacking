#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "bitpacking/pack.h"
#include "bitpacking/unpack.h"



static uint8_t unpacked[4] = {32, 24, 6, 1};
static uint8_t packed[3] = {};

constexpr size_t nunpacked = sizeof(unpacked) / sizeof(unpacked[0]);
constexpr size_t npacked = sizeof(packed) / sizeof(packed[0]);

static void print(FILE * fd) {
    for (size_t i = 0; i < nunpacked; ++i) {
        fprintf(fd, "unpacked[%zu] = %d\n", i, unpacked[i]);
    }
    for (size_t i = 0; i < npacked; ++i) {
        fprintf(fd, "packed[%zu] = %d\n", i, packed[i]);
    }
    fprintf(fd, "\n");
}


int main (void) {

    print(stdout);
    bitpacking__pack(&unpacked, &packed);
    print(stdout);


    fprintf(stdout, "resetting unpacked\n");
    for (size_t i = 0; i < nunpacked; i++) {
        unpacked[i] = 0;
    }

    print(stdout);
    bitpacking__unpack(&packed, &unpacked);
    print(stdout);
    return EXIT_SUCCESS;
}
