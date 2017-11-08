//
// Created by fedie on 15.10.16.
//

#include "stdafx.h"
#include "Combatant.h"
#include "TurnEffect.h"
#include "Spell.h"

Combatant::Combatant(std::string name, int health, int mana, int strength, int defense, int dexterity, int speed,
                     int focus, int level, int exp) {
    this->name = name;
    this->level = level;
    this->exp = exp;

    this->baseHealth = health;
    this->baseMana = mana;
    this->baseStrength = strength;
    this->baseDefense = defense;
    this->baseDexterity = dexterity;
    this->baseSpeed = speed;
    this->baseFocus = focus;

    actHealth = baseHealth;
    actMana = baseMana;
    actStrength = baseStrength;
    actDefense = baseDefense;
    actDexterity = baseDexterity;
    actSpeed = baseSpeed;
    actFocus = baseFocus;
}

Combatant::~Combatant() {
}

void Combatant::addTurnEffect(TurnEffect *effect) {
    activeTurnEffects.insert(effect);
}

void Combatant::removeTurnEffect(TurnEffect *effect) {
    activeTurnEffects.erase(effect);
    delete (effect);
}

void Combatant::clearTurnEffects() {
    for (TurnEffect *e : activeTurnEffects) {
        removeTurnEffect(e);
    }
}

bool Combatant::hasTurnEffect(std::string name) {
    for (TurnEffect *te : activeTurnEffects) {
        if (te->getName() == name) {
            return true;
        }
    }
    return false;
}

int Combatant::displaySpellList() {
    int i = 1;
    for (; i < spellList.size() + 1; i++) {
        std::cout << i << "-" << spellList[i - 1]->getName() << '\n';
    }
    return i;
}

void Combatant::addSpell(Spell *newSpell) {
    spellList.push_back(newSpell);
}

int Combatant::displayTargets(std::vector<Combatant *> targets) {
    int i = 1;
    for (; i < targets.size() + 1; i++) {
        std::cout << i << "-" << targets[i - 1]->getName() << '\n';
    }
    return i;
}

void Combatant::activateTurnEffects() {
    for (TurnEffect *e : activeTurnEffects) {
        e->cycle();
    }
    for (TurnEffect *e : activeTurnEffects) {
        if (e->getDuration() <= 0) {
            removeTurnEffect(e);
        }
    }
}

std::string Combatant::getName() const {
    return name;
}

int Combatant::getLevel() const {
    return level;
}

int Combatant::getExp() const {
    return exp;
}

void Combatant::modLevel(int mod){
    level += mod;
}

void Combatant::modExp(int mod){
    exp += mod;
}


int Combatant::getBaseHealth() const {
    return baseHealth;
}

int Combatant::getBaseMana() const {
    return baseMana;
}

int Combatant::getBaseStrength() const {
    return baseStrength;
}

int Combatant::getBaseDefense() const {
    return baseDefense;
}

int Combatant::getBaseDexterity() const {
    return baseDexterity;
}

int Combatant::getBaseSpeed() const {
    return baseSpeed;
}

int Combatant::getBaseFocus() const {
    return baseFocus;
}

int Combatant::getActHealth() const {
    return actHealth;
}

int Combatant::getActMana() const {
    return actMana;
}

int Combatant::getActStrength() const {
    return actStrength;
}

int Combatant::getActDefense() const {
    return actDefense;
}

int Combatant::getActDexterity() const {
    return actDexterity;
}

int Combatant::getActSpeed() const {
    return actSpeed;
}

int Combatant::getActFocus() const {
    return actFocus;
}


void Combatant::setName(std::string name) {
    this->name = name;
}

void Combatant::setBaseHealth(int health) {
    baseHealth = health;
    if (baseHealth < 0) {
        baseHealth = 0;
    }
}

void Combatant::setBaseMana(int mana) {
    baseMana = mana;
    if (baseMana < 0) {
        baseMana = 0;
    }
}

void Combatant::setBaseStrength(int strength) {
    baseStrength = strength;
    if (baseStrength < 0) {
        baseStrength = 0;
    }
}

void Combatant::setBaseDefense(int defense) {
    baseDefense = defense;
    if (baseDefense < 0) {
        baseDefense = 0;
    }
}

void Combatant::setBaseDexterity(int dexterity) {
    baseDexterity = dexterity;
    if (baseDexterity < 0) {
        baseDexterity = 0;
    }
}

void Combatant::setBaseSpeed(int speed) {
    baseSpeed = speed;
    if (baseSpeed < 0) {
        baseSpeed = 0;
    }
}

void Combatant::setBaseFocus(int focus) {
    baseFocus = focus;
    if (baseFocus < 0) {
        baseFocus = 0;
    }
}

void Combatant::setActHealth(int health) {
    actHealth = health;
    if (actHealth < 0) {
        actHealth = 0;
    }
}

void Combatant::setActMana(int mana) {
    actMana = mana;
    if (actMana < 0) {
        actMana = 0;
    }
}

void Combatant::setActStrength(int strength) {
    actStrength = strength;
    if (actStrength < 0) {
        actStrength = 0;
    }
}

void Combatant::setActDefense(int defense) {
    actDefense = defense;
    if (actDefense < 0) {
        actDefense = 0;
    }
}

void Combatant::setActDexterity(int dexterity) {
    actDexterity = dexterity;
    if (actDexterity < 0) {
        actDexterity = 0;
    }
}

void Combatant::setActSpeed(int speed) {
    actSpeed = speed;
    if (actSpeed < 0) {
        actSpeed = 0;
    }
}

void Combatant::setActFocus(int focus) {
    actFocus = focus;
    if (actFocus < 0) {
        actFocus = 0;
    }
}


void Combatant::modBaseHealth(int mod) {
    baseHealth += mod;
    if (baseHealth < 0) {
        baseHealth = 0;
    }
}

void Combatant::modBaseMana(int mod) {
    baseMana += mod;
    if (baseMana < 0) {
        baseMana = 0;
    }
}

void Combatant::modBaseStrength(int mod) {
    baseStrength += mod;
    if (baseStrength < 0) {
        baseStrength = 0;
    }
}

void Combatant::modBaseDefense(int mod) {
    baseDefense += mod;
    if (baseDefense < 0) {
        baseDefense = 0;
    }
}

void Combatant::modBaseDexterity(int mod) {
    baseDexterity += mod;
    if (baseDexterity < 0) {
        baseDexterity = 0;
    }
}

void Combatant::modBaseSpeed(int mod) {
    baseSpeed += mod;
    if (baseSpeed < 0) {
        baseSpeed = 0;
    }
}

void Combatant::modBaseFocus(int mod) {
    baseFocus += mod;
    if (baseFocus < 0) {
        baseFocus = 0;
    }
}


void Combatant::modActHealth(int mod) {
    actHealth += mod;
    if (actHealth < 0) {
        actHealth = 0;
    }
}

void Combatant::modActMana(int mod) {
    actMana += mod;
    if (actMana < 0) {
        actMana = 0;
    }
}

void Combatant::modActStrength(int mod) {
    actStrength += mod;
    if (actStrength < 0) {
        actStrength = 0;
    }
}

void Combatant::modActDefense(int mod) {
    actDefense += mod;
    if (actDefense < 0) {
        actDefense = 0;
    }
}

void Combatant::modActDexterity(int mod) {
    actDexterity += mod;
    if (actDexterity < 0) {
        actDexterity = 0;
    }
}

void Combatant::modActSpeed(int mod) {
    actSpeed += mod;
    if (actSpeed < 0) {
        actSpeed = 0;
    }
}

void Combatant::modActFocus(int mod) {
    actFocus += mod;
    if (actFocus < 0) {
        actFocus = 0;
    }
}


void Combatant::modActHealth(double mod) {
    actHealth *= mod;
    if (actHealth < 0) {
        actHealth = 0;
    }
}

void Combatant::modActMana(double mod) {
    actMana *= mod;
    if (actMana < 0) {
        actMana = 0;
    }
}

void Combatant::modActStrength(double mod) {
    actStrength *= mod;
    if (actStrength < 0) {
        actStrength = 0;
    }
}

void Combatant::modActDefense(double mod) {
    actDefense *= mod;
    if (actDefense < 0) {
        actDefense = 0;
    }
}

void Combatant::modActDexterity(double mod) {
    actDexterity *= mod;
    if (actDexterity < 0) {
        actDexterity = 0;
    }
}

void Combatant::modActSpeed(double mod) {
    actSpeed *= mod;
    if (actSpeed < 0) {
        actSpeed = 0;
    }
}

void Combatant::modActFocus(double mod) {
    actFocus *= mod;
    if (actFocus < 0) {
        actFocus = 0;
    }
}

bool operator<(const Combatant &c1, const Combatant &c2) {
    return c1.getActSpeed() <= c2.getActSpeed();
}
