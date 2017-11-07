//
// Created by fedie on 15.10.16.
//

#ifndef TURN_BASED_BATTLE_COMBATANT_H
#define TURN_BASED_BATTLE_COMBATANT_H

#include "../stdafx.h"

//Forward declaration
class TurnEffect;
class Spell;

/**
 *
 */
class Combatant {
private:
    /**
     *
     */
    std::set<TurnEffect*> activeTurnEffects;

    /**
     *
     */
    std::string name;

    /**
     *
     */
    int level, exp;
    int baseHealth, baseMana, baseStrength, baseDefense, baseDexterity, baseSpeed, baseFocus;
    int actHealth, actMana, actStrength, actDefense, actDexterity, actSpeed, actFocus;

protected:
    /**
     *
     */
    std::vector<Spell*> spellList;

public:

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
     * @param exp
     * @return
     */
    Combatant(std::string name, int health, int mana, int strength, int defense, int dexterity, int speed,
              int focus, int level = 1, int exp = 1);
    ~Combatant();

    /**
     *
     * @param effect
     */
    void addTurnEffect(TurnEffect* effect);

    /**
     *
     * @param effect
     */
    void removeTurnEffect(TurnEffect* effect);

    /**
     *
     */
    void clearTurnEffects();

    /**
     *
     */
    void activateTurnEffects();

    /**
     *
     * @param name
     * @return
     */
    bool hasTurnEffect(std::string name);

    /**
     *
     * @return
     */
    int displaySpellList();

    /**
     *
     * @param newSpell
     */
    void addSpell(Spell* newSpell);

    /**
     *
     * @param targets
     * @return
     */
    int displayTargets(std::vector<Combatant*> targets);

    /**
     *
     * @param playerTeam
     * @param enemyTeam
     */
    virtual void myTurn(std::vector<Combatant*> playerTeam, std::vector<Combatant*> enemyTeam) = 0;

    /**
     *
     * @return
     */
    std::string getName() const;

    /**
     *
     * @return
     */
    int getLevel() const;

    /**
     *
     * @return
     */
    int getExp() const;

    /**
     *
     * @param mod
     */
    virtual void modExp(int mod);

    /**
     *
     * @param mod
     */
    void modLevel(int mod);

    int getBaseHealth() const;
    int getBaseMana() const;
    int getBaseStrength() const;
    int getBaseDefense() const;
    int getBaseDexterity() const;
    int getBaseSpeed() const;
    int getBaseFocus() const;

    int getActHealth() const;
    int getActMana() const;
    int getActStrength() const;
    int getActDefense() const;
    int getActDexterity() const;
    int getActSpeed() const;
    int getActFocus() const;

    void setName(std::string name);
    void setBaseHealth(int);
    void setBaseMana(int);
    void setBaseStrength(int);
    void setBaseDefense(int);
    void setBaseDexterity(int);
    void setBaseSpeed(int);
    void setBaseFocus(int);

    void setActHealth(int);
    void setActMana(int);
    void setActStrength(int);
    void setActDefense(int);
    void setActDexterity(int);
    void setActSpeed(int);
    void setActFocus(int);

    void modBaseHealth(int);
    void modBaseMana(int);
    void modBaseStrength(int);
    void modBaseDefense(int);
    void modBaseDexterity(int);
    void modBaseSpeed(int);
    void modBaseFocus(int);

    void modActHealth(int);
    void modActMana(int);
    void modActStrength(int);
    void modActDefense(int);
    void modActDexterity(int);
    void modActSpeed(int);
    void modActFocus(int);

    void modActHealth(double);
    void modActMana(double);
    void modActStrength(double);
    void modActDefense(double);
    void modActDexterity(double);
    void modActSpeed(double);
    void modActFocus(double);

};

bool operator<(const Combatant &c1, const Combatant &c2);

#endif //TURN_BASED_BATTLE_COMBATANT_H
