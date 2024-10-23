#include "../includes/InstructionFetch.hpp"
#include "../includes/RAM.hpp"

Instruction fetchInstruction(int endereco, RAM& ram){
    if (endereco >= 0 && endereco < ram.tamanho) {
        return ram.instruction_memory[endereco];
    }
    std::cout << "Erro: Endereço inválido para instrução na RAM " << endereco << std::endl;
    return Instruction(ADD, 0, 0, 0);
}
