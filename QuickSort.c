#include "predef.h"

typedef unsigned char byte;

void QuickSort(void* seq, const unsigned long long type_size, const unsigned long long length, int (*comparator)(const void* x, const void* y)) {
	unsigned long long i = 0, j = length - 1;
	byte* list = (byte*)seq;
	byte * pivot_adr = list + type_size * (int)(length/ 2);

	while (i <= j)
	{
		while (comparator(list + (i * type_size), pivot_adr) < 0) i++;
		while (comparator(list + (j * type_size), pivot_adr) > 0) j--;

		if (i != j)	swap(list + (i * type_size), list + (j * type_size), type_size);
        i++;
		j--;
	}

    if(0 < j)   QuickSort(list,type_size,j,comparator);
    else if (i < length)    QuickSort(list + (i * type_size), type_size, length - i, comparator);

}

int icomp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int list[11] = {10,39,781,82,662,8,5,50,6,87,46};
    QuickSort(list,sizeof(int),11,icomp);
    for (int i = 0; i < 11; i++)    printf("%d ", list[i]);
}