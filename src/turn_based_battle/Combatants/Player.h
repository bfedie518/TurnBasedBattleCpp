//
// Created by fedie on 15.10.16.
//

#ifndef TURN_BASED_BATTLE_PLAYER_H
#define TURN_BASED_BATTLE_PLAYER_H

#include "Combatant.h"

class Player : public Combatant {
private:
    void attack(Combatant *enemy);

    bool chooseSpell(Combatant *enemy);

    void defend();

    bool attack(std::vector<Combatant *>);

    bool chooseSpell(std::vector<Combatant *>);

public:
    Player(std::string name, int health, int mana, int strength, int defense, int dexterity,
           int speed, int focus, int level = 1, int exp = 1) :
            Combatant(name, health, mana, strength, defense, dexterity, speed, focus, level, exp) {}

    void levelUp();
    virtual void modExp(int);
    void determineLevel();

    virtual void myTurn(Combatant *enemy);

    virtual void myTurn(std::vector<Combatant *> playerTeam, std::vector<Combatant *> enemyTeam);
};


#endif //TURN_BASED_BATTLE_PLAYER_H
