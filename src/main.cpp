#include "cpu/Opcode.hpp"
#include "cpu/Instruction.hpp"
#include "cpu/Registers.hpp"
#include "cpu/ULA.hpp"
#include "cpu/UnidadeControle.hpp"
#include "mainMemory/RAM.hpp"
#include "pipeline/InstructionFetch.hpp"
#include "pipeline/InstructionDecode.hpp"
#include "pipeline/Execute.hpp"
#include "pipeline/Pipeline.hpp"

#include <vector>
#include <iostream>

using namespace std;

int main() {
    Registers regs;
    UnidadeControle uc;
    RAM ram;
    int PC = 0;

    Pipeline(regs, ram, uc, PC);

    regs.display();

    cout << "\nDados RAM\n";
    ram.display();

    cout << "\nEstado atual da RAM:\n";
    ram.displayI();

    cout << "PC: " << PC << endl;

    return 0;
}













