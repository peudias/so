#ifndef REGISTERS_HPP
#define REGISTERS_HPP
#define NUM_REGISTRADORES 32

#include <iostream>
#include <vector>

using namespace std;

class Registers {
private: 
    vector<int> registradores;

public:
    Registers() : registradores(NUM_REGISTRADORES, 0) {} 

    int get(int index) const {
        if (index >= 0 && index < registradores.size()) {
            return registradores[index];
        }
        cerr << "Erro: Registrador inválido " << index << endl;
        return 0;
    }

    void set(int index, int value) {
        if (index >= 0 && index < registradores.size()) {
            registradores[index] = value;
        } else {
            cerr << "Erro: Registrador inválido " << index << endl;
        }
    }

    void display() const {
        for (size_t i = 0; i < registradores.size(); ++i) {
            cout << "R" << i << " = " << registradores[i] << endl;
        } 
    }  
};

#endif
