//
// Created by w10493 on 2023/2/2.
//

#include "Register.h"

Register::Register(u64 initialState) : out(initialState) {}

void Register::tick() {
    out = in;
}
