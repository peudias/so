#ifndef WRITEBACK_HPP
#define WRITEBACK_HPP

#include "InstructionDecode.hpp"
#include "../cpu/Registers.hpp"
#include <iostream>

void WriteBack(const DecodedInstruction& decoded, int resultado, Registers& regs) {
    if (decoded.opcode == ADD || decoded.opcode == SUB || decoded.opcode == LOAD) {
        regs.set(decoded.destiny, resultado); // Escreve o resultado no registrador de destino
    }
}

#endif