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
            resultado = ula.exec(decoded.value1, decoded.value2, decoded.opcode);
            std::cout << "[EX]: " << "Operação executada -> Resultado: " << resultado << std::endl;
            WriteBack(decoded, resultado, regs);
            break;
        }
        case LOAD:
        case STORE: {
            MemoryAccess(decoded, resultado, ram);
            if (decoded.opcode == LOAD) {
                WriteBack(decoded, resultado, regs);
            }
            break;
        }
        case IF_igual: 
        case IF_maior: 
        case ENQ:
            resultado = ula.exec(decoded.value1, decoded.value2, decoded.opcode);
            std::cout << "[EX]: " << "Operação executada -> Resultado: " << resultado << std::endl;
            WriteBack(decoded, resultado, regs);
            break;
        default:
            cerr << "Opcode desconhecido: " << decoded.opcode << endl;
            return;
    }
}