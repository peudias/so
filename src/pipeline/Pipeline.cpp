#include "../includes/Pipeline.hpp"
#include "../includes/FileReader.hpp"
#include "../includes/InstructionFetch.hpp"
#include "../includes/MemoryAccess.hpp"
#include "../includes/WriteBack.hpp"
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
        Instruction instr = fetchInstruction(PC/4,ram);
        DecodedInstruction decodedInstr = InstructionDecode(instr, regs);

        cout << endl << "[ID]: "
             << "Opcode: " << decodedInstr.opcode
             << ", Destino: R" << decodedInstr.destiny
             << ", Operando 1: " << decodedInstr.value1
             << ", Operando 2: " << decodedInstr.value2 << endl;

        int resultado = execute(decodedInstr, regs, ram, uc, PC);
        EM(PC/4,resultado,ram);
        WB(decodedInstr,resultado,regs);

        PC += 4;
    }
}
