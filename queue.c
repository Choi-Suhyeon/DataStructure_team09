#include "queue.h"

Queue * queue() {
    Queue * qu = calloc(sizeof(Queue), 1);
    return qu;
}

void put(Queue * const qu, void * const value) {
    Node * elem = malloc(sizeof(Node));
    elem->data = value;
    elem->next = NULL;

    if (qu->length) qu->rear->next = (QuPtr)elem;
    else            qu->front = elem;
    qu->rear = elem;
    ++qu->length;
}

void * get(Queue * const qu) {
    if (!qu->length) return NULL;

    void * result        = qu->front->data;
    QuPtr  will_be_front = qu->front->next;

    free(qu->front);
    qu->front = (Node *)will_be_front;
    --qu->length;

    return result;
}