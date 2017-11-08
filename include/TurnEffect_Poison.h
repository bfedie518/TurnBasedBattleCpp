//
// Created by fedie on 16.10.16.
//

#ifndef TURN_BASED_BATTLE_TURNEFFECT_POISON_H
#define TURN_BASED_BATTLE_TURNEFFECT_POISON_H

#include "TurnEffect.h"

class TurnEffect_Poison : public TurnEffect {
private:
    virtual void affect();

public:
    const std::string NAME = "poison";

    virtual std::string getName(){return TurnEffect_Poison::NAME;}

    TurnEffect_Poison(Combatant *owner, int duration) : TurnEffect(owner, duration) {};
};


#endif //TURN_BASED_BATTLE_TURNEFFECT_POISON_H
