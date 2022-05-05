#include <stdlib.h>
#include <stdio.h>
#define MAX_COUNT 100

typedef struct {
	int data[MAX_COUNT];
	int size;
}heapType;

void insertHeap(heapType* h, int item) {
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

void printHeap(heapType* h) {
	int i;
	printf("My heap: ");
	for (i = 1; i <= h->size; i++)
		printf("%d ", h->data[i]);
	printf("\n");
}

int deleteHeap(HeapType* h) {
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
		//���� ������ �ڽ� �� �� ū ���� ���� ��ġ ->child
		child = current * 2;
		if (((child + 1) <= h->size) && (h->data[child] < h->data[child + 1]))
		child++;

		if (h->data[child] <= h->data[current])
			break;
		//�θ� �ڽ� �� ���� ��ȯ
		temp = h->data[child];
		h->data[child] = h->data[current];
		h->data[current] = temp;

		current = child;
	}
	return topdata;
}

void main() {
	heapType heap;
	heap.size = 0;

	int i,count;

	insertHeap(&heap, 17);
	insertHeap(&heap, 29);
	insertHeap(&heap, 27);
	insertHeap(&heap, 15);
	insertHeap(&heap, 34);
	printHeap(&heap);

	count = heap.size;
	for (i = 0; i < count; i++) {
		printf("deleted: %d\n", deleteHeap(&heap));
	}
}