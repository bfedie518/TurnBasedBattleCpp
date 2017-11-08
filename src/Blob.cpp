//
// Created by fedie on 15.10.16.
//
#include "stdafx.h"
#include "Blob.h"
#include "Battle.h"
#include "TurnEffect_Defend.h"


//Starts by activating each turn effect and checking to see if an effect killed it.
//Randomly chooses whether to attack or defend (70% chance to attack, 30% to defend).
void Blob::myTurn(std::vector<Combatant*> playerTeam, std::vector<Combatant*> enemyTeam){
    activateTurnEffects();
    if (getActHealth() > 0) {
        std::cout << '\n' << getName() << " health: " << getActHealth() << "\n\n";
        int move = rand() % 10;
        if (move < 7) {
            attack(playerTeam);
        } else {
            defend();
        }
    }else{
        std::cout << getName() << " has died!\n";
    }
}

//Randomly chooses target from player's team and attacks
void Blob::attack(std::vector<Combatant*> playerTeam){
    bool isHit;
    Combatant *target;
    do {
        target = playerTeam[(int) (rand() % playerTeam.size())];
    } while (target->getActHealth() <= 0);

    std::cout << getName() << " attacks " << target->getName() << "!\n";
    isHit = Battle::willHit(this, target, 80);
    if (isHit) {
        int damage = Battle::damageCalc(this, target, 15);
        target->modActHealth(-damage);
        std::cout << "HIT!! They did " << damage << " damage.\n";
        std::cout << target->getActHealth() << " health remaining.\n";
    } else {
        std::cout << "They missed.\n";
    }
}

//Boosts own defense and starts effect that will remove boost at the start of the next turn.
void Blob::defend() {
    modActDefense(1.5);
    addTurnEffect(new TurnEffect_Defend(this, 1));
    std::cout << getName() << " is defending.  Defense is temporarily raised.\n";
}
