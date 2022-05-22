#include "SelectSortArray.h"

void swap(void * const fst, void * const snd, const unsigned long long sz) {
    byte * const tmp = (byte *)malloc(sz);
    memcpy(tmp, fst, sz);
    memcpy(fst, snd, sz);
    memcpy(snd, tmp, sz);
    free(tmp);
}

void SelectSortArray(void * seq, const unsigned long long type_size, const unsigned long long elem_size, int (*comparator)(const void * x, const void * y))
{
    byte* lst = (byte*) seq;
    int i, j;
    int minindex = 0;

	for(i = 0; i< elem_size - 1; i++) {
		for(j = i + 1; j< elem_size; j++) {
            if (comparator(lst + (minindex * type_size), lst + (j * type_size)) > 0){
                minindex = j;
            }
		}
        if(i != minindex)   swap(lst + (type_size * i), lst + (type_size * minindex), type_size);
	}
}