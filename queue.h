#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include <stdlib.h>


typedef struct Node *      QuPtr;
typedef unsigned long long LenDtType;
typedef struct {
    void * data;
    QuPtr  next;
} Node;
typedef struct {
    Node *    front;
    Node *    rear;
    LenDtType length;
} Queue;

Queue * queue();

void   put(Queue *, void *);
void * get(Queue *);

#endif //DATA_STRUCTURE_QUEUE_H