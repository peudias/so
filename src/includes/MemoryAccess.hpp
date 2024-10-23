#ifndef MEMORYACCESS_HPP
#define MEMORYACCESS_HPP

#include "InstructionDecode.hpp"
#include "RAM.hpp"
#include <iostream>

void EM(int endereco, int valor, RAM& ram);

#endif
