#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack*
newStack()
{
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->sp = -1;

    return stack;
}

void
push(Stack *stack, int val)
{
    if (stack->sp >= STACK_MAX_SIZE) {
        printf("Error: Stack overflow");
        exit(1);
    }

    stack->items[++stack->sp] = val;
}

int
pop(Stack *stack)
{
    if (stack->sp == -1) {
        return 0;
    }

    return stack->items[stack->sp--];
}

int 
isEmpty(Stack *stack)
{
    if (stack->sp == -1) {
        return 1;
    }

    return 0;
}

int
peek(Stack *stack)
{
    if (stack->sp == -1) {
        return stack->sp;
    }

    return stack->items[stack->sp];
}

