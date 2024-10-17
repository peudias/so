#ifndef PIPELINE_HPP
#define PIPELINE_HPP

// #include "Registers.hpp"
// #include "RAM.hpp"
// #include "UnidadeControle.hpp"
#include "../cpu/Registers.hpp"
#include "../memory/RAM.hpp"
#include "../cpu/UnidadeControle.hpp"

void Pipeline(Registers& regs, RAM& ram, UnidadeControle& uc, int& PC);

#endif
