/*
#include "../includes/InstructionFetch.hpp"

Instruction InstructionFetch(const std::vector<Instruction>& memoria, int& PC) {
    if (PC < memoria.size() * 4) {
        Instruction instr = memoria[PC / 4];
        PC += 4;
        return instr;
    } else {
        std::cerr << "Erro: PC fora dos limites da memória." << std::endl;
        return Instruction(static_cast<Opcode>(-1), 0, 0, 0);
    }
}
*/