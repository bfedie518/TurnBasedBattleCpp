//
// Created by fedie on 16.10.16.
//

#ifndef TURN_BASED_BATTLE_SPELL_POISONCLOUD_H
#define TURN_BASED_BATTLE_SPELL_POISONCLOUD_H

#include "Spell.h"

class Spell_PoisonCloud : public Spell{
private:
    const int DURATION = 5;
public:
    const std::string NAME = "Poison Cloud";
    const int MANA_COST = 15;

    virtual std::string getName(){return Spell_PoisonCloud::NAME;}

    virtual int getManaCost() {return Spell_PoisonCloud::MANA_COST;}

    virtual void cast(Combatant* user, Combatant* target);

};


#endif //TURN_BASED_BATTLE_SPELL_POISONCLOUD_H
