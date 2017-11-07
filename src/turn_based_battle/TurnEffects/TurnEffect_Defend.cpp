//
// Created by fedie on 16.10.16.
//

#include "TurnEffect_Defend.h"

void TurnEffect_Defend::affect(){
    owner->modActDefense(1.0/1.5);
    std::cout << owner->getName() << " is no longer defending.\n";
}