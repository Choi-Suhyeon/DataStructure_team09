#include "SelectSortArray.h"

void swap(void * const fst, void * const snd, const unsigned sz) {
    byte * const tmp = (byte *)malloc(sz);
    memcpy(tmp, fst, sz);
    memcpy(fst, snd, sz);
    memcpy(snd, tmp, sz);
    free(tmp);
}

void SelectSortArray(void * seq, unsigned char type_size, const unsigned long long elem_size, int (*comparator)(const void * x, const void * y))
{
    byte* lst = (byte*) seq;
    int i, j;
    byte* min = lst;

	for(i=0; i< elem_size / 2; i++) {
        byte* tmp = lst + (type_size * i);
		for(j = 0; j< elem_size - i; j++) {
            if (comparator(min, tmp + (j * type_size)) > 0){
                min = tmp + (j * type_size);
            }
		}
        swap(lst + (type_size * i), min, type_size);
	}
}
