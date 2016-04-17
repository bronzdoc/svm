#include <stdio.h>
#include "lib/stack.h"
#define EXIT 0

int fetch();
void eval(Stack*, int);

// Machine instructions
typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

// Instruction pointer
int ip = 0;

// Stack pointer
int sp = -1;

// VM state
int running = 1;

int
main(int argc, char *argv[])
{
    // VM Stack
    Stack *stack = newStack();
    while(running) {
        int instr = fetch();
        eval(stack, instr);
        ip++;
    }
    return EXIT;
}

int
fetch()
{
    return program[ip];
}

void
eval(Stack *stack, int instr)
{
    switch(instr) {
        case HLT: {
            running = 0;
            break;
        }
        case PSH: {
            push(stack, program[++ip]);
            //stack[++sp] = program[++ip];
            break;
        }
        case ADD: {
            int a = pop(stack);
            int b = pop(stack);
            push(stack, a + b);
            break;
        }
        case POP: {
            printf("=> %d\n", pop(stack));
            break;
        }
    }
}
