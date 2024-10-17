#ifndef EXECUTE_HPP
#define EXECUTE_HPP

#include "InstructionDecode.hpp"
#include "../cpu/UnidadeControle.hpp"
#include "../mainMemory/RAM.hpp"
#include <iostream>

void Execute(const DecodedInstruction& decoded, Registers& regs, RAM& ram, UnidadeControle& uc) {
    uc.executarInstrucao(decoded, regs, ram); 
}

#endif