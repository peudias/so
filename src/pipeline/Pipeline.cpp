#include "../includes/Pipeline.hpp"
#include <iostream>

void Pipeline(Registers& regs, RAM& ram, UnidadeControle& uc, int& PC) {
    regs.set(2, 10); // R2 = 10
    regs.set(3, 5);  // R3 = 5
    regs.set(4, 7);  // R4 = 7

    // escreve as instruções na memória (endereço, intr)
    ram.writeInstruction(0, Instruction(ADD, 1, 2, 3)); 
    ram.writeInstruction(1, Instruction(SUB, 4, 1, 3));
    ram.writeInstruction(2, Instruction(STORE, 3, 2, 0));
    ram.writeInstruction(3, Instruction(LOAD, 0, 2, 0)); 
    
    while (PC < 4 * 4) {
        Instruction instr = ram.fetchInstruction(PC / 4);
        DecodedInstruction decodedInstr = InstructionDecode(instr, regs);

        std::cout << std::endl << "[ID]: "
                  << "Opcode: " << decodedInstr.opcode
                  << ", Destino: R" << decodedInstr.destiny
                  << ", Operando 1: " << decodedInstr.value1
                  << ", Operando 2: " << decodedInstr.value2 << std::endl;

        Execute(decodedInstr, regs, ram, uc, PC);   

        PC += 4;
    }
}
