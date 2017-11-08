//
// Created by fedie on 23.10.16.
//

#ifndef TURN_BASED_BATTLE_ENEMY_H
#define TURN_BASED_BATTLE_ENEMY_H

#include "Combatant.h"

/**
 *
 */
class Npc_Enemy : public Combatant {
public:
    const int BASE_EXP = 100;

    virtual int getBaseExp() { return Npc_Enemy::BASE_EXP; }

    /**
     *
     * @param name
     * @param health
     * @param mana
     * @param strength
     * @param defense
     * @param dexterity
     * @param speed
     * @param focus
     * @param level
     * @param expBase
     * @return
     */
    Npc_Enemy(std::string name, int health, int mana, int strength, int defense, int dexterity, int speed, int focus,
              int level, int expBase) :
            Combatant(name, health, mana, strength, defense, dexterity, speed, focus, level, expBase) {}

    /**
     * Pure virtual function.  Enemy takes their turn.
     * @param playerTeam
     * @param enemyTeam
     */
    virtual void myTurn(std::vector<Combatant *> playerTeam, std::vector<Combatant *> enemyTeam) = 0;
};


#endif //TURN_BASED_BATTLE_ENEMY_H
