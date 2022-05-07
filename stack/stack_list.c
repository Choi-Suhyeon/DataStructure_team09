#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
}Node;

typedef struct {
	Node* top;
}Stack;

void init(Stack* stack) {
	stack->top = NULL;
}

int isEmpty(Stack* stack) {
	if (stack->top == NULL)
		return 1;
	else
		return 0;
}

void push(Stack* stack, int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = stack->top;
	stack->top = node;
}

void pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty\n");
		return;
	}
	else {
		Node* temp = stack->top;
		stack->top = temp->next;
		free(temp);
	}
}

void print(Stack* stack) {
	Node* temp = stack->top;

	for (temp = stack->top; temp != NULL; temp = temp->next)
		printf("%d\n", temp->value);
	printf("\n");
}

int main() {
	Stack s;

	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	print(&s);
	pop(&s);
	print(&s);

	return 0;
}