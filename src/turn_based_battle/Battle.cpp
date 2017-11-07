//
// Created by fedie on 15.10.16.
//

#include "Battle.h"

//Determines order (calls detOrder) then calls battleCycle(), redetermining
// order every round to accomodate speed changing mid-battle.
Battle::Battle(std::vector<Combatant *> playerTeam, std::vector<Combatant *> enemyTeam) {
    std::vector<Combatant *> combatants;
    bool cont;
    do {
        combatants = detOrder(playerTeam, enemyTeam);
        cont = battleCycle(combatants, playerTeam, enemyTeam);
    } while (cont);
}

//Calls every combatant's myTurn() in order, checking to see if either team is entirely dead after each turn
bool Battle::battleCycle(std::vector<Combatant *> combatants, std::vector<Combatant *> playerTeam,
                         std::vector<Combatant *> enemyTeam) {
    for (Combatant *c : combatants) {
        if (c->getActHealth() > 0) {
            c->myTurn(playerTeam, enemyTeam);
            if (!isStillAlive(playerTeam)) {
                endBattle(false, playerTeam, enemyTeam);
                return false;
            }
            if (!isStillAlive(enemyTeam)) {
                endBattle(true, playerTeam, enemyTeam);
                return false;
            }
        }
    }
    return true;

}

//Gets health from each member until an alive one (health > 0) is found.  If none are found, entire team is dead.
bool Battle::isStillAlive(std::vector<Combatant *> team) {
    for (Combatant *c : team) {
        if (c->getActHealth() > 0) {
            return true;
        }
    }
    return false;
}

//Clears effects from battle and awards experience if player won.  Displays win/lose message
void Battle::endBattle(bool playerWon, std::vector<Combatant *> playerTeam, std::vector<Combatant *> enemyTeam) {
    this->playerWon = playerWon;
    if (playerWon) {
        std::cout << "You won!\n";
        for (Combatant *p : playerTeam) {
            p->clearTurnEffects();
            for (Combatant *e : enemyTeam) {
                std::cout << p->getName() << " gained " << e->getExp() << " exp from " << e->getName() << "!\n";
                p->modExp(e->getExp());
            }
        }
    } else {
        std::cout << "You lost!\n";
    }
}

//Uses overloaded '+' operator in Combatant class to sort by Combatant.speed
std::vector<Combatant *> Battle::detOrder(std::vector<Combatant *> combatants) {
    sort(combatants.begin(), combatants.end());
    return combatants;
}

//Combines player and enemy teams into one vector before sorting.
//Uses overloaded '+' operator in Combatant class to sort by Combatant.speed
std::vector<Combatant *> Battle::detOrder(std::vector<Combatant *> playerTeam, std::vector<Combatant *> enemyTeam) {
    std::vector<Combatant *> combatants = playerTeam;

    for (Combatant *c : enemyTeam) { combatants.push_back(c); }

    sort(combatants.begin(), combatants.end());
    return combatants;
}

//I hope this one's obvious
bool Battle::getPlayerWon() const {
    return this->playerWon;
}

//Compares user's and target's dexterity and multiplies by base accuracy of attack to determine chance of hit.
//Generates random number then return whether or not attack will hit
bool Battle::willHit(Combatant *user, Combatant *target, int base) {
    int chance = (int) (((double) user->getActDexterity() / target->getActDexterity()) * base);
    int result = rand() % 100;
    return result <= chance;
}

//Compares user's attack and target's defense in formula (with the base damage of attack) to determine damage dealt.
int Battle::damageCalc(Combatant *user, Combatant *target, int base) {
    return (int) (.4 * ((double) user->getActStrength() / target->getActDefense()) * base);
}
