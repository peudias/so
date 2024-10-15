#ifndef UNIDADECONTROLE_HPP
#define UNIDADECONTROLE_HPP

#include <iostream>
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ULA.hpp"
#include "RAM.hpp"

using namespace std;

class UnidadeControle {
private:
    ULA ula;

public:

    void executarInstrucao(const Instruction& instr, Registers& regs, RAM& ram, int& PC) {
        switch(instr.op) {
            case ADD: {
                int resultado = ula.exec(regs.get(instr.Register_1), regs.get(instr.Register_2), ADD);
                regs.set(instr.Destiny_Register, resultado);
                cout << "ADD R" << instr.Destiny_Register << " = R" << instr.Register_1 << " + R" << instr.Register_2 << " -> " << regs.get(instr.Destiny_Register) << endl;
                break;
            }
            case SUB: {
                int resultado = ula.exec(regs.get(instr.Register_1), regs.get(instr.Register_2), SUB);
                regs.set(instr.Destiny_Register, resultado);
                cout << "SUB R" << instr.Destiny_Register << " = R" << instr.Register_1 << " - R" << instr.Register_2 << " -> " << regs.get(instr.Destiny_Register) << endl;
                break;
            }
            case AND: {
                int resultado = ula.exec(regs.get(instr.Register_1), regs.get(instr.Register_2), AND);
                regs.set(instr.Destiny_Register, resultado);
                cout << "AND R" << instr.Destiny_Register << " = R" << instr.Register_1 << " & R" << instr.Register_2 << " -> " << regs.get(instr.Destiny_Register) << endl;
                break;
            }
            case OR: {
                int resultado = ula.exec(regs.get(instr.Register_1), regs.get(instr.Register_2), OR);
                regs.set(instr.Destiny_Register, resultado);
                cout << "OR R" << instr.Destiny_Register << " = R" << instr.Register_1 << " | R" << instr.Register_2 << " -> " << regs.get(instr.Destiny_Register) << endl;
                break;
            }
            case LOAD: {
                int valor = ram.read(regs.get(instr.Register_1)); 
                regs.set(instr.Destiny_Register, valor);
                cout << "LOAD R" << instr.Destiny_Register << " = RAM[" << regs.get(instr.Register_1) << "] -> " << regs.get(instr.Destiny_Register) << endl;
                break;
            }
            case STORE: {
                int valor = regs.get(instr.Destiny_Register);
                ram.write(regs.get(instr.Register_1), valor); 
                cout << "STORE RAM[" << regs.get(instr.Register_1) << "] = R" << instr.Destiny_Register << " -> " << valor << endl;
                break;
            }
            case MULT: {
                int resultado = ula.exec(regs.get(instr.Register_1), regs.get(instr.Register_2), MULT);
                regs.set(instr.Destiny_Register, resultado);
                cout << "MULT R" << instr.Destiny_Register << " = R" << instr.Register_1 << " * R" << instr.Register_2 << " -> " << regs.get(instr.Destiny_Register) << endl;
                break;
            }
            case DIV: {
                int resultado = ula.exec(regs.get(instr.Register_1), regs.get(instr.Register_2), MULT);
                regs.set(instr.Destiny_Register, resultado);
                cout << "DIV R" << instr.Destiny_Register << " = R" << instr.Register_1 << " / R" << instr.Register_2 << " -> " << regs.get(instr.Destiny_Register) << endl;
                break;
            }
            default:
                cerr << "Opcode desconhecido: " << instr.op << endl;
        }
        // PC += 4;
    }
};

#endif
