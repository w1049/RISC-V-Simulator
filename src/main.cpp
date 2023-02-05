#include <iostream>

#include "Utils/ClockManager.h"
#include "ClockedChip/Registers.h"
#include "ClockedChip/Memory.h"
#include "Logic/SeqLogic.h"


int main() {
    SeqLogic logic;
    ClockManager::init();
    for (int i = 0; i < 20; i++) {
        ClockManager::tick();
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
