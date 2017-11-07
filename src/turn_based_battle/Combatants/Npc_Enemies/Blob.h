//
// Created by fedie on 15.10.16.
//

#ifndef TURN_BASED_BATTLE_BLOB_H
#define TURN_BASED_BATTLE_BLOB_H

#include "Npc_Enemy.h"

/**
 * The default sample enemy until more varieties are programmed.
 */
class Blob : public Npc_Enemy {
private:
    /**
    * Base amount of exp given when Blob is defeated.  Overrides constant in NPC_Enemy.
    */
    const int BASE_EXP = 80;
    /**
     * Raises defense by 50% until start of the Blob's next turn
     */
    void defend();

    /**
     * Selects a target from player's team and attacks
     * @param playerTeam The team being attacked
     */
    void attack(std::vector<Combatant *> playerTeam);

public:
    /**
     * Used to get the BASE_EXP of the blob.  Used so constant in NPC_Enemy can be overridden
     * @return
     */
    virtual int getBaseExp() {return Blob::BASE_EXP;}

    /**
     * Constructs an instance of Blob.  Uses base class NPC_Enemy's constructor.
     * @param name Name of the blob
     * @param health starting health
     * @param mana starting mana
     * @param strength starting strength
     * @param defense starting defense
     * @param dexterity starting dexterity
     * @param speed starting speed
     * @param focus starting focus
     * @param level level of the blob
     * @param expBase exp given when blob is defeated
     */
    Blob(std::string name, int health, int mana, int strength, int defense, int dexterity, int speed, int focus,
         int level, int expBase) :
            Npc_Enemy(name, health, mana, strength, defense, dexterity, speed, focus, level, expBase) {}

    /**
     * Blob takes its turn--choosing and executing an action.
     * @param playerTeam
     * @param enemyTeam
     */
    virtual void myTurn(std::vector<Combatant *> playerTeam, std::vector<Combatant *> enemyTeam);
};


#endif //TURN_BASED_BATTLE_BLOB_H
