//
// Created by fedie on 01.11.16.
//

#ifndef TURN_BASED_BATTLE_GAME_H
#define TURN_BASED_BATTLE_GAME_H

#include "stdafx.h"
#include "Player.h"
#include "Blob.h"
#include "Battle.h"
#include "Spell_PoisonCloud.h"

class Game{
private:
    Combatant *generateCombatant(std::string, bool);
    std::string teammateName(int i);
    std::string enemyName(int i);
public:
    Game();

};


#endif //TURN_BASED_BATTLE_GAME_H
