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

int main() {
	return 0;
}