#ifndef EXECUTE_HPP
#define EXECUTE_HPP

#include "InstructionDecode.hpp"
#include <iostream>

void Execute(const DecodedInstruction& decoded, int& resultado) {
    switch (decoded.opcode) {
        case ADD:
            resultado = decoded.value1 + decoded.value2;
            std::cout << "[EX]: ADD executado! Resultado: " << resultado << std::endl;
            break;
        case SUB:
            resultado = decoded.value1 - decoded.value2;
            std::cout << "[EX]: SUB executado! Resultado: " << resultado << std::endl;
            break;
        case LOAD:
            std::cout << "[EX]: LOAD executado -> Valor lido do endereço " << decoded.value1 << std::endl;
            break;
         case STORE:
            std::cout << "[EX]: STORE executado -> Valor: " << decoded.value2 << " armazenado no endereço " << decoded.value1 << std::endl;
            break;
        case AND:
            resultado = decoded.value1 & decoded.value2;
            std::cout << "[EX]: AND executado! Resultado: " << resultado << std::endl;
            break;
        case OR:
            resultado = decoded.value1 | decoded.value2;
            std::cout << "[EX]: OR executado! Resultado: " << resultado << std::endl;
            break;
        // case MULT:
        //     resultado = decoded.value1 * decoded.value2;
        //     std::cout << "[EX]: MULT executado! Resultado: " << resultado << std::endl;
        //     break;
        // case DIV:
        //     if (decoded.value2 != 0) {
        //         resultado = decoded.value1 / decoded.value2;
        //         std::cout << "[EX]: DIV executado! Resultado: " << resultado << std::endl;
        //     } else {
        //         std::cerr << "[EX]: Erro: Divisão por zero." << std::endl;
        //     }
        //     break;
        default:
            std::cerr << "[EX]: Erro: Opcode desconhecido." << std::endl;
            break;
    }
}

#endif