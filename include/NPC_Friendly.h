//
// Created by fedie on 25.10.16.
//

#ifndef TURN_BASED_BATTLE_NPC_FRIENDLY_H
#define TURN_BASED_BATTLE_NPC_FRIENDLY_H

#include "Combatant.h"

class NPC_Friendly : public Combatant {
    NPC_Friendly(std::string name, int health, int mana, int strength, int defense, int dexterity,
                 int speed, int focus, int level, int exp) :
            Combatant(name, health, mana, strength, defense, dexterity, speed, focus, level, exp) {}
};


#endif //TURN_BASED_BATTLE_NPC_FRIENDLY_H
