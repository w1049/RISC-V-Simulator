//
// Created by w10493 on 2023/2/2.
//

#ifndef RISC_V_SIMULATOR_INSTRUCTION_H
#define RISC_V_SIMULATOR_INSTRUCTION_H


#include "Types.h"

namespace Instruction {
    u32 get(u32 instruction, int l, int r);

    u32 opcode(u32 instruction);

    u32 rs1(u32 instruction);

    u32 rs2(u32 instruction);

    u32 rd(u32 instruction);

    u32 funct3(u32 instruction);

    u32 funct7(u32 instruction);

    u32 Iimm(u32 instruction);

    u32 Simm(u32 instruction);

    u32 SBimm(u32 instruction);
}


#endif //RISC_V_SIMULATOR_INSTRUCTION_H
