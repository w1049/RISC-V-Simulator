//
// Created by w10493 on 2023/2/2.
//

#include "Instruction.h"

namespace Instruction {
    u32 get(u32 instruction, int l, int r) {
        return (instruction << (31 - l)) >> (31 - l + r);
    }

    u32 opcode(u32 instruction) {
        return get(instruction, 6, 0);
    }

    u32 rs1(u32 instruction) {
        return get(instruction, 19, 15);
    }

    u32 rs2(u32 instruction) {
        return get(instruction, 24, 20);
    }

    u32 rd(u32 instruction) {
        return get(instruction, 11, 7);
    }

    u32 funct3(u32 instruction) {
        return get(instruction, 14, 12);
    }

    u32 sign_extend(u32 imm) {
        u32 x = get(imm, 11, 11);
        if (x) return 0xfffff000 + imm;
        else return imm;
    }

    u32 funct7(u32 instruction) {
        return sign_extend(get(instruction, 31, 25));
    }

    u32 Iimm(u32 instruction) {
        return sign_extend(get(instruction, 31, 20));
    }

    u32 Simm(u32 instruction) {
        return sign_extend((get(instruction, 31, 25) << 5) + get(instruction, 11, 7));
    }

    u32 SBimm(u32 instruction) {
        return sign_extend((get(instruction, 31, 31) << 11) +
                           (get(instruction, 7, 7) << 10) +
                           (get(instruction, 30, 25) << 4) +
                           get(instruction, 11, 8));
    }

}
