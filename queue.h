#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include <stdlib.h>
#include <assert.h>

#define DEFINE_QUEUE(T) \
    typedef struct T##_Node *  T##_QuPtr; \
    typedef unsigned long long LenDtType; \
    typedef struct {    \
        T         data; \
        T##_QuPtr next; \
    } T##_Node;         \
    typedef struct {       \
        T##_Node * front;  \
        T##_Node * rear;   \
        LenDtType  length; \
    } T##_Queue;           \
    \
    T##_Queue * T##Queue() {                           \
        T##_Queue * qu = calloc(sizeof(T##_Queue), 1); \
        return qu;                                     \
    }                                                  \
    \
    void T##Enqueue(T##_Queue * const qu, T value) {      \
        T##_Node * elem = malloc(sizeof(T##_Node));       \
        elem->data = value;                               \
        elem->next = NULL;                                \
                                                          \
        if (qu->length) qu->rear->next = (T##_QuPtr)elem; \
        else            qu->front = elem;                 \
                                                          \
        qu->rear = elem;                                  \
        ++qu->length;                                     \
    }                                                     \
    \
    T T##Dequeue(T##_Queue * const qu) {           \
        assert(qu->length);                        \
                                                   \
        T         result        = qu->front->data; \
        T##_QuPtr will_be_front = qu->front->next; \
        free(qu->front);                           \
                                                   \
        if (!will_be_front) qu->rear = NULL;       \
        qu->front = (T##_Node *)will_be_front;     \
        --qu->length;                              \
                                                   \
        return result;                             \
    }                                              \
    \
    unsigned T##IsEmptyQueue(T##_Queue * const qu) { \
        const unsigned kLenBool  = !!qu->length,     \
                       kFntBool  = !!qu->front,      \
                       kRearBool = !!qu->rear;       \
                                                     \
        assert(!(kLenBool | kFntBool | kRearBool)    \
             || (kLenBool & kFntBool & kRearBool));  \
                                                     \
        return !kLenBool;                            \
    }
#define QUEUE(T)          T##_Queue *
#define NEW_QUEUE(T)      T##Queue()
#define ENQUEUE(T)        T##Enqueue
#define DEQUEUE(T)        T##Dequeue
#define IS_EMPTY_QUEUE(T) T##IsEmptyQueue

#endif //DATA_STRUCTURE_QUEUE_H