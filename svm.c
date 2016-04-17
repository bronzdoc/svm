#include <stdio.h>
#define EXIT 0

int fetch();
void eval(int);

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

// VM Stack
int stack[256];

// VM state
int running = 1;

int
main(int argc, char *argv[])
{
    while(running) {
        int instr = fetch();
        eval(instr);
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
eval(int instr)
{
    switch(instr) {
        case HLT: {
            running = 0;
            break;
        }
        case PSH: {
            stack[++sp] = program[++ip];
            break;
        }
        case ADD: {
            int a = stack[sp--];
            int b = stack[sp--];
            int result = a + b;

            stack[++sp] = result;
            break;
        }
        case POP: {
            printf("=> %d\n", stack[sp--]);
            break;
        }
    }
}
