#include "../includes/MemoryAccess.hpp"
#include "../includes/RAM.hpp"

void EM(int endereco, int valor, RAM& ram) {
    if (endereco >= 0 && endereco < ram.tamanho) {
        ram.memoria[endereco] = valor;
    } else {
        std::cout << "Erro: Endereço fora da memória!" << std::endl;
    }
}