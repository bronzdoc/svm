#include "stdlib.h"
#include "stdio.h"
#include "stack.h"
#include "svm.h"

// Create a new VM
VM *
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
            push(vm->stack, vm->process[++vm->ip]);
            break;
        }
        case ADD: {
            int a = pop(vm->stack);
            int b = pop(vm->stack);
            push(vm->stack, a + b);
            break;
        }
        case MOV: {
            vm->registers[vm->process[vm->ip + 1]] = vm->registers[vm->process[vm->ip + 2]];
            vm->ip = vm->ip + 2;
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
start(VM *vm, int program[])
{
    vm->process = program;
    vm->state = 1;
    vm->ip++;
    while(vm->state) {
        int instr = fetch(vm);
        eval(vm, instr);
        vm->ip++;
    }
}

// Fetch program next instruction
int
fetch(VM *vm)
{
    return vm->process[vm->ip];
}

