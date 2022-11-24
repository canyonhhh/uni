#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int *p;
    int size;
} Stack;

void initStack(Stack *stack){
    stack->p = 0;
    stack->size = 0;
}

void printStack(Stack *stack){
    for(int i = 0; i < stack->size; ++i){
	printf("%d ", stack->p[i]);
    }
    printf("\n");
}

int getStackSize(Stack *stack){
    return(stack->size);
}

void push(Stack *stack, int value){
    stack->p = realloc(stack->p, sizeof(int) * (++stack->size));
    stack->p[stack->size - 1] = value;
}

int top(Stack *stack){
    return(stack->p[stack->size - 1]);
}

int pop(Stack *stack){
    int ret = top(stack);

    stack->p = realloc(stack->p, sizeof(int) * (--stack->size));

    return ret;
}

void destroyStack(Stack *stack){
    free(stack->p);
}

int main(){
    Stack stack;
    initStack(&stack);

    push(&stack, 5);
    push(&stack, 1);
    push(&stack, 20);
    push(&stack, 31);
    push(&stack, 25);

    printStack(&stack);
    printf("pop: %d\n", pop(&stack));
    push(&stack, 321);
    printf("top: %d\n", top(&stack));
    printStack(&stack);

    destroyStack(&stack);
}
