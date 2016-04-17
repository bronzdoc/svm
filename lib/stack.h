#ifndef __SVM_STACK_H__
#define __SVM_STACK_H__
#define STACK_MAX_SIZE 1024
struct stack_tag {
    int items[STACK_MAX_SIZE];
    int sp;
};
typedef struct stack_tag Stack ;

Stack * newStack();
void push(Stack *stack, int val);
int pop(Stack *stack);
int peek(Stack *stack);

#endif
