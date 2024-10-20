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
