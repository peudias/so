#include "../includes/Core.hpp"

Core::Core(RAM& ram) : ram(ram), PC(0) , disco(disco){
    cout << "Core inicializado com RAM\n";
}

void Core::activate() {
    Pipeline(regs, ram, uc, PC, "data/instructions.txt", "data/setRegisters.txt", disco);
    cout << "PC: " << PC << endl;
}