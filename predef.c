#include "predef.h"

void swap(void * fst, void * snd, const uLLong sz) {
    byte * const tmp = (byte *)malloc(sz);
    memcpy(tmp, fst, sz);
    memcpy(fst, snd, sz);
    memcpy(snd, tmp, sz);
    free(tmp);
}