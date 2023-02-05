//
// Created by w10493 on 2023/2/3.
//

#include "ALU.h"

u64 ALU::out() const {
    switch (op) {
        case 0b0000:
            return in1 & in2;
        case 0b0001:
            return in1 | in2;
        case 0b0010:
            return in1 + in2;
        case 0b0110:
            return in1 - in2;
    }
    return 0;
}

u32 ALU::zero() const {
    return out() == 0;
}
