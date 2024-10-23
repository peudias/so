#include "../includes/Execute.hpp"

int execute(const DecodedInstruction& decoded, Registers& regs, RAM& ram, UnidadeControle& uc, int& PC) {
    return uc.executarInstrucao(decoded, regs, ram, PC);
}
