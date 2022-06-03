#include "Swap.h"
#include "CombSort.h"

void CombSort(void* seq, const unsigned long long type_size, const unsigned long long length, int (*comparator)(const void* x, const void* y)) {
    byte* list = (byte*)seq;
    int gap = length;
    double shrink_factor = 1.3;

    while (gap != 1) {
        gap /= shrink_factor;
        if(gap < 1) 
            gap = 1;
        for (int i = 0; i < (length - gap); i++)
            if (comparator(list + (i * type_size), list + ((i + gap) * type_size)) > 0)
                swap(list + (i * type_size), list + ((i + gap) * type_size), type_size);
    }
}