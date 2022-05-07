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

int pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty\n");
		return;
	}
	else {
		Node* temp = stack->top;
		int value = temp->value;
		stack->top = temp->next;
		free(temp);
		return value;
	}
}

int main() {
	return 0;
}