#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define DEFINE_QUEUE(T) \
    typedef struct _##T##_QueueNode *  T##_QuPtr; \
    typedef struct _##T##_QueueNode { \
        T         data;               \
        T##_QuPtr next;               \
    } T##_QueueNode;                  \
    typedef struct {               \
        T##_QueueNode *    front;  \
        T##_QueueNode *    rear;   \
        unsigned long long length; \
    } T##_Queue;                   \
    \
    T##_Queue * T##Queue() {                           \
        T##_Queue * qu = calloc(1, sizeof(T##_Queue)); \
        return qu;                                     \
    }                                                  \
    \
    void T##Enqueue(T##_Queue * const qu, T value) {          \
        assert(qu->length < ULLONG_MAX);                      \
                                                              \
        T##_QueueNode * elem = malloc(sizeof(T##_QueueNode)); \
        elem->data = value;                                   \
        elem->next = NULL;                                    \
                                                              \
        if (qu->length) qu->rear->next = (T##_QuPtr)elem;     \
        else            qu->front      = elem;                \
                                                              \
        qu->rear = elem;                                      \
        ++qu->length;                                         \
    }                                                         \
    \
    T T##Dequeue(T##_Queue * const qu) {            \
        assert(qu->length);                         \
                                                    \
        T         result        = qu->front->data;  \
        T##_QuPtr will_be_front = qu->front->next;  \
        free(qu->front);                            \
                                                    \
        if (!will_be_front) qu->rear = NULL;        \
        qu->front = (T##_QueueNode *)will_be_front; \
        --qu->length;                               \
                                                    \
        return result;                              \
    }                                               \
    \
    void T##TestForNormalcyQu(T##_Queue * const qu) { \
        const unsigned kLenBool  = !!qu->length,      \
                       kFntBool  = !!qu->front,       \
                       kRearBool = !!qu->rear;        \
                                                      \
        assert(!(kLenBool | kFntBool | kRearBool)     \
             || (kLenBool & kFntBool & kRearBool));   \
    }                                                 \
    \
    unsigned T##IsEmptyQueue(T##_Queue * const qu) { \
        T##TestForNormalcyQu(qu);                    \
        return !qu->length;                          \
    }                                                \
    \
    unsigned T##IsFullQueue(T##_Queue * const qu) { \
        T##TestForNormalcyQu(qu);                   \
        return qu->length == ULLONG_MAX;            \
    }
#define QUEUE(T)          T##_Queue *
#define NEW_QUEUE(T)      T##Queue()
#define ENQUEUE(T)        T##Enqueue
#define DEQUEUE(T)        T##Dequeue
#define IS_EMPTY_QUEUE(T) T##IsEmptyQueue
#define IS_FULL_QUEUE(T)  T##IsFullQueue

#endif //DATA_STRUCTURE_QUEUE_H