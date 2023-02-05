//
// Created by w10493 on 2023/2/1.
//

#ifndef RISC_V_SIMULATOR_REGISTERS_H
#define RISC_V_SIMULATOR_REGISTERS_H

#include "../Utils/Types.h"
#include "../ClockedChip/ClockedChip.h"

class Registers : ClockedChip {
private:
    u64 registers[32]{
            0, 1, 2, 0,
            0, 0, 0, 0,
            0, 0, 0, 1,
            1, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
    };

public:
    u32 read_register1{}; // 5-bit
    u32 read_register2{}; // 5-bit
    u32 write_register{}; // 5-bit
    u32 reg_write{}; // 1-bit
    u64 write_data{};

    u64 read_data1();

    u64 read_data2();

    void tick() override;

    void debug_print() override;
};


#endif //RISC_V_SIMULATOR_REGISTERS_H
