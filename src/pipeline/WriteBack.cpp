#include "../includes/WriteBack.hpp"

void WB(const DecodedInstruction& decoded, int resultado, Registers& regs) {
    //if (decoded.opcode == STORE) {
        regs.set(decoded.destiny, resultado); // Escreve o resultado no registrador de destino
    //}
}
