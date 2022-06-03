#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define DEFINE_STACK(T) \
   typedef struct _##T##_StackNode *  T##_StPtr; \
   typedef struct _##T##_StackNode { \
      T           data;              \
      T##_StPtr next;                \
   } T##_StackNode;                  \
   typedef struct {                \
        T##_StackNode *    top;    \
        unsigned long long length; \
    } T##_Stack;                   \
    \
    T##_Stack * T##Stack() {                                       \
        T##_Stack * st = (T##_Stack*)calloc(1, sizeof(T##_Stack)); \
        return st;                                                 \
    }                                                              \
    \
    void T##Push(T##_Stack * const st, T value) {                             \
        assert(st->length < ULLONG_MAX);                                      \
                                                                              \
        T##_StackNode * node = (T##_StackNode*)malloc(sizeof(T##_StackNode)); \
        node->data = value;                                                   \
        node->next = st->top;                                                 \
        st->top = (T##_StPtr)node;                                            \
        ++st->length;                                                         \
    }                                                                         \
    \
    T T##Pop(T##_Stack * const st) {    \
        assert(st->length);             \
                                        \
        T##_StackNode * temp = st->top; \
        T result = temp->data;          \
        st->top = temp->next;           \
        free(temp);                     \
        --st->length;                   \
                                        \
        return result;                  \
    }                                   \
    \
    void T##DeleteStack(T##_Stack * const st) {          \
        while (st->length) {                             \
            T##_StackNode * next_node = st->top->next;   \
                                                         \
            free(st->top);                               \
            st->top = next_node;                         \
            --st->length;                                \
        }                                                \
                                                         \
        free(st);                                        \
    }                                                    \
    \
    void T##TestForNormalcySt(T##_Stack * const st) { \
        const unsigned kLenBool  = !!st->length,      \
                       kTopBool  = !!st->top;         \
                                                      \
        assert(!(kLenBool | kTopBool)                 \
             || (kLenBool & kTopBool));               \
    }                                                 \
    \
    unsigned T##IsEmptyStack(T##_Stack * const st) { \
        T##TestForNormalcySt(st);                    \
        return !st->length;                          \
    }                                                \
    \
    unsigned T##IsFullStack(T##_Stack * const st) { \
        T##TestForNormalcySt(st);                   \
        return st->length == ULLONG_MAX;            \
    }
#define STACK(T)          T##_Stack *
#define NEW_STACK(T)      T##Stack()
#define PUSH(T)           T##Push
#define POP(T)            T##Pop
#define DELETE_STACK(T)   T##DeleteStack
#define IS_EMPTY_STACK(T) T##IsEmptyStack
#define IS_FULL_STACK(T)  T##IsFullStack

#endif
