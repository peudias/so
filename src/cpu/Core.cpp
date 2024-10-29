#include "../includes/Core.hpp"

Core::Core(RAM& ram, Disco& disco) : ram(ram), disco(disco), PC(0) {
    cout << "Core inicializado com RAM\n";
}

void Core::activate() {
    Pipeline(regs, ram, uc, PC, "data/instructions.txt", "data/setRegisters.txt", disco);
    cout << "PC: " << PC << endl;
}