#include <stdio.h>
#include "lib/vm.h"

#define EXIT 0

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

int
main(int argc, char *argv[])
{
    VM *vm = newVM(); // Create a new VM
    start(vm); // Run the VM
    return EXIT;
}




