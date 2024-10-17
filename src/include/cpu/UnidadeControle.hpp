#ifndef UNIDADECONTROLE_HPP
#define UNIDADECONTROLE_HPP

#include "Instruction.hpp"
#include "Registers.hpp"
#include "ULA.hpp"
// #include "../mainMemory/RAM.hpp"
// #include "../pipeline/InstructionDecode.hpp"
#include "../memory/RAM.hpp"
#include "../pipeline/InstructionDecode.hpp"

class UnidadeControle {
private:
    ULA ula;

public:
    void executarInstrucao(const DecodedInstruction& decoded, Registers& regs, RAM& ram, int& PC);
};

#endif
