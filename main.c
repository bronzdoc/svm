#include <stdio.h>
#include "lib/svm.h"

#define EXIT 0

int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    SET, 90, A,
    MOV, A, B,
    PSH, 6,
    LR , B,
    POP,
    ADD,
    HLT
};

int
main(int argc, char *argv[])
{
    VM *vm = newVM(); // Create a new VM
    start(vm, program); // Run the VM
    return EXIT;
}




