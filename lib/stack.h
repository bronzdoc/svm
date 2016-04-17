#ifndef _SVM_STACK_H_
#define _SVM_STACK_H_
typedef struct {
    int a_stack[1024];
    int sp;
} Stack;

Stack *newStack();
void push(*Stack stack, int val);
int pop(*Stack stack);
int peek(*Stack stack)

#ifndef
