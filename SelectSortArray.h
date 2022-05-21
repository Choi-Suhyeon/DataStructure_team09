#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef unsigned char byte;

void SelectSortArray(void * seq, unsigned char type_size, const unsigned long long elem_size, int (*comparator)(const void * x, const void * y));
void swap(void * const fst, void * const snd, const unsigned sz);
