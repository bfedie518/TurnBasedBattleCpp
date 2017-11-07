//
// Created by fedie on 15.10.16.
//

#ifndef TURN_BASED_BATTLE_BATTLE_H
#define TURN_BASED_BATTLE_BATTLE_H

#include "stdafx.h"
#include "Combatants/Combatant.h"

/**
 * Handles the battle between two teams of combatants.  Create a new instance to start each battle.
 */
class Battle {
private:

    /**
     * Tells whether the player won the battle.
     */
    bool playerWon;

    /**
    * Runs each combatant's turn in order, checking to see if either team is entirely dead before continuing
    * @param combatants all combatants in battle
    * @param playerTeam just the player's team
    * @param enemyTeam just the enemy team
    * @return whether or not the battle continues
    */
    bool battleCycle(std::vector<Combatant *> combatants, std::vector<Combatant *> playerTeam,
                     std::vector<Combatant *> enemyTeam);

    /**
    * Checks whether any member of a team is still living
    * @param team The team to be checked
    * @return whether or not a member of the team is still alive
    */
    bool isStillAlive(std::vector<Combatant *> team);

    /**
    * Clears effects from battle and awards experience if player won.  Displays win/lose message
    * @param playerWon whether or not the player team won
    * @param playerTeam the Combatants on player's team
    * @param enemyTeam the Combatants on enemy team
    */
    void endBattle(bool playerWon, std::vector<Combatant *> playerTeam, std::vector<Combatant *> enemyTeam);

    /**
    * Sorts combatants by speed when given one vector with pointers
    * @param combatants Vector of pointers to all Combatants
    * @return A vector of combatants sorted by speed
    */
    std::vector<Combatant *> detOrder(std::vector<Combatant *> combatants);

    /**
    * Combines playerTeam and enemyTeam vectors and sorts by speed.
    * @param playerTeam Vector of pointers to combatants in player's team
    * @param enemyTeam Vector of pointers to combatants in enemy team
    * @return A vector of combatants sorted by speed
    */
    std::vector<Combatant *> detOrder(std::vector<Combatant *> playerTeam, std::vector<Combatant *> enemyTeam);

public:

    /**
    * Returns whether or not the player won the battle
    * @return the value of playerWon
    */
    bool getPlayerWon() const;

    /**
    * Constructs battle instance.
    * @param playerTeam NPC and player-controlled combatants in party.
    * @param enemyTeam Opposing team to player.
    */
    Battle(std::vector<Combatant *> playerTeam, std::vector<Combatant *> enemyTeam);

    ~Battle() {};

    /**
    * Static function that determines whether or not an attack hits the opponent
    * @param user The combatant attacking
    * @param target The combatant being attacked
    * @param base The base accuracy of the attack
    * @return whether or not the attack hits
    */
    static bool willHit(Combatant *user, Combatant *target, int base);

    /**
    * Calculates the damage dealt by an attack
    * @param The combatant attacking
    * @param target The combatant being attacked
    * @param base The base powerof the attack
    * @return The damage dealt
    */
    static int damageCalc(Combatant *user, Combatant *target, int base);

};

#endif //TURN_BASED_BATTLE_BATTLE_H
