#include "includes/Opcode.hpp"
#include "includes/Instruction.hpp"
#include "includes/Registers.hpp"
#include "includes/ULA.hpp"
#include "includes/UnidadeControle.hpp"
#include "includes/RAM.hpp"
#include "includes/InstructionFetch.hpp"
#include "includes/InstructionDecode.hpp"
#include "includes/Execute.hpp"
#include "includes/Pipeline.hpp"

#include <vector>
#include <iostream>

using namespace std;

int main() {
    Registers regs;
    UnidadeControle uc;
    RAM ram;
    int PC = 0;

    Pipeline(regs, ram, uc, PC, "data/instructions.txt");

    regs.display();

    cout << "\nDados RAM\n";
    ram.display();

    cout << "\nEstado atual da RAM:\n";
    ram.displayI();

    cout << "PC: " << PC << endl;

    return 0;
}













