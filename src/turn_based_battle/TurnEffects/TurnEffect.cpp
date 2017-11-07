//
// Created by fedie on 16.10.16.
//

#include "TurnEffect.h"

TurnEffect::TurnEffect(Combatant *owner, int duration) {
    this->owner = owner;
    this->duration = duration;
}

void TurnEffect::cycle() {
    this->affect();
    duration--;
}

int TurnEffect::getDuration() const{
    return duration;
}