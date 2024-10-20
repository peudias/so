#include "../includes/Pipeline.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void setRegistersFromFile(Registers& regs, const string& regsFilename){
    ifstream regsFile(regsFilename);
    if(!regsFile.is_open()){
        cerr << "Erro ao abrir o arquivo de registradores: " << regsFilename << endl;
        return;
    }

    string line;
    while(getline(regsFile, line)){
        int regNum, regValue;
        char virgula;
        stringstream ss(line);
        ss >> regNum >> virgula >> regValue;
        regs.set(regNum, regValue);
    }
    regsFile.close();
}

void Pipeline(Registers& regs, RAM& ram, UnidadeControle& uc, int& PC, const string& filename, const string& regsFilename) {
    setRegistersFromFile(regs, regsFilename);

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }

    string line;
    int instructionAddress = 0;

    while (getline(file, line)) {
        string opcodeStr;
        int reg1, reg2, reg3;
        char virgula;

        stringstream ss(line);

        getline(ss, opcodeStr, ',');

        opcodeStr.erase(remove_if(opcodeStr.begin(), opcodeStr.end(), ::isspace), opcodeStr.end());

        ss >> reg1 >> virgula >> reg2 >> virgula >> reg3;

        Opcode opcode;
        if (opcodeStr == "ADD") opcode = ADD;
        else if (opcodeStr == "SUB") opcode = SUB;
        else if (opcodeStr == "STORE") opcode = STORE;
        else if (opcodeStr == "LOAD") opcode = LOAD;
        else {
            cerr << "Instrução inválida no arquivo: " << opcodeStr << endl;
            continue;
        }

        ram.writeInstruction(instructionAddress++, Instruction(opcode, reg1, reg2, reg3));
    }

    file.close();
    
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
