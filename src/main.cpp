#include "cpu/Opcode.hpp"
#include "cpu/Instruction.hpp"
#include "cpu/Registers.hpp"
#include "cpu/ULA.hpp"
#include "cpu/UnidadeControle.hpp"
#include "cpu/RAM.hpp"

using namespace std;

int main() {
    Registers regs;
    UnidadeControle uc;
    RAM ram(128);
    int PC = 0;

    regs.set(2, 10);
    regs.set(3, 5);  

    Instruction instr1(ADD, 1, 2, 3);
    uc.executarInstrucao(instr1, regs, ram, PC);
    
    Instruction instr2(SUB, 4, 1, 3);
    uc.executarInstrucao(instr2, regs, ram, PC);

    Instruction storeInstr(STORE, 3, 2, 0);
    uc.executarInstrucao(storeInstr, regs, ram, PC);

    Instruction loadInstr(LOAD, 0, 2, 0);  
    uc.executarInstrucao(loadInstr, regs, ram, PC);

    regs.display();

    cout << "\nEstado atual da RAM:\n";
    ram.display();

    return 0;
}
