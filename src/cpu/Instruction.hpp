#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include "Opcode.hpp"
#include <ostream>

struct Instruction {
    Opcode op;
    int Destiny_Register;
    int Register_1;
    int Register_2;

    Instruction(Opcode opc, int rd, int r1, int r2)
        : op(opc), Destiny_Register(rd), Register_1(r1), Register_2(r2) {}

    Instruction() 
        : op(ADD), Destiny_Register(0), Register_1(0), Register_2(0) {} 
};

std::ostream& operator<<(std::ostream& os, const Instruction& instr) {
    os << "Opcode: " << instr.op << ", Destino: R" << instr.Destiny_Register
       << ", R1: " << instr.Register_1 << ", R2: " << instr.Register_2;
    return os;
}

#endif
