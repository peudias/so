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
    RAM ram(128); // Inicializando a RAM com 128 endereços
    int PC = 0;

    // Setando valores nos registradores
    regs.set(2, 10);  // R2 = 10 (Endereço de RAM)
    regs.set(3, 5);   // R3 = 5  (Valor a ser armazenado)

    Instruction instr1(ADD, 1, 2, 3);
    uc.executarInstrucao(instr1, regs, ram, PC);
    
    Instruction instr2(SUB, 4, 1, 3);
    uc.executarInstrucao(instr2, regs, ram, PC);

    // Instrução STORE para armazenar R3 em RAM[R2] (Endereço 10 da RAM)
    Instruction storeInstr(STORE, 3, 2, 0);  // STORE R3 -> RAM[R2]
    uc.executarInstrucao(storeInstr, regs, ram, PC);

    // Instrução LOAD para carregar RAM[R2] (Endereço 10) para R1
    Instruction loadInstr(LOAD, 0, 2, 0);  // LOAD R1 <- RAM[R2]
    uc.executarInstrucao(loadInstr, regs, ram, PC);

    // Exibindo valores dos registradores
    regs.display();

    // Exibindo o estado da RAM (opcional)
    cout << "\nEstado atual da RAM:\n";
    ram.display();

    return 0;
}
