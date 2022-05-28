#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef unsigned char byte;

void swap(void * const fst, void * const snd, const unsigned long long sz) {
    byte * const tmp = (byte *)malloc(sz);
    memcpy(tmp, fst, sz);
    memcpy(fst, snd, sz);
    memcpy(snd, tmp, sz);
    free(tmp);
}
