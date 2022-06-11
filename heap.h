#ifndef DATA_STRUCTURE_HEAP_H
#define DATA_STRUCTURE_HEAP_H

#include <limits.h>
#include <assert.h>
#include <math.h>
#include "predef.h"

#define L_CHILD(ME) ((ME) << 1)
#define R_CHILD(ME) (((ME) << 1) + 1)
#define PARENT(ME)  ((uLLong)ceil(((double)(ME) - 1) / 2))

#define DEFINE_HEAP(T) \
    typedef struct {          \
        CompFn comparator;    \
        uLLong length;        \
        uLLong capacity;      \
        uLLong capacity_unit; \
        T *    heap;          \
    } T##_Heap;               \
    \
    T##_Heap * T##Heap(int unit, CompFn comp) {            \
        if (unit < 1) unit = 50;                           \
                                                           \
        T##_Heap * hp = malloc(sizeof(T##_Heap));          \
        hp->length        = 0;                             \
        hp->comparator    = comp;                          \
        hp->capacity      = unit;                          \
        hp->capacity_unit = unit;                          \
        hp->heap          = (T *)malloc(unit * sizeof(T)); \
                                                           \
        return hp;                                         \
    }                                                      \
    \
    void T##PushHeap(T##_Heap * hp, T value) {                         \
        assert(hp->length < ULLONG_MAX);                               \
                                                                       \
        if (hp->length + 1 == hp->capacity) {                          \
            const uLLong kAbleToExpand = ULLONG_MAX - hp->length;      \
            hp->capacity += kAbleToExpand < hp->capacity_unit          \
                    ? kAbleToExpand                                    \
                    : hp->capacity_unit;                               \
                                                                       \
            T * new_heap = (T *)malloc(hp->capacity * sizeof(T));      \
            memmove(new_heap, hp->heap, (hp->length + 1) * sizeof(T)); \
                                                                       \
            free(hp->heap);                                            \
            hp->heap = new_heap;                                       \
        }                                                              \
                                                                       \
        hp->heap[++hp->length] = value;                                \
                                                                       \
        for (uLLong idx = hp->length; idx > 1;) {                      \
            const uLLong kPrtIdx = PARENT(idx);                        \
                                                                       \
            T * prt_adr = hp->heap + kPrtIdx,                          \
              * crt_adr = hp->heap + idx;                              \
                                                                       \
            if (hp->comparator(prt_adr, crt_adr) != 1) break;          \
                                                                       \
            swap(crt_adr, prt_adr, sizeof(T));                         \
            idx = kPrtIdx;                                             \
        }                                                              \
    }                                                                  \
    \
    T T##PopHeap(T##_Heap * hp) {                                                        \
        assert(hp->length);                                                              \
                                                                                         \
        T value = hp->heap[1];                                                           \
                                                                                         \
        hp->heap[1] = hp->heap[hp->length];                                              \
        memset(hp->heap + hp->length--, 0, sizeof(T));                                   \
                                                                                         \
        for (uLLong idx = 1; idx < hp->length;) {                                        \
            const uLLong kLChildIdx = L_CHILD(idx),                                      \
                         kRChildIdx = R_CHILD(idx);                                      \
                                                                                         \
            T * crt_adr = hp->heap + idx,                                                \
              * l_c_adr = hp->heap + kLChildIdx,                                         \
              * r_c_adr = hp->heap + kRChildIdx;                                         \
                                                                                         \
            const int kLCmp         = hp->comparator(crt_adr, l_c_adr),                  \
                      kRCmp         = hp->comparator(crt_adr, r_c_adr),                  \
                      kIsRAdvisable = hp->comparator(l_c_adr, r_c_adr);                  \
                                                                                         \
            if (kLCmp != 1 && kRCmp != 1) break;                                         \
                                                                                         \
            const uLLong kToSwapedIdx = kLCmp == 1 && (kRCmp != 1 || kIsRAdvisable != 0) \
                    ? kLChildIdx                                                         \
                    : kRChildIdx;                                                        \
                                                                                         \
            swap(crt_adr, hp->heap + kToSwapedIdx, sizeof(T));                           \
            idx = kToSwapedIdx;                                                          \
        }                                                                                \
                                                                                         \
        if (hp->length + 1 < hp->capacity - hp->capacity_unit) {                         \
            hp->capacity -= hp->capacity_unit;                                           \
            T * new_heap = malloc(hp->capacity * sizeof(T));                             \
            memmove(new_heap, hp->heap, (hp->length + 1) * sizeof(T));                   \
                                                                                         \
            free(hp->heap);                                                              \
            hp->heap = new_heap;                                                         \
        }                                                                                \
                                                                                         \
        return value;                                                                    \
    }                                                                                    \
    \
    T##_Heap * T##MakeHeap(T * arr, uLLong len, int unit, CompFn comp) { \
        if (unit < 1) unit = 50;                                         \
                                                                         \
        const uLLong kIncLen = len + 1;                                  \
                                                                         \
        T##_Heap * hp = malloc(sizeof(T##_Heap));                        \
        hp->length        = 0;                                           \
        hp->comparator    = comp;                                        \
        hp->capacity      = kIncLen % unit                               \
                ? unit * (kIncLen / unit + 1)                            \
                : kIncLen;                                               \
        hp->capacity_unit = unit;                                        \
        hp->heap          = (T *)malloc(hp->capacity * sizeof(T));       \
                                                                         \
        while (len--) T##PushHeap(hp, *arr++);                           \
                                                                         \
        return hp;                                                       \
    }                                                                    \
    \
    void T##DeleteHeap(T##_Heap * hp) { \
        free(hp->heap);                 \
        free(hp);                       \
    }                                   \
    \
    unsigned T##IsEmptyHeap(T##_Heap * hp) { \
        return !hp->length;                  \
    }                                        \
    \
    unsigned T##IsFullHeap(T##_Heap * hp) { \
        return hp->length == ULLONG_MAX;    \
    }                                       \
    \
    void T##HeapSort(T * arr, uLLong len, CompFn comp) {            \
        T##_Heap * tmp_heap = T##MakeHeap(arr, len, len + 1, comp); \
        while (len--) *arr++ = T##PopHeap(tmp_heap);                \
        T##DeleteHeap(tmp_heap);                                    \
    }
#define HEAP(T)          T##_Heap *
#define NEW_HEAP(T)      T##Heap
#define MAKE_HEAP(T)     T##MakeHeap
#define PUSH_HEAP(T)     T##PushHeap
#define POP_HEAP(T)      T##PopHeap
#define DELETE_HEAP(T)   T##DeleteHeap
#define IS_EMPTY_HEAP(T) T##IsEmptyHeap
#define IS_FULL_HEAP(T)  T##IsFullHeap
#define HEAP_SORT(T)     T##HeapSort

#endif //DATA_STRUCTURE_HEAP_H