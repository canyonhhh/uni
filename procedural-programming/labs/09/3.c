#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    double x, y;
} Point;

typedef struct Stack{
    Point *points;
    int size;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point value);
Point top(Stack *stack);
Point pop(Stack *stack);
void destroyStack(Stack *stack);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

void initStack(Stack *stack){
    stack->points = NULL;
    stack->size = 0;
}

void printStack(Stack *stack){
    for(int i = 0; i < getStackSize(stack); ++i){
	printf("%f %f %f\n", stack->points[i].x, stack->points[i].y, getDistance(stack->points[i], createPoint(0, 0)));
    }
}

int getStackSize(Stack *stack){
    return(stack->size);
}

void push(Stack *stack, Point value){
    stack->points = realloc(stack->points, sizeof(Point) * (++stack->size));
    stack->points[stack->size - 1] = value;
}

Point top(Stack *stack){
    return(stack->points[stack->size - 1]);
}

Point pop(Stack *stack){
    Point ret = top(stack);

    stack->points = realloc(stack->points, sizeof(Point) * (--stack->size));

    return ret;
}

void destroyStack(Stack *stack){
    free(stack->points);
}

Point createPoint(double x, double y){
    Point p;
    p.x = x, p.y = y;
    return p;
}

double getDistance(Point a, Point b){
    return sqrt(powf(a.x - b.x, 2) + powf(a.y - b.y, 2));
}

int main(){
    Stack stack;

    initStack(&stack);

    push(&stack, createPoint(1, 2));
    push(&stack, createPoint(-5, 2));
    push(&stack, createPoint(-2, 3));
    push(&stack, createPoint(0, 0));
    push(&stack, createPoint(-40, 0));

    Point check = pop(&stack);

    printStack(&stack);

    destroyStack(&stack);
}
