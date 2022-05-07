#include <stdio.h>
#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

int isFull() {
	if (top >= MAX_STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

int isEmpty() {
	if (top == -1)
		return 1;
	else
		return 0;
}

void push(int value) {
	if (isFull()) {
		printf("Stack is full\n");
		return;
	}
		stack[++top] = value;
}

int pop() {
	if (isEmpty()) {
		printf("Stack is empty\n");
		return;
	}
	return stack[top--];
}

void print() {
	for (int i = top; i >= 0; i--)
		printf("%d\n", stack[i]);
	printf("\n");
}

int main() {
	push(1);
	push(2);
	push(3);
	push(4);
	print();
	pop();
	print();

	return 0;
}