#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include "Disco.hpp"
#include "Opcode.hpp"
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ULA.hpp"
#include "RAM.hpp"
#include "InstructionDecode.hpp"
#include <string>

class Pipeline
{
private:
    ULA ula;

public:
    Pipeline();
    void PipelineProcess(Registers& regs, RAM& ram, int& PC, const string& filename, const string& regsFilename, Disco& Disco, int& Clock);
    Instruction InstructionFetch(RAM& ram, int endereco);
    void Wb(const DecodedInstruction& decoded, int& resultado, RAM& ram, Disco& disco, int& Clock);
    void MemoryAccess(const DecodedInstruction& decoded, int resultado, Registers& regs, int& Clock);
    void setRegistersFromFile(Registers& regs, const std::string& regsFilename);
    int loadInstructionsFromFile(RAM& ram, const std::string& instrFilename);
    void Execute(const DecodedInstruction& decoded, Registers& regs, RAM& ram, int& PC, Disco& Disco, int& Clock);
};




#endif
