#include "cpu/Opcode.hpp"
#include "cpu/Instruction.hpp"
#include "cpu/Registers.hpp"
#include "cpu/ULA.hpp"
#include "cpu/UnidadeControle.hpp"
#include "mainMemory/RAM.hpp"
#include "pipeline/InstructionFetch.hpp"
#include "pipeline/InstructionDecode.hpp"
#include "pipeline/Execute.hpp"

#include <vector>
#include <iostream>

using namespace std;

int main() {
    Registers regs;
    UnidadeControle uc;
    RAM ram;
    int PC = 0;

    int resultado = 0;

    regs.set(2, 10); // R2 = 10
    regs.set(3, 5);  // R3 = 5
    regs.set(4, 7);  // R4 = 7

    //escreve as instrucoes na memoria (endereco, intr)
    ram.writeInstruction(0, Instruction(ADD, 1, 2, 3)); 
    ram.writeInstruction(1, Instruction(SUB, 4, 1, 3));
    ram.writeInstruction(2, Instruction(STORE, 3, 2, 0));
    ram.writeInstruction(3, Instruction(LOAD, 0, 2, 0)); 
    
    //esta parte ficaria no execute da pipeline, ele apenas chama o metodo da UC (eu acho)
    //ram.fetchIntruction le a intrucao que ta na memoria
    uc.executarInstrucao(ram.fetchInstruction(0), regs, ram);
    uc.executarInstrucao(ram.fetchInstruction(1), regs, ram);
    uc.executarInstrucao(ram.fetchInstruction(2), regs, ram); 
    uc.executarInstrucao(ram.fetchInstruction(3), regs, ram);  
    
    
    vector<Instruction> memoria = {
        Instruction(ADD, 1, 2, 3),   // R1 -> R2 + R3 = 10 + 5 = 15
        Instruction(SUB, 5, 1, 3),   // R5 -> R1 - R3 = 15 - 5 = 10
        Instruction(AND, 6, 1, 4),   // R6 -> R1 & R4 = 15 & 7 = 1111 & 111 => (0111 === 7)
        Instruction(OR, 7, 2, 4),    // R7 -> R2 | R4 = 10 | 7 = 1010 | 111 => (1111 === 15)
        Instruction(ADD, 1, 2, 3),   // R1 -> R2 + R3
        Instruction(SUB, 4, 1, 3),   // R4 -> R1 - R3
        Instruction(STORE, 3, 2, 0), // R3 -> R2 store R0
        Instruction(LOAD, 0, 2, 0)   // R0 -> R2 load R0
    };

    while (PC < memoria.size() * 4){
        Instruction instr = InstructionFetch(memoria, PC);
        DecodedInstruction decodedInstr = InstructionDecode(instr, regs);

        cout << endl << "[ID]: "
              << "Opcode: " << decodedInstr.opcode
              << ", Destino: R" << decodedInstr.destiny
              << ", Operando 1: " << decodedInstr.value1
              << ", Operando 2: " << decodedInstr.value2 << endl;

        uc.executarInstrucao(instr, regs, ram);

        // Executa estágio EX do pipeline e escreve o resultado no registrador
        Execute(decodedInstr, resultado);
        regs.set(decodedInstr.destiny, resultado);
    }

    regs.display();

    cout << "\nDados RAM\n";
    ram.display();

    cout << "\nEstado atual da RAM:\n";
    ram.displayI();

    cout << "PC: " << PC << endl;

    return 0;
}













