#ifndef RAM_HPP
#define RAM_HPP

#include <iostream>
#include <vector>

using namespace std;

class RAM {
private:
    vector<int> memoria;
    int tamanho;

public:
    RAM(int tam) : tamanho(tam), memoria(tam, 0) {}

    void write(int endereco, int valor) {
        if (endereco >= 0 && endereco < tamanho) {
            memoria[endereco] = valor;
        } else {
            cout << "Erro: Endereço fora da memória!" << endl;
        }
    }

    int read(int endereco) {
        if (endereco >= 0 && endereco < tamanho) {
            return memoria[endereco];
        } else {
            cout << "Erro: Endereço fora da memória!" << endl;
            return -1; 
        }
    }

    void display() const {
        for (int i = 0; i < tamanho; i++) {
            cout << "Endereço " << i << " -> " << memoria[i] << endl;
        }
    }
};

#endif
