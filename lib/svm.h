#ifndef _SVM_REGISTERS_H
#define _SVM_REGISTERS_H
int fetch();
void eval(int);

// Instruction Set
typedef enum { PSH, ADD, POP, SET, HLT } InstructionSet;

// Registers
typedef enum { A, B, C, D, E, F, NUM_OF_REGISTERS } Registers;

typedef struct vm_tag {
   Stack *stack;        // vm stack machie stack
   int ip;              // vm instruction pointer
   InstructionSet is;   // vm instruction set
   Registers registers; // vm registers
   int state;           // vm state, may be running may not
} VM;

void eval(VM *vm, int instr);
void start(VM *vm, int program[]);
void fetch(VM *vm, int program[]);
VM *vm newVM();


#endif


