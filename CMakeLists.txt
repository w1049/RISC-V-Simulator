cmake_minimum_required(VERSION 3.24)
project(RISC_V_Simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(RISC_V_Simulator
        src/main.cpp
        src/Utils/ClockManager.cpp
        src/ClockedChip/ClockedChip.cpp
        src/ClockedChip/Registers.cpp
        src/ClockedChip/Memory.cpp
        src/Logic/CombinationalLogic.cpp
        src/ClockedChip/Register.cpp
        src/Utils/ROM.cpp
        src/Logic/SeqLogic.cpp
        src/Utils/Instruction.cpp
        src/Utils/ALU.cpp)