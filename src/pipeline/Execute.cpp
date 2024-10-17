// #include "Execute.hpp"
#include "../include/pipeline/Execute.hpp"

void Execute(const DecodedInstruction& decoded, Registers& regs, RAM& ram, UnidadeControle& uc, int& PC) {
    uc.executarInstrucao(decoded, regs, ram, PC);
}
