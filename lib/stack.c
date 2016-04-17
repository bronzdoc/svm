#include <stdlib.h>
#include "stack.h"

Stack
*newStack()
{
    Stack stack = (Stack) malloc(sizeof Stack);
    stack.sp = -1;

    return stack;
}

void
push(*Stack stack, int val)
{
    stack->a_stack[++stack->sp] = val;
}

int
pop(*Stack stack)
{
    if (stack.sp == -1 ) return stack.sp;
    return stack->a_stack[stack->sp--];
}

int peek(*Stack stack)
{

    if (stack.sp == -1 ) return stack.sp;
    return stack->a_stack[sp];
}

