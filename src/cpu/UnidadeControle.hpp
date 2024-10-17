#ifndef UNIDADECONTROLE_HPP
#define UNIDADECONTROLE_HPP

#include <iostream>
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ULA.hpp"
#include "../mainMemory/RAM.hpp"
#include "../pipeline/InstructionDecode.hpp" 

using namespace std;

class UnidadeControle {
private:
    ULA ula;

public:

 // void executarInstrucao(const Instruction& instr, Registers& regs, RAM& ram, int& PC) {
 // void executarInstrucao(const Instruction& instr, Registers& regs, RAM& ram) {
    void executarInstrucao(const DecodedInstruction& decoded, Registers& regs, RAM& ram) {
        switch(decoded.opcode) {
            case ADD: {
                int resultado = ula.exec(decoded.value1, decoded.value2, ADD);
                regs.set(decoded.destiny, resultado);
                cout << "ADD R" << decoded.destiny << " = " << decoded.value1 << " + " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
                break;
            }
            case SUB: {
                int resultado = ula.exec(decoded.value1, decoded.value2, SUB);
                regs.set(decoded.destiny, resultado);
                cout << "SUB R" << decoded.destiny << " = " << decoded.value1 << " - " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
                break;
            }
            case AND: {
                int resultado = ula.exec(decoded.value1, decoded.value2, AND);
                regs.set(decoded.destiny, resultado);
                cout << "AND R" << decoded.destiny << " = " << decoded.value1 << " & " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
                break;
            }
            case OR: {
                int resultado = ula.exec(decoded.value1, decoded.value2, OR);
                regs.set(decoded.destiny, resultado);
                cout << "OR R" << decoded.destiny << " = " << decoded.value1 << " | " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
                break;
            }
            case LOAD: {
                int valor = ram.read(decoded.value1); 
                regs.set(decoded.destiny, valor);
                cout << "LOAD R" << decoded.destiny << " = RAM[" << decoded.value1 << "] -> " << regs.get(decoded.destiny) << endl;
                break;
            }
            case STORE: {
                int valor = regs.get(decoded.destiny);
                ram.write(decoded.value1, valor); 
                cout << "STORE RAM[" << decoded.value1 << "] = R" << decoded.destiny << " -> " << valor << endl;
                break;
            }
            case MULT: {
                int resultado = ula.exec(decoded.value1, decoded.value2, MULT);
                regs.set(decoded.destiny, resultado);
                cout << "MULT R" << decoded.destiny << " = " << decoded.value1 << " * " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
                break;
            }
            case DIV: {
                if (decoded.value2 != 0) {
                    int resultado = ula.exec(decoded.value1, decoded.value2, DIV);
                    regs.set(decoded.destiny, resultado);
                    cout << "DIV R" << decoded.destiny << " = " << decoded.value1 << " / " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
                } else {
                    cerr << "Erro: Divisão por zero!" << endl;
                }
                break;
            }
            default:
                cerr << "Opcode desconhecido: " << decoded.opcode << endl;
        }
    }
};

#endif
