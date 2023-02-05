//
// Created by w10493 on 2023/2/3.
//

#ifndef RISC_V_SIMULATOR_ALU_H
#define RISC_V_SIMULATOR_ALU_H


#include "Types.h"

class ALU {
public:
    u64 in1{}, in2{};
    u32 op{};

    u32 zero() const;

    u64 out() const;
};


#endif //RISC_V_SIMULATOR_ALU_H
