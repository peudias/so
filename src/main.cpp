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
#include "includes/Core.hpp"

#include <vector>
#include <iostream>

using namespace std;

int main() {

    RAM ram;

    vector<Core> cores;

    for (int i = 0; i < 2; i++)
    {   cout << "CORE " << i << ": " << endl;
        cores.emplace_back(ram);
        cout << endl << endl << endl;
    }

    cout << "Utilizando o Core 0:" << endl;
    cores[0].activate();

    cout << "\nDados RAM\n";
    ram.display();

    cout << "\nEstado atual da RAM:\n";
    ram.displayI();

    return 0;
}













