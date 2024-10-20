#include "../includes/Core.hpp"

Core::Core(RAM& ram) : ram(ram), PC(0) {
    cout << "Core inicializado com RAM\n";
}

void Core::activate() {
    Pipeline(regs, ram, uc, PC);
    cout << "PC: " << PC << endl;
}