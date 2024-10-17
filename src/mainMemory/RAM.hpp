#ifndef RAM_HPP
#define RAM_HPP

#include <iostream>
#include <vector>
#include "../cpu/Instruction.hpp"
#include "../pipeline/InstructionDecode.hpp"

using namespace std;

class RAM {
private:
    vector<int> memoria;
    vector<Instruction> instruction_memory;
    static const int tamanho = 32;

public:
    RAM() : memoria(tamanho, 0), instruction_memory(tamanho) {}

    void write(int endereco, int valor) {
        if (endereco >= 0 && endereco < tamanho) {
            memoria[endereco] = valor;
        } else {
            cout << "Erro: Endereço fora da memória!" << endl;
        }
    }

    int read(int endereco) {
        if (endereco >= 0 && endereco < tamanho) {
            return memoria[endereco];
        } else {
            cout << "Erro: Endereço fora da memória!" << endl;
            return -1; 
        }
    }
    
    void writeInstruction(int endereco, const Instruction& instr) {
        if (endereco >= 0 && endereco < tamanho) {
            instruction_memory[endereco] = instr;
        } else {
            cout << "Erro: Endereço inválido para instrução na RAM " << endereco << endl;
        }
    }

    Instruction fetchInstruction(int endereco) const {
        if (endereco >= 0 && endereco < tamanho) {
            return instruction_memory[endereco];
        }
        cout << "Erro: Endereço inválido para instrução na RAM " << endereco << endl;
        return Instruction(ADD, 0, 0, 0); 
    }

    void display() const {
        for (int i = 0; i < tamanho; i++) {
            cout << "Endereço " << i << " -> " << memoria[i] << endl;
        }
    }

    void displayI() const {
        for (int i = 0; i < tamanho; i++) {
            cout << "Endereço " << i << " -> " << instruction_memory[i] << endl;
        }
    }
};

#endif