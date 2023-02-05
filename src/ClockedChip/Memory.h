//
// Created by w10493 on 2023/2/1.
//

#ifndef RISC_V_SIMULATOR_MEMORY_H
#define RISC_V_SIMULATOR_MEMORY_H

#include "../Utils/Types.h"
#include "ClockedChip.h"

class Memory : ClockedChip {
private:
    const static u64 MAX_ADDRESS = 1024;
    u8 memory[MAX_ADDRESS]{};

public:
    u64 address{};
    u64 write_data{};
    u32 mem_read{};
    u32 mem_write{};

    u64 read_data();

    void debug_print() override;

    void tick() override;
};


#endif //RISC_V_SIMULATOR_MEMORY_H
