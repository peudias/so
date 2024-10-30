#ifndef UNIDADECONTROLE_HPP
#define UNIDADECONTROLE_HPP

#include <iostream>
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ULA.hpp"
#include "RAM.hpp"
#include "InstructionDecode.hpp"
#include "Disco.hpp"

using namespace std;

class UnidadeControle {
private:
    ULA ula;

public:
    void executarInstrucao(const DecodedInstruction& decoded, Registers& regs, RAM& ram, int& PC, Disco& disco);
};

#endif
