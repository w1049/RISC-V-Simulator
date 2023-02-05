//
// Created by w10493 on 2023/2/1.
//

#ifndef RISC_V_SIMULATOR_CLOCKMANAGER_H
#define RISC_V_SIMULATOR_CLOCKMANAGER_H


#include "../ClockedChip/ClockedChip.h"
#include "../Logic/CombinationalLogic.h"

namespace ClockManager {
    void addClocked(ClockedChip *chip);

    void addLogic(CombinationalLogic *logic);

    void init();

    void tick();
}

#endif //RISC_V_SIMULATOR_CLOCKMANAGER_H
