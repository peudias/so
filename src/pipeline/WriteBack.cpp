#include "../includes/WriteBack.hpp"

void WriteBack(const DecodedInstruction& decoded, int resultado, Registers& regs) {
    // Escreve o resultado no registrador de destino
    regs.set(decoded.destiny, resultado);
    std::cout << "[WB]: WriteBack -> Registrador R" << decoded.destiny << " = " << resultado << std::endl;
}