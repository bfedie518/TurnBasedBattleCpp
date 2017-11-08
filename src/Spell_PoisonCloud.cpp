//
// Created by fedie on 16.10.16.
//

#include "Spell_PoisonCloud.h"
#include "TurnEffect_Poison.h"

void Spell_PoisonCloud::cast(Combatant *user, Combatant *target) {
    user->modActMana(-getManaCost());
    if (!target->hasTurnEffect("poison")) {
        target->addTurnEffect(new TurnEffect_Poison(target, DURATION));
        std::cout << target->getName() << " was poisoned\n";
    } else {
        std::cout << target->getName() << " was already poisoned\n";
    }
}
