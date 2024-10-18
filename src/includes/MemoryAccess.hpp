#ifndef MEMORYACCESS_HPP
#define MEMORYACCESS_HPP

#include "InstructionDecode.hpp"
#include "RAM.hpp"
#include <iostream>

void MemoryAccess(const DecodedInstruction& decoded, int& resultado, RAM& ram);

#endif
