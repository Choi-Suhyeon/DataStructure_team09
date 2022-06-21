#include "Swap.h"
#include "InsertionSortArray.h"

void InsertionSortArray(void* seq, const unsigned long long type_size, const unsigned long long length, int (*comparator)(const void* x, const void* y)) {
    byte* list = (byte*)seq;
    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0; j--) {
            if (comparator(list + ((j - 1) * type_size), list + (j * type_size)) > 0)
                swap(list + ((j - 1) * type_size), list + (j * type_size), type_size);
        }
    }
}