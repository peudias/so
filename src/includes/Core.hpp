#include "Opcode.hpp"
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ULA.hpp"
#include "UnidadeControle.hpp"
#include "RAM.hpp"
#include "InstructionDecode.hpp"
#include "Pipeline.hpp"
#include "disco.hpp"

class Core {
public:
    Registers regs;
    UnidadeControle uc;
    int PC;
    RAM& ram;
    Disco& disco;

    Core(RAM& ram, Disco& disco);
    void activate();
};