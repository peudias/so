/*#ifndef INSTRUCTIONFETCH_HPP
#define INSTRUCTIONFETCH_HPP

#include "../cpu/Instruction.hpp"
#include <iostream>


using namespace std;

Instruction InstructionFetch(const vector<Instruction>& memoria, int& PC){
    if(PC < memoria.size() * 4){
        Instruction instr = memoria[PC/4];
        PC += 4;
        return instr;
    } else {
        cerr << "Erro: PC fora dos limites da memória." << endl;
        return Instruction(static_cast<Opcode>(-1), 0, 0, 0);
    }
}

#endif*/