#include "stack.h"
#include "svm.h"

// Create a new VM
VM *vm
newVM()
{
    Stack *stack = newStack();
    VM *vm = (VM*) malloc(sizeof(VM));
    vm->stack = stack;
    vm->ip = -1;
    vm->state = 0;

    return vm;
}

// Eval VM instruction
void
eval(VM *vm, int instr)
{
    switch(instr) {
        case HLT: {
            vm->state = 0;
            break;
        }
        case PSH: {
            push(vm->stack, program[++ip]);
            break;
        }
        case ADD: {
            int a = pop(vm->stack);
            int b = pop(vm->stack);
            push(vm->stack, a + b);
            break;
        }
        case POP: {
            printf("=> %d\n", pop(vm->stack));
            break;
        }
    }
}

// Start VM
void
start(VM *vm, int programa[])
{
    vm->state = 1;
    while(vm->state) {
        int instr = fetch(vm, program);
        eval(vm, instr);
        vm->ip++;
    }
}

// Fetch program next instruction
int
fetch(VM *vm, int program[])
{
    return program[vm->ip];
}

