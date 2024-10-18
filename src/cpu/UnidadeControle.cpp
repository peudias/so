#include "../includes/UnidadeControle.hpp"

void UnidadeControle::executarInstrucao(const DecodedInstruction& decoded, Registers& regs, RAM& ram, int& PC) {
    switch (decoded.opcode) {
        case ADD: {
            int resultado = ula.exec(decoded.value1, decoded.value2, ADD);
            regs.set(decoded.destiny, resultado);
            ram.write(PC / 4, resultado);
            cout << "ADD R" << decoded.destiny << " = " << decoded.value1 << " + " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case SUB: {
            int resultado = ula.exec(decoded.value1, decoded.value2, SUB);
            regs.set(decoded.destiny, resultado);
            ram.write(PC / 4, resultado);
            cout << "SUB R" << decoded.destiny << " = " << decoded.value1 << " - " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case AND: {
            int resultado = ula.exec(decoded.value1, decoded.value2, AND);
            regs.set(decoded.destiny, resultado);
            ram.write(PC / 4, resultado);
            cout << "AND R" << decoded.destiny << " = " << decoded.value1 << " & " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case OR: {
            int resultado = ula.exec(decoded.value1, decoded.value2, OR);
            regs.set(decoded.destiny, resultado);
            ram.write(PC / 4, resultado);
            cout << "OR R" << decoded.destiny << " = " << decoded.value1 << " | " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case LOAD: {
            int valor = ram.read(decoded.value1);
            regs.set(decoded.destiny, valor);
            cout << "LOAD R" << decoded.destiny << " = RAM[" << decoded.value1 << "] -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case STORE: {
            int valor = regs.get(decoded.destiny);
            ram.write(decoded.value1, valor);
            cout << "STORE RAM[" << decoded.value1 << "] = R" << decoded.destiny << " -> " << valor << endl;
            break;
        }
        case MULT: {
            int resultado = ula.exec(decoded.value1, decoded.value2, MULT);
            regs.set(decoded.destiny, resultado);
            ram.write(PC / 4, resultado);
            cout << "MULT R" << decoded.destiny << " = " << decoded.value1 << " * " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case DIV: {
            if (decoded.value2 != 0) {
                int resultado = ula.exec(decoded.value1, decoded.value2, DIV);
                regs.set(decoded.destiny, resultado);
                ram.write(PC / 4, resultado);
                cout << "DIV R" << decoded.destiny << " = " << decoded.value1 << " / " << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            } else {
                cerr << "Erro: Divisão por zero!" << endl;
            }
            break;
        }
        case IF_igual: {
            int resultado = ula.exec(regs.get(decoded.value1), regs.get(decoded.value2), IF_igual);
            regs.set(decoded.destiny, resultado);
            cout << "IF_igual " << decoded.destiny << " = R" << decoded.value1 << " == R" << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case IF_maior: {
            int resultado = ula.exec(regs.get(decoded.value1), regs.get(decoded.value2), IF_maior);
            regs.set(decoded.destiny, resultado);
            cout << "IF_maior " << decoded.destiny << " = R" << decoded.value1 << " > R" << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        case ENQ: {
            int resultado = ula.exec(regs.get(decoded.value1), regs.get(decoded.value2), ENQ);
            regs.set(decoded.destiny, resultado);
            cout << "IF_maior " << decoded.destiny << " = R" << decoded.value1 << " enquanto R" << decoded.value2 << " -> " << regs.get(decoded.destiny) << endl;
            break;
        }
        default:
            cerr << "Opcode desconhecido: " << decoded.opcode << endl;
    }
}
