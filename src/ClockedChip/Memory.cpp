//
// Created by w10493 on 2023/2/1.
//

#include <iostream>
#include "Memory.h"

void Memory::tick() {
    // Attention byte order
    if (mem_write) {
        *(u64 *) (memory + address) = write_data;
    }
}

u64 Memory::read_data() {
    if (mem_read) return *(u64 *) (memory + address);
    else return 0;
}

void Memory::debug_print() {
    std::cout << "Memory:\n";
    for (int i = 0; i < 16; i++) {
        std::cout << "\t" << i * 8 << ": " << *(u64 *) (memory + i * 8) << "\t";
        if (i % 4 == 3) std::cout << std::endl;
    }
}
