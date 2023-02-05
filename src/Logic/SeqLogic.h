//
// Created by w10493 on 2023/2/2.
//

#ifndef RISC_V_SIMULATOR_SEQLOGIC_H
#define RISC_V_SIMULATOR_SEQLOGIC_H


#include "CombinationalLogic.h"
#include "../ClockedChip/Register.h"
#include "../Utils/ROM.h"
#include "../ClockedChip/Registers.h"
#include "../ClockedChip/Memory.h"
#include "../Utils/ALU.h"

class SeqLogic : CombinationalLogic {
private:
    ROM rom;
    Registers reg;
    Memory memory;
    ALU alu;
public:
    Register pc;

    SeqLogic();

    void compute() override;
};


#endif //RISC_V_SIMULATOR_SEQLOGIC_H
