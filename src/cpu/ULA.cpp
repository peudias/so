#include "../includes/ULA.hpp"

int ULA::exec(int operador_1, int operador_2, Opcode operando) {
    switch (operando) {
        case ADD:
            return operador_1 + operador_2;
        case SUB:
            return operador_1 - operador_2;
        case AND:
            return operador_1 & operador_2;
        case OR:
            return operador_1 | operador_2;
        case MULT:
            return operador_1 * operador_2;
        case DIV:
            return operador_1 / operador_2;
        case IF_igual:
            return (operador_1 == operador_2) ? 1 : 0;
        case IF_maior:
            return (operador_1 > operador_2) ? 1 : 0;
        case ENQ:
            while (operador_1 < operador_2) {
                operador_1 += operador_1;
            }
            return operador_1;
        default:
            cout << "Operacao invalida!" << endl;
            return 0;
    }
}
