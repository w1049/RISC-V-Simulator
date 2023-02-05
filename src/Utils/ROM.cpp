//
// Created by w10493 on 2023/2/2.
//

#include "ROM.h"

u32 ROM::instruction() {
    return *(u32 *) (memory + address);
}

ROM::ROM() {
    int n = 5;
    u32 ins[5] = {
            0x00c585b3,
            0x00b6b023,
            0x00c58633,
            0x00c6b423,
            0x0046b703
    };
    for (int i = 0; i < n; i++) {
        *(u32 *) (memory + i * 4) = ins[i];
    }
}
