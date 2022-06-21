#ifndef DATA_STRUCTURE_PREDEF_H
#define DATA_STRUCTURE_PREDEF_H

#include <memory.h>
#include <stdlib.h>

typedef unsigned char      byte;
typedef unsigned long long uLLong;
typedef int (* CompFn)(const void *, const void *);
typedef enum {
    UChar, UShort, UInt, ULong, ULLong
} UNumType;

void swap(void *, void *, uLLong);

#endif //DATA_STRUCTURE_PREDEF_H