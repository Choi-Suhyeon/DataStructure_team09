#include "Swap.h"
#include "ShellSort.h"

void ShellSort(void* seq, const unsigned long long type_size, const unsigned long long length, int (*comparator)(const void* x, const void* y)) {
    byte* list = (byte*)seq;
    for (int gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i += gap) {
            for (int j = i; j > 0; j -= gap) {
                if (comparator(list + ((j - 1) * type_size), list + (j * type_size)) > 0)
                    swap(list + ((j - 1) * type_size), list + (j * type_size), type_size);
            }
        }
    }
}
