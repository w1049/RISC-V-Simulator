//
// Created by w10493 on 2023/2/1.
//

#ifndef RISC_V_SIMULATOR_TYPES_H
#define RISC_V_SIMULATOR_TYPES_H

#include <exception>

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;

class OutOfBound : std::exception {
};

#endif //RISC_V_SIMULATOR_TYPES_H
