// #include "Swap.h"
#include "QuickSort.h"

typedef unsigned char byte;

void QuickSort(void* seq, const unsigned long long type_size, const unsigned long long elem_size, unsigned long long left, unsigned long long right, int (*comparator)(const void* x, const void* y)) {
	unsigned long long i, j;
	byte* list = (byte*)seq;
	byte * pivot_adr = list + type_size * ((left + right) / 2);

	while (i <= j)
	{
		while (comparator(list + (i * type_size), pivot_adr) < 0) i++;
		while (comparator(list + (j * type_size), pivot_adr) > 0) j--;

		if (i <= j)
		{
			swap(list + (i * type_size), list + (j * type_size), type_size);
			i++;
			j-- ;
		}
		
	}

}
void QuickSort(void* seq, const unsigned long long type_size, const unsigned long long length, int (*comparator)(const void* x, const void* y)) {
	QuicksortInner(seq, type_size, 0, length - 1, comparator);
}