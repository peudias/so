#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <string>
#include "Registers.hpp"
#include "RAM.hpp"

void setRegistersFromFile(Registers& regs, const std::string& regsFilename);

int loadInstructionsFromFile(RAM& ram, const std::string& instrFilename);

#endif
