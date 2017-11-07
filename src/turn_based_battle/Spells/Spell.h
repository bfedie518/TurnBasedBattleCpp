//
// Created by fedie on 16.10.16.
//

#ifndef TURN_BASED_BATTLE_SPELL_H
#define TURN_BASED_BATTLE_SPELL_H

#include "../stdafx.h"
#include "../Combatants/Combatant.h"

class Spell {
public:
    const std::string NAME = "Spell";
    const int MANA_COST = 10;

    virtual std::string getName(){return Spell::NAME;}

    virtual int getManaCost() {return Spell::MANA_COST;}

    virtual void cast(Combatant* user, Combatant* target) = 0;
};


#endif //TURN_BASED_BATTLE_SPELL_H
