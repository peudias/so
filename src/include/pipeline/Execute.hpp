#ifndef EXECUTE_HPP
#define EXECUTE_HPP

// #include "InstructionDecode.hpp"
// #include "Registers.hpp"
// #include "UnidadeControle.hpp"
// #include "RAM.hpp"
#include "InstructionDecode.hpp"
#include "../cpu/Registers.hpp"
#include "../cpu/UnidadeControle.hpp"
#include "../memory/RAM.hpp"

void Execute(const DecodedInstruction& decoded, Registers& regs, RAM& ram, UnidadeControle& uc, int& PC);

#endif