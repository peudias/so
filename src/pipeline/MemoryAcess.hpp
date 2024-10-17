/*#ifndef MEMORYACCESS_HPP
#define MEMORYACCESS_HPP

#include "InstructionDecode.hpp"
#include "../mainMemory/RAM.hpp"
#include <iostream>

void MemoryAccess(const DecodedInstruction& decoded, int& resultado, RAM& ram) {
    if (decoded.opcode == LOAD) {
        // Lê da RAM no endereço especificado pelo valor1 e coloca no registrador de destino
        resultado = ram.read(decoded.value1); 
        cout << "[MEM]: LOAD da RAM[" << decoded.value1 << "] -> Resultado: " << resultado << endl;
    } else if (decoded.opcode == STORE) {
        // Escreve na RAM no endereço value1 o valor de value2
        ram.write(decoded.value1, decoded.value2); 
        cout << "[MEM]: STORE na RAM[" << decoded.value1 << "] = " << decoded.value2 << endl;
    }
}

#endif*/