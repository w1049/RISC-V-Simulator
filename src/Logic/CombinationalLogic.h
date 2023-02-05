//
// Created by w10493 on 2023/2/2.
//

#ifndef RISC_V_SIMULATOR_COMBINATIONALLOGIC_H
#define RISC_V_SIMULATOR_COMBINATIONALLOGIC_H


// should be independent
// don't nest
class CombinationalLogic {
public:
    CombinationalLogic();

    // similar to "assign xx = yy"
    virtual void compute() = 0;
};


#endif //RISC_V_SIMULATOR_COMBINATIONALLOGIC_H
