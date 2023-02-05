//
// Created by w10493 on 2023/2/1.
//

#include <iostream>
#include "Registers.h"

void Registers::tick() {
    if (read_register1 >= 32) throw OutOfBound();
    if (read_register2 >= 32) throw OutOfBound();
    if (write_register >= 32) throw OutOfBound();

    if (reg_write && write_register) // x0 = 0
        registers[write_register] = write_data;
}

u64 Registers::read_data1() {
    return registers[read_register1];
}

u64 Registers::read_data2() {
    return registers[read_register2];
}

void Registers::debug_print() {
    std::cout << "Registers:\n" << std::dec;
    for (int i = 0; i < 32; i++) {
        std::cout << "\t" << i << ": " << registers[i] << "\t";
        if (i % 4 == 3) std::cout << std::endl;
    }
    std::cout << std::endl;
}
