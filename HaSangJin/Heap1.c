#include <stdlib.h>
#include <stdio.h>
#define MAX_COUNT 100

typedef struct {
	int data[MAX_COUNT];
	int size;
}HeapType;

void InsertHeap(HeapType* h, int item) {
	int index;
	if (h->size >= MAX_COUNT - 1) {
		printf("Full!!\n");
		return;
	}


	h->size++;
	index = h->size;
	h->data[index] = item;

	while ((index !=1)&&(h->data[index/2]<h->data[index])) {
		int temp = h->data[index / 2];
		h->data[index / 2] = h->data[index];
		h->data[index] = temp;

		index = index / 2;

	}
}

void PrintHeap(HeapType* h) {
	int i;
	printf("My heap: ");
	for (i = 1; i <= h->size; i++)
		printf("%d ", h->data[i]);
	printf("\n");
}

int DeleteHeap(HeapType* h) {
	int current, child;
	int temp;
	int topdata = h->data[1];
	if (h->size == 0) {
		printf("Empty!!\n");
		return;
	}
	h->data[1]= h->data[h->size];
	h->size--;

	current = 1;
	while ((current * 2) <= h->size)
	{
		//왼쪽 오른쪽 자식 중 더 큰 값을 가진 위치 ->child
		child = current * 2;
		if (((child + 1) <= h->size) && (h->data[child] < h->data[child + 1]))
		child++;

		if (h->data[child] <= h->data[current])
			break;
		//부모 자식 간 값을 교환
		temp = h->data[child];
		h->data[child] = h->data[current];
		h->data[current] = temp;

		current = child;
	}
	return topdata;
}

void main() {
	HeapType heap;
	heap.size = 0;

	int i,count;

	InsertHeap(&heap, 17);
	InsertHeap(&heap, 29);
	InsertHeap(&heap, 27);
	InsertHeap(&heap, 15);
	InsertHeap(&heap, 34);
	PrintHeap(&heap);

	count = heap.size;
	for (i = 0; i < count; i++) {
		printf("deleted: %d\n", DeleteHeap(&heap));
	}
}