#include "../includes/Registers.hpp"

Registers::Registers() : registradores(NUM_REGISTRADORES, 0) {}

int Registers::get(int index) const {
    if (index >= 0 && index < registradores.size()) {
        return registradores[index];
    }
    cerr << "Erro: Registrador inválido " << index << endl;
    return 0;
}

void Registers::set(int index, int value) {
    if (index >= 0 && index < registradores.size()) {
        registradores[index] = value;
    } else {
        cerr << "Erro: Registrador inválido " << index << endl;
    }
}

void Registers::display() const {
    cout << endl << "Registradores: " << endl;
    for (size_t i = 0; i < registradores.size(); ++i) {
        cout << "R[" << i << "] = " << registradores[i] << endl;
    }
}
