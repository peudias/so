#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include "Opcode.hpp"

struct Instruction {
    Opcode op;
    int Destiny_Register;
    int Register_1;
    int Register_2;

    Instruction(Opcode opc, int rd, int r1, int r2)
        : op(opc), Destiny_Register(rd), Register_1(r1), Register_2(r2) {}
};

#endif
