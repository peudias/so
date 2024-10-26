#include "../includes/Pipeline.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
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

void Execute(const DecodedInstruction& decoded, Registers& regs, RAM& ram, UnidadeControle& uc, int& PC) {
    uc.executarInstrucao(decoded, regs, ram, PC);
}

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
