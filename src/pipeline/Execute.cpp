#include "../includes/Execute.hpp"

void Execute(const DecodedInstruction& decoded, Registers& regs, RAM& ram, UnidadeControle& uc, int& PC, Disco& disco) {
    uc.executarInstrucao(decoded, regs, ram, PC, disco);
}
