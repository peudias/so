#include "cpu/Opcode.hpp"
#include "cpu/Instruction.hpp"
#include "cpu/Registers.hpp"
#include "cpu/ULA.hpp"
#include "cpu/UnidadeControle.hpp"
#include "mainMemory/RAM.hpp"

using namespace std;

int main() {
    Registers regs;
    UnidadeControle uc;
    RAM ram;
    int PC = 0;

    regs.set(2, 10);
    regs.set(3, 5);  

    //escreve as instrucoes na memoria (endereco, intr)
    ram.writeInstruction(0, Instruction(ADD, 1, 2, 3)); 
    ram.writeInstruction(1, Instruction(SUB, 4, 1, 3));
    ram.writeInstruction(2, Instruction(STORE, 3, 2, 0));
    ram.writeInstruction(3, Instruction(LOAD, 0, 2, 0)); 
    
    //esta parte ficaria no execute da pipeline, ele apenas chama o metodo da UC (eu acho)
    //ram.fetchIntruction le a intrucao que ta na memoria
    uc.executarInstrucao(ram.fetchInstruction(0), regs, ram, PC);
    uc.executarInstrucao(ram.fetchInstruction(1), regs, ram, PC);
    uc.executarInstrucao(ram.fetchInstruction(2), regs, ram, PC); 
    uc.executarInstrucao(ram.fetchInstruction(3), regs, ram, PC);  

    regs.display();

    cout << "\nDados RAM\n";
    ram.display();

    cout << "\nEstado atual da RAM:\n";
    ram.displayI();

    return 0;
}
