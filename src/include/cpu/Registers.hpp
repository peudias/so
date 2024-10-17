#ifndef REGISTERS_HPP
#define REGISTERS_HPP
#define NUM_REGISTRADORES 8

#include <iostream>
#include <vector>

class Registers {
private: 
    std::vector<int> registradores;

public:
    Registers();
    int get(int index) const;
    void set(int index, int value);
    void display() const;
};

#endif
