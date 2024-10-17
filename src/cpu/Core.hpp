#include "Opcode.hpp"
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ULA.hpp"
#include "UnidadeControle.hpp"

class Core
{
    private:
        Registers regs;
        UnidadeControle uc;
        
    public:
        Core();
        ~Core();
};

Core::Core()
{
    Instruction instr;

}

Core::~Core()
{}
