//
// Created by w10493 on 2023/2/2.
//

#ifndef RISC_V_SIMULATOR_ROM_H
#define RISC_V_SIMULATOR_ROM_H


#include "Types.h"
#include "../ClockedChip/ClockedChip.h"

class ROM {
private:
    const static u64 MAX_ADDRESS = 1024;
    u8 memory[MAX_ADDRESS]{};

public:
    ROM();

    u64 address{};

    u32 instruction();
};


#endif //RISC_V_SIMULATOR_ROM_H
