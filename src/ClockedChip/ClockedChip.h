//
// Created by w10493 on 2023/2/1.
//

#ifndef RISC_V_SIMULATOR_CLOCKEDCHIP_H
#define RISC_V_SIMULATOR_CLOCKEDCHIP_H


// Combinational logic is implemented by C++ statements.
// Structure: using statements to determine the input of many ClockedChip.
class ClockedChip {
public:
    // auto addClocked to manager
    ClockedChip();

    // use inputs to generate outputs
    virtual void tick() = 0;

    virtual void debug_print();

    // dont destruct it
};


#endif //RISC_V_SIMULATOR_CLOCKEDCHIP_H
