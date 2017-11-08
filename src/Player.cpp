//
// Created by fedie on 15.10.16.
//

#include "stdafx.h"
#include "Player.h"
#include "Battle.h"
#include "TurnEffect_Defend.h"
#include "Spell.h"


void Player::levelUp() {
    modLevel(1);
    int choice;
    std::cout << "LEVEL UP! You are now level " << getLevel() << "\nIncrease a stat.\n\n";
    std::cout << "1-Health: " << getBaseHealth() << '\n';
    std::cout << "2-Mana: " << getBaseMana() << '\n';
    std::cout << "3-Strength: " << getBaseStrength() << '\n';
    std::cout << "4-Defense: " << getBaseDefense() << '\n';
    std::cout << "5-Dexterity: " << getBaseDexterity() << '\n';
    std::cout << "6-Speed: " << getBaseSpeed() << '\n';
    std::cout << "7-Focus: " << getBaseFocus() << '\n';

    std::cin >> choice;

    switch (choice) {
        case 1:
            modBaseHealth(10);
            modActHealth(10);
            break;
        case 2:
            modBaseMana(10);
            modActMana(10);
            break;
        case 3:
            modBaseStrength(1);
            setActStrength(getBaseStrength());
            break;
        case 4:
            modBaseDefense(1);
            setActDefense(getBaseDefense());
            break;
        case 5:
            modBaseDexterity(1);
            setActDexterity(getBaseDexterity());
            break;
        case 6:
            modBaseSpeed(1);
            setActSpeed(getBaseSpeed());
            break;
        case 7:
            modBaseFocus(1);
            setActFocus(getBaseFocus());
            break;
        default:
            break;
    }
}

void Player::modExp(int mod){
    Combatant::modExp(mod);
    determineLevel();
}

void Player::determineLevel(){
    int oldLevel = getLevel();
    int newLevel = (int) (std::cbrt(getExp()));
    if (newLevel > oldLevel){
        for (int i = 0; i < newLevel - oldLevel; i++){
            levelUp();
        }
    }
}

void Player::myTurn(Combatant *enemy) {
    activateTurnEffects();
    if (getActHealth() > 0) {
        int choice;
        bool isTurnOver;

        do {
            isTurnOver = false;
            std::cout << '\n' << getName() << " Health: " << getActHealth() << '\n';
            std::cout << getName() << " Mana: " << getActMana() << "\n\n";
            std::cout << "1-Attack\n2-Spells\n3-Defend\n";
            do {
                std::cin >> choice;
            } while (choice != 1 && choice != 2 && choice != 3);
            switch (choice) {
                case 1:
                    attack(enemy);
                    isTurnOver = true;
                    break;
                case 2:
                    isTurnOver = chooseSpell(enemy);
                    break;
                case 3:
                    defend();
                    isTurnOver = true;
                    break;
                default:
                    break;
            }
        } while (!isTurnOver);
    }else{
        std::cout << getName() << " has died!\n";
    }
}

void Player::myTurn(std::vector<Combatant *> playerTeam, std::vector<Combatant *> enemyTeam) {
    activateTurnEffects();
    int choice;
    bool isTurnOver;

    do {
        isTurnOver = false;
        std::cout << '\n' << getName() << " Health: " << getActHealth() << '\n';
        std::cout << getName() << " Mana: " << getActMana() << "\n\n";
        std::cout << "1-Attack\n2-Spells\n3-Defend\n";
        do {
            std::cin >> choice;
        } while (choice != 1 && choice != 2 && choice != 3);
        switch (choice) {
            case 1:
                isTurnOver = attack(enemyTeam);
                break;
            case 2:
                isTurnOver = chooseSpell(enemyTeam);
                break;
            case 3:
                defend();
                isTurnOver = true;
                break;
            default:
                break;
        }
    } while (!isTurnOver);
}


void Player::attack(Combatant *enemy) {
    bool isHit = Battle::willHit(this, enemy, 85);
    if (isHit) {
        int damage = Battle::damageCalc(this, enemy, 20);
        enemy->modActHealth(-damage);
        std::cout << "HIT!! You did " << damage << " damage.\n";
        std::cout << enemy->getActHealth() << " health remaining.\n\n";
    } else {
        std::cout << "You missed.\n\n";
    }
}

bool Player::attack(std::vector<Combatant *> targets) {
    int choice;
    int i = displayTargets(targets);
    std::cout << i << "-Back\n";
    do {
        std::cin >> choice;
    } while (choice < 1 || choice > i);
    if (choice == i) {
        return false;
    } else {
        attack(targets[choice - 1]);
        return true;
    }
}

bool Player::chooseSpell(Combatant *enemy) {
    int choice;
    int i = displaySpellList();
    std::cout << i << "-Back\n";
    do {
        std::cin >> choice;
    } while (choice < 1 || choice > i);
    if (choice == i) {
        return false;
    } else {
        if (spellList[choice - 1]->getManaCost() <= getActMana()) {
            spellList[choice - 1]->cast(this, enemy);
            return true;
        } else {
            std::cout << "Not enough mana.\n";
            return false;
        }
    }
}

bool Player::chooseSpell(std::vector<Combatant *> targets) {
    int spellChoice, targetChoice;
    int i = displaySpellList();
    std::cout << i << "-Back\n";
    do {
        std::cin >> spellChoice;
    } while (spellChoice < 1 || spellChoice > i);
    if (spellChoice == i) {
        return false;
    } else {
        i = displayTargets(targets);
        std::cout << i << "-Back\n";
        do {
            std::cin >> targetChoice;
        } while (targetChoice < 1 || targetChoice > i);
        if (targetChoice == i) {
            return false;
        } else {
            if (spellList[spellChoice - 1]->getManaCost() <= getActMana()) {
                spellList[spellChoice - 1]->cast(this, targets[targetChoice-1]);
                return true;
            } else {
                std::cout << "Not enough mana.\n";
                return false;
            }
        }
    }
}

void Player::defend() {
    modActDefense(1.5);
    addTurnEffect(new TurnEffect_Defend(this, 1));
    std::cout << "Defending!  Defense temporarily raised!\n\n";
}
