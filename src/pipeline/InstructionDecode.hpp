#ifndef INSTRUCTIONDECODE_HPP
#define INSTRUCTIONDECODE_HPP

#include "../cpu/Instruction.hpp"
#include "../cpu/Registers.hpp"
#include <iostream>

struct DecodedInstruction {
    int value1;
    int value2;
    int destiny;
    Opcode opcode;
};

DecodedInstruction InstructionDecode(const Instruction& instr, const Registers& regs){
    DecodedInstruction decoded;
    decoded.opcode = instr.op;
    decoded.destiny = instr.Destiny_Register;
    decoded.value1 = regs.get(instr.Register_1);
    decoded.value2 = regs.get(instr.Register_2);
    return decoded;
}

#endif