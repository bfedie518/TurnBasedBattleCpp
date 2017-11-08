//
// Created by fedie on 16.10.16.
//

#ifndef TURN_BASED_BATTLE_TURNEFFECT_H
#define TURN_BASED_BATTLE_TURNEFFECT_H

#include "Combatant.h"

class TurnEffect {
protected:
    Combatant *owner;
    int duration;

    virtual void affect() = 0;
public:

    const std::string NAME = "Turn Effect";

    virtual std::string getName(){return TurnEffect::NAME;}

    TurnEffect(Combatant *owner, int duration);

    void cycle();

    int getDuration() const;
};


#endif //TURN_BASED_BATTLE_TURNEFFECT_H
