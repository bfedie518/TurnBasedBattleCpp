//
// Created by fedie on 16.10.16.
//

#include "TurnEffect_Poison.h"
void TurnEffect_Poison::affect(){
    int damage = (int) (owner->getBaseHealth() * .125);
    owner->modActHealth(-damage);
    std::cout << owner->getName() << " took " << damage << " damage from poison.\n";
}
