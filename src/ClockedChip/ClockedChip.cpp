//
// Created by w10493 on 2023/2/1.
//

#include <iostream>
#include "ClockedChip.h"
#include "../Utils/ClockManager.h"

ClockedChip::ClockedChip() {
    ClockManager::addClocked(this);
}

void ClockedChip::debug_print() {
    std::cout << "Nothing printed." << std::endl;
}
