#ifndef DATA_STRUCTURE_PREDEF_H
#define DATA_STRUCTURE_PREDEF_H

#include <memory.h>
#include <stdlib.h>

typedef unsigned char      byte;
typedef unsigned long long uLLong;
typedef int (* CompFn)(const void *, const void *);

void swap(void * fst, void * snd, const uLLong sz) {
    byte * const tmp = (byte *)malloc(sz);
    memcpy(tmp, fst, sz);
    memcpy(fst, snd, sz);
    memcpy(snd, tmp, sz);
    free(tmp);
}

#endif //DATA_STRUCTURE_PREDEF_H