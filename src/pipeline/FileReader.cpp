#include "../includes/FileReader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void setRegistersFromFile(Registers& regs, const string& regsFilename) {
    ifstream regsFile(regsFilename);
    if (!regsFile.is_open()) {
        cerr << "Erro ao abrir o arquivo de registradores: " << regsFilename << endl;
        return;
    }

    string line;
    while (getline(regsFile, line)) {
        int regNum, regValue;
        char virgula;
        stringstream ss(line);

        ss >> regNum >> virgula >> regValue;
        regs.set(regNum, regValue);
    }
    regsFile.close();
}

int loadInstructionsFromFile(RAM& ram, const string& instrFilename) {
    ifstream file(instrFilename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo de instruções: " << instrFilename << endl;
        return -1;
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

    return instructionAddress;
}
