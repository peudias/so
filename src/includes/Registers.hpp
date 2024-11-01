#ifndef REGISTERS_HPP
#define REGISTERS_HPP
#define NUM_REGISTRADORES 32

#include <iostream>
#include <vector>

using namespace std;

class Registers {
private: 
    vector<int> registradores;

public:
    Registers(); 

    int get(int index) const;
    
    void set(int index, int value);

    void display() const;
};

#endif
