#ifndef EXECUTE_HPP
#define EXECUTE_HPP

#include "InstructionDecode.hpp"
#include "UnidadeControle.hpp"
#include "RAM.hpp"
#include "disco.hpp"

void Execute(const DecodedInstruction& decoded, Registers& regs, RAM& ram, UnidadeControle& uc, int& PC, Disco& disco);

#endif
