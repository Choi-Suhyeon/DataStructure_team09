#include "Swap.h"
#include "BubbleSort.h"

void BubbleSort(void * seq, const unsigned long long type_size, const unsigned long long elem_size, int (*comparator)(const void * x, const void * y)){
    byte* list = (byte*) seq;
    for (unsigned long long i = elem_size - 1; i > 0; i--) {
        for (int p = 0; p < i; p++) {
            if (comparator(list + (p * type_size), list + ((p+1) * type_size)) > 0) {
                swap(list + (p * type_size), list + ((p+1) * type_size) , type_size);
            }
        }
    }
}