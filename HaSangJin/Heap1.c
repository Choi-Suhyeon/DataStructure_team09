#include <stdlib.h>
#include <stdio.h>
#define MAX_COUNT 100

typedef struct _heaptype{
	int data[MAX_COUNT];
	int size;
}heapType;

void insertHeap(heapType* h, int item, int (*comparator)(const void * x, const void * y)) {
	int index;
	if (h->size >= MAX_COUNT - 1) {
		printf("Full!!\n");
		return;
	}


	h->size++;
	index = h->size;
	h->data[index] = item;

	while ((index !=1)&&(comparator(h->data[index], h->data[index/2]) > 0)) {
		int temp = h->data[index / 2];
		h->data[index / 2] = h->data[index];
		h->data[index] = temp;

		index = index / 2;
	}
}

void printHeap(heapType* h) {
	int i;
	printf("My heap: ");
	for (i = 1; i <= h->size; i++)
		printf("%d ", h->data[i]);
	printf("\n");
}

int deleteHeap(heapType* h , int (*comparator)(const void * x, const void * y)) {
	int current, child;
	int temp;
	int topdata = h->data[1];
	if (h->size == 0) {
		printf("Empty!!\n");
	}
    else {
        h->data[1]= h->data[h->size];
        h->size--;

        current = 1;
        while ((current * 2) <= h->size)
        {
            
            child = current * 2;
            if (((child + 1) <= h->size) && (comparator(h->data[child + 1], h->data[child])))
            child++;

            if (comparator(h->data[current],h->data[child]) >= 0)
                break;
            
            temp = h->data[child];
            h->data[child] = h->data[current];
            h->data[current] = temp;

            current = child;
        }
        return topdata;
    }
}