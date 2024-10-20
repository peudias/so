#include "Opcode.hpp"
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ULA.hpp"
#include "UnidadeControle.hpp"
#include "RAM.hpp"
#include "InstructionFetch.hpp"
#include "InstructionDecode.hpp"
#include "Execute.hpp"
#include "Pipeline.hpp"

class Core {
public:
    Registers regs;
    UnidadeControle uc;
    int PC;
    RAM& ram;

    Core(RAM& ram);
    void activate();
};