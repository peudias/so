#ifndef EXECUTE_HPP
#define EXECUTE_HPP

#include "InstructionDecode.hpp"
#include "UnidadeControle.hpp"
#include "RAM.hpp"

void Execute(const DecodedInstruction& decoded, Registers& regs, RAM& ram, UnidadeControle& uc, int& PC);

#endif
