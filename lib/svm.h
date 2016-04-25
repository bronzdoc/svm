#ifndef _SVM_REGISTERS_H
#define _SVM_REGISTERS_H
 #include "stack.h"

// Instruction Set
typedef enum {
    PSH, // Push a value to the stack
    ADD, // Add to numbers from the stack 
    POP, // Pop value from the stack
    SET, // Set value of register
    HLT, // Stops the vm
    MOV, // Moves value of register x to regster z
    LR,  // Loads register to the stack
} InstructionSet;

// Registers
typedef enum { A, B, C, D, E, F, NUM_OF_REGISTERS } Registers;

typedef struct vm_tag {
   Stack *stack;                    // vm stack machie stack
   int ip;                          // vm instruction pointer
   InstructionSet is;               // vm instruction set
   int registers[NUM_OF_REGISTERS]; // vm registers
   int *process;                    // vm process, a program that the vm understand
   int state;                       // vm state, may be running may not
} VM;

void eval(VM *vm, int instr);
void start(VM *vm, int program[]);
int fetch(VM *vm);
VM * newVM();

#endif
