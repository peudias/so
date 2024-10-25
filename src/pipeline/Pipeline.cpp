#include "../includes/Pipeline.hpp"
#include "../includes/FileReader.hpp"

#include <iostream>

using namespace std;

void Pipeline(Registers& regs, RAM& ram, UnidadeControle& uc, int& PC, const string& instrFilename, const string& regsFilename) {
    setRegistersFromFile(regs, regsFilename);

    int instructionAddress = loadInstructionsFromFile(ram, instrFilename);
    if (instructionAddress == -1) {
        cerr << "Erro ao carregar as instruções." << endl;
        return;
    }

    while (PC < instructionAddress * 4) {
        Instruction instr = ram.fetchInstruction(PC / 4);
        DecodedInstruction decodedInstr = InstructionDecode(instr, regs);

        cout << endl << "[ID]: "
             << "Opcode: " << decodedInstr.opcode
             << ", Destino: R" << decodedInstr.destiny
             << ", Operando 1: " << decodedInstr.value1
             << ", Operando 2: " << decodedInstr.value2 << endl;

        Execute(decodedInstr, regs, ram, uc, PC);

        PC += 4;
    }
}

Instruction InstructionFetch(const std::vector<Instruction>& memoria, int& PC) {
    if (PC < memoria.size() * 4) {
        Instruction instr = memoria[PC / 4];
        PC += 4;
        return instr;
    } else {
        std::cerr << "Erro: PC fora dos limites da memória." << std::endl;
        return Instruction(static_cast<Opcode>(-1), 0, 0, 0);
    }
}

void MemoryAccess(const DecodedInstruction& decoded, int& resultado, RAM& ram) {
    if (decoded.opcode == LOAD) {
        // Lê da RAM no endereço especificado pelo valor1 e coloca no registrador de destino
        resultado = ram.read(decoded.value1); 
        std::cout << "[MEM]: LOAD da RAM[" << decoded.value1 << "] -> Resultado: " << resultado << std::endl;
    } else if (decoded.opcode == STORE) {
        // Escreve na RAM no endereço value1 o valor de value2
        ram.write(decoded.value1, decoded.value2); 
        std::cout << "[MEM]: STORE na RAM[" << decoded.value1 << "] = " << decoded.value2 << std::endl;
    }
}

void WriteBack(const DecodedInstruction& decoded, int resultado, Registers& regs) {
    //if (decoded.opcode == ADD || decoded.opcode == SUB || decoded.opcode == LOAD) {
    regs.set(decoded.destiny, resultado); // Escreve o resultado no registrador de destino
    //}
}
