// #include "UnidadeControle.hpp"
#include "../cpu/UnidadeControle.hpp"

#include <iostream>

void UnidadeControle::executarInstrucao(const DecodedInstruction& decoded, Registers& regs, RAM& ram, int& PC) {
    switch (decoded.opcode) {
        case ADD: {
            int resultado = ula.exec(decoded.value1, decoded.value2, ADD);
            regs.set(decoded.destiny, resultado);
            ram.write(PC / 4, resultado);
            std::cout << "ADD R" << decoded.destiny << " = " << decoded.value1 << " + " << decoded.value2
                      << " -> " << regs.get(decoded.destiny) << std::endl;
            break;
        }
        // Outros casos...
        default:
            std::cerr << "Opcode desconhecido: " << decoded.opcode << std::endl;
    }
}
