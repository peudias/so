// #include "Registers.hpp"
#include "include/cpu/Registers.hpp"
#include <iostream>

Registers::Registers() : registradores(NUM_REGISTRADORES, 0) {}

int Registers::get(int index) const {
    if (index >= 0 && index < registradores.size()) {
        return registradores[index];
    }
    std::cerr << "Erro: Registrador inválido " << index << std::endl;
    return 0;
}

void Registers::set(int index, int value) {
    if (index >= 0 && index < registradores.size()) {
        registradores[index] = value;
    } else {
        std::cerr << "Erro: Registrador inválido " << index << std::endl;
    }
}

void Registers::display() const {
    std::cout << "\nRegistradores: " << std::endl;
    for (size_t i = 0; i < registradores.size(); ++i) {
        std::cout << "R[" << i << "] = " << registradores[i] << std::endl;
    }
}
