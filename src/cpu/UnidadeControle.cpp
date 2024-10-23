#include "../includes/UnidadeControle.hpp"

void UnidadeControle::executarInstrucao(const DecodedInstruction& decoded, Registers& regs, RAM& ram, int& PC) {
    int resultado = 0;

    switch (decoded.opcode) {
        case ADD:
        case SUB:
        case AND:
        case OR:
        case MULT:
        case DIV: {
            // Operações que escrevem de volta no registrador
            resultado = ula.exec(decoded.value1, decoded.value2, decoded.opcode);
            std::cout << "[EX]: " << "Operação executada -> Resultado: " << resultado << std::endl;
            WriteBack(decoded, resultado, regs);  // Chama WriteBack para registrar o resultado
            break;
        }
        case LOAD:
        case STORE:
            // Operações de memória (Memory Access)
            MemoryAccess(decoded, resultado, ram);
            if (decoded.opcode == LOAD) {
                WriteBack(decoded, resultado, regs);  // WB é necessário para LOAD
            }
            break;
        default:
            cerr << "Opcode desconhecido: " << decoded.opcode << endl;
            return;
    }
}