//
// Created by w10493 on 2023/2/1.
//

#include "ClockManager.h"

#include <vector>
#include <iostream>

namespace ClockManager {
    namespace {
        std::vector<ClockedChip *> chips;
        std::vector<CombinationalLogic *> logics;
    } // anonymous

    void addClocked(ClockedChip *chip) {
        chips.push_back(chip);
    }

    void addLogic(CombinationalLogic *logic) {
        logics.push_back(logic);
    }

    void init() {
        for (auto logic: logics)
            logic->compute();
        std::cout << "============ Initial ============" << std::endl;
        for (auto chip: chips)
            chip->debug_print();
    }

    // can be parallel
    void tick() {
        std::cout << "============== Tick ==============\n"
                     "command in tick will affect registers and memory in next tick" << std::endl;
        for (auto chip: chips)
            chip->tick();
        for (auto logic: logics)
            logic->compute();

        for (auto chip: chips)
            chip->debug_print();
        std::cout << "============ End Tick ============" << std::endl;
    }
}
