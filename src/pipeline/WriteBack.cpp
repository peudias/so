#include "../includes/WriteBack.hpp"

void WriteBack(const DecodedInstruction& decoded, int resultado, Registers& regs) {
    //if (decoded.opcode == ADD || decoded.opcode == SUB || decoded.opcode == LOAD) {
    regs.set(decoded.destiny, resultado); // Escreve o resultado no registrador de destino
    //}
}
