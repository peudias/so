#include "../includes/UnidadeControle.hpp"

int UnidadeControle::executarInstrucao(const DecodedInstruction& decoded, Registers& regs, RAM& ram, int& PC) {
    int resultado;
    switch (decoded.opcode) {
        case ADD: {
            resultado = ula.exec(decoded.value1, decoded.value2, ADD);
            //cout << "ADD R" << decoded.destiny << " = " << decoded.value1 << " + " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case SUB: {
            resultado = ula.exec(decoded.value1, decoded.value2, SUB);
        
            //cout << "SUB R" << decoded.destiny << " = " << decoded.value1 << " - " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case AND: {
            resultado = ula.exec(decoded.value1, decoded.value2, AND);
        
            //cout << "AND R" << decoded.destiny << " = " << decoded.value1 << " & " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case OR: {
            resultado = ula.exec(decoded.value1, decoded.value2, OR);
        
            //cout << "OR R" << decoded.destiny << " = " << decoded.value1 << " | " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case LOAD: {
            resultado = ram.read(decoded.value1);
            //cout << "LOAD R" << decoded.destiny << " = RAM[" << decoded.value1 << "] -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case STORE: {
            resultado = regs.get(decoded.destiny);
            ram.write(decoded.value1, resultado);
            //cout << "STORE RAM[" << decoded.value1 << "] = R" << decoded.destiny << " -> " << resultado << endl;
            break;
        }
        case MULT: {
            resultado = ula.exec(decoded.value1, decoded.value2, MULT);
        
            //cout << "MULT R" << decoded.destiny << " = " << decoded.value1 << " * " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case DIV: {
            if (decoded.value2 != 0) {
                resultado = ula.exec(decoded.value1, decoded.value2, DIV);
                
                //cout << "DIV R" << decoded.destiny << " = " << decoded.value1 << " / " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            } else {
                cerr << "Erro: Divisão por zero!" << endl;
            }
            break;
        }
        case IF_igual: {
            resultado = ula.exec(regs.get(decoded.value1), regs.get(decoded.value2), IF_igual);
            
            //cout << "IF_igual " << decoded.destiny << " = R" << decoded.value1 << " == R" << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case IF_maior: {
            resultado = ula.exec(regs.get(decoded.value1), regs.get(decoded.value2), IF_maior);
            
            //cout << "IF_maior " << decoded.destiny << " = R" << decoded.value1 << " > R" << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case ENQ: {
            resultado = ula.exec(regs.get(decoded.value1), regs.get(decoded.value2), ENQ);
            
            //cout << "IF_maior " << decoded.destiny << " = R" << decoded.value1 << " enquanto R" << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        default:
            cerr << "Opcode desconhecido: " << decoded.opcode << endl;
    }

    return resultado;
}
