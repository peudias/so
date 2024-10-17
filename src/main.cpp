#include "include/cpu/Opcode.hpp"
#include "include/cpu/Instruction.hpp"
#include "include/cpu/Registers.hpp"
#include "include/cpu/ULA.hpp"
#include "include/cpu/UnidadeControle.hpp"

#include "include/memory/RAM.hpp"

#include "include/pipeline/InstructionFetch.hpp"
#include "include/pipeline/InstructionDecode.hpp"
#include "include/pipeline/Execute.hpp"
#include "include/pipeline/Pipeline.hpp"

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













