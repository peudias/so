#ifndef UNIDADECONTROLE_HPP
#define UNIDADECONTROLE_HPP

#include <iostream>
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ULA.hpp"

using namespace std;

class UnidadeControle {
private:
    ULA ula;

public:
    void executarInstrucao(const Instruction& instr, Registers& regs, int& PC) {
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
            default:
                cerr << "Opcode desconhecido: " << instr.op << endl;
        }
        PC += 4;
    }
};

#endif
