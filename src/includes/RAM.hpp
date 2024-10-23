#ifndef RAM_HPP
#define RAM_HPP

#include <iostream>
#include <vector>
#include "../includes/Instruction.hpp"
#include "../includes/InstructionDecode.hpp"

class RAM {

public:
    RAM();

    std::vector<int> memoria;
    std::vector<Instruction> instruction_memory;
    static const int tamanho = 32;

    void write(int endereco, int valor);

    int read(int endereco);

    void writeInstruction(int endereco, const Instruction& instr);

    void display() const;

    void displayI() const;
};

#endif
