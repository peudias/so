#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include "Opcode.hpp"
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ULA.hpp"
#include "UnidadeControle.hpp"
#include "RAM.hpp"
// #include "InstructionFetch.hpp"
#include "InstructionDecode.hpp"
#include "Execute.hpp"

void Pipeline(Registers& regs, RAM& ram, UnidadeControle& uc, int& PC, const string& filename, const string& regsFilename);
Instruction InstructionFetch(const std::vector<Instruction>& memoria, int& PC);
void MemoryAccess(const DecodedInstruction& decoded, int& resultado, RAM& ram);
void WriteBack(const DecodedInstruction& decoded, int resultado, Registers& regs);

#endif