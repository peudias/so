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
    // Construtor para inicializar a RAM com o tamanho desejado
    RAM(int tam) : tamanho(tam), memoria(tam, 0) {}

    // Função para escrever na memória
    void write(int endereco, int valor) {
        if (endereco >= 0 && endereco < tamanho) {
            memoria[endereco] = valor;
        } else {
            cout << "Erro: Endereço fora da memória!" << endl;
        }
    }

    // Função para ler da memória
    int read(int endereco) {
        if (endereco >= 0 && endereco < tamanho) {
            return memoria[endereco];
        } else {
            cout << "Erro: Endereço fora da memória!" << endl;
            return -1; // valor de erro
        }
    }

    // Função para exibir o estado da RAM
    void display() const {
        for (int i = 0; i < tamanho; i++) {
            cout << "Endereço " << i << " -> " << memoria[i] << endl;
        }
    }
};

#endif
