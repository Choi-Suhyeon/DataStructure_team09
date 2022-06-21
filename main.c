#include <stdio.h>
#include "countingSort.h"
#include "binaryInsertionSort.h"
#include "queue.h"
#include "list.h"
#include "stack.h"
#include "heap.h"

typedef int * ip;
typedef char * str;

typedef struct {
   int a;
   double b;
} Tmp;

DEFINE_QUEUE(Tmp)
DEFINE_QUEUE(unsigned)
DEFINE_QUEUE(ip)

DEFINE_LIST(Tmp)
DEFINE_LIST(int)
DEFINE_LIST(str)

DEFINE_STACK(Tmp)

DEFINE_HEAP(int)
DEFINE_HEAP(char)

// 최대 힙
int compHeap(const void * x, const void * y) {
    int using_x = *(int *)x,
        using_y = *(int *)y;

    return using_x < using_y ? 1  :
           using_x > using_y ? -1 :
           0;
}

int compStr(const void * x, const void * y) {
    return strcmp(*(char **)x, *(char **)y);
}

int compInt(const void * x, const void * y) {
    return *(int *)x - *(int *)y;
}

int main() {
    //HEAP
    int arr[5] = { 4, 8, 2, 7, 9 };
    HEAP_SORT(int)(arr, 5, compHeap);
    for (unsigned i = 0; i < 5; i++) printf("%d\n", arr[i]);

    HEAP(int) heap = MAKE_HEAP(int)(arr, 5, 4, compHeap);

    unsigned len_heap = heap->length;
    for (unsigned i = 0; i < len_heap; i++) {
        printf("%d, ", POP_HEAP(int)(heap));
        printf("%llu %llu\n", heap->length, heap->capacity);
    }
    printf("%u\n", IS_EMPTY_HEAP(int)(heap));

    // STACK
    STACK(Tmp) tst = NEW_STACK(Tmp);
    PUSH(Tmp)(tst, (Tmp) {1, 1.12});
    printf("[debug] %p %llu\n", tst->top, tst->length);
    PUSH(Tmp)(tst, (Tmp) {2, 2.34});
    printf("[debug] %p %llu\n", tst->top, tst->length);
    unsigned long long len;
    printf("%llu\n", len = tst->length);
    for (int i = 0; i < len; i++) {
        printf("%d\n", POP(Tmp)(tst).a);
        printf("[debug] %p %llu\n", tst->top, tst->length);
    }
    printf("%u\n", IS_EMPTY_STACK(Tmp)(tst));
    DELETE_STACK(Tmp)(tst);
    printf("[debug] %p %llu\n", tst->top, tst->length);

    // QUEUE
    printf("QUEUE\n");
    QUEUE(Tmp) tqu = NEW_QUEUE(Tmp);
    ENQUEUE(Tmp)(tqu, (Tmp) { 3, 3.14 });
    ENQUEUE(Tmp)(tqu, (Tmp) { 2, 2.11 });

    printf("isEmpty? : %u\n\n", IS_EMPTY_QUEUE(Tmp)(tqu));
    unsigned length = tqu->length;
    for (unsigned i = 0; i < length; i++) {
        printf("%d\n", DEQUEUE(Tmp)(tqu).a);
    }
    printf("isEmpty? : %u\n\n", IS_EMPTY_QUEUE(Tmp)(tqu));
    ENQUEUE(Tmp)(tqu, (Tmp) { 4, 3.14 });
    ENQUEUE(Tmp)(tqu, (Tmp) { 5, 2.11 });
    DELETE_QUEUE(Tmp)(tqu);

    // LIST
    puts("LIST");
    LIST(str) ls = NEW_LIST(str);

    APPEND(str)(ls, "security");
    APPEND(str)(ls, "bestOfTheBest");
    APPEND(str)(ls, "korea");
    APPEND(str)(ls, "cyber");
    APPEND(str)(ls, "although");
    APPEND(str)(ls, "university");

    SORT_LIST(str)(ls, compStr);

    ITERATOR(str) iter = NEW_ITERATOR(str)(ls);
    while (HAS_NEXT(str)(iter)) {
        puts(NEXT(str)(iter));
    }

    DELETE_LIST(str)(ls);
    DELETE_ITERATOR(str)(iter);

    puts("LIST");
    LIST(int) lsi = NEW_LIST(int);

    APPEND(int)(lsi, 12);
    APPEND(int)(lsi, 18);
    APPEND(int)(lsi, 7);
    APPEND(int)(lsi, 1);
    APPEND(int)(lsi, 11);
    APPEND(int)(lsi, 20);

    SORT_LIST(int)(lsi, compInt);

    ITERATOR(int) it = NEW_ITERATOR(int)(lsi);
    while (HAS_NEXT(int)(it)) {
        printf("%d\n", NEXT(int)(it));
    }

    DELETE_LIST(str)(ls);
    DELETE_ITERATOR(str)(iter);

    // int arr2[15] = { 10, 6, 78, 13, 34, 70, 82, 55, 5, 39, 75, 12, 81, 38, 76 };

    int arr2[30] = { 1, 3, 2, 3, 3, 4, 0, 0, 0, 6, 2, 5, 8, 1, 5, 1, 4, 5, 7, 2, 3, 1, 0, 8, 2, 5, 4, 2, 5, 0 };
    // countingSort(arr2, 30);
    binaryInsertionSort(arr2, 30);
    for (int i = 0; i < 30; i++) {
        printf("[%d]: %d ", i, arr2[i]);
    }
    puts("");

    return 0;
}
