#include "cpu/Opcode.hpp"
#include "cpu/Instruction.hpp"
#include "cpu/Registers.hpp"
#include "cpu/ULA.hpp"
#include "cpu/UnidadeControle.hpp"

int main() {
    Registers regs;
    UnidadeControle uc;
    int PC = 0;

    Instruction instr1(ADD, 1, 2, 3);
    Instruction instr2(SUB, 4, 1, 3);
    
    regs.set(2, 10);
    regs.set(3, 5);

    uc.executarInstrucao(instr1, regs, PC);
    uc.executarInstrucao(instr2, regs, PC);

    regs.display();

    return 0;
}













