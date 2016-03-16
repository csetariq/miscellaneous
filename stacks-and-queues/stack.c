#include <stdio.h>

#define MAX 3

int top = -1;

int is_full(int *stack) {
    return top == MAX - 1;
}

int is_empty(int *stack) {
    return top == -1;
}

void push(int *stack, int item) {
    if (is_full(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = item;        
}

int pop(int *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    int stack[MAX];
    push(stack, 5);
    push(stack, 7);
    printf("pop() %d\n", pop(stack));
    push(stack, 7);
    push(stack, 7);
    printf("gonna overflow?\n");
    push(stack, 7);// overflow
    pop(stack);
    pop(stack);
    pop(stack);
    printf("gonna underflow?\n");
    pop(stack);
    return 0;
}

