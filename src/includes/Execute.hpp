#ifndef EXECUTE_HPP
#define EXECUTE_HPP

#include "InstructionDecode.hpp"
#include "UnidadeControle.hpp"
#include "RAM.hpp"

int execute(const DecodedInstruction& decoded, Registers& regs, RAM& ram, UnidadeControle& uc, int& PC);

#endif
