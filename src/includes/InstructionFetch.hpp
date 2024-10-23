#ifndef INSTRUCTIONFETCH_HPP
#define INSTRUCTIONFETCH_HPP

#include "Instruction.hpp"
#include "RAM.hpp"
#include <vector>
#include <iostream>
using namespace std;

Instruction fetchInstruction(int endereco, RAM& ram);

#endif
