//
// Created by fedie on 16.10.16.
//

#ifndef TURN_BASED_BATTLE_TURNEFFECT_DEFEND_H
#define TURN_BASED_BATTLE_TURNEFFECT_DEFEND_H

#include "TurnEffect.h"

class TurnEffect_Defend : public TurnEffect {
private:
    virtual void affect();

public:
    const std::string NAME = "defend";

    virtual std::string getName(){return TurnEffect_Defend::NAME;}

    TurnEffect_Defend(Combatant *owner, int duration) : TurnEffect(owner, duration) {};
};


#endif //TURN_BASED_BATTLE_TURNEFFECT_DEFEND_H
