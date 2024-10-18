#ifndef WRITEBACK_HPP
#define WRITEBACK_HPP

#include "InstructionDecode.hpp"
#include "Registers.hpp"

void WriteBack(const DecodedInstruction& decoded, int resultado, Registers& regs);

#endif
