//
// Created by w10493 on 2023/2/2.
//

#ifndef RISC_V_SIMULATOR_REGISTER_H
#define RISC_V_SIMULATOR_REGISTER_H


#include "../ClockedChip/ClockedChip.h"
#include "../Utils/Types.h"

// D Flip-Flop
class Register : ClockedChip {
public:
    u64 in{};
    u64 out;

    explicit Register(u64 initialState = 0);

    void tick() override;

};


#endif //RISC_V_SIMULATOR_REGISTER_H
