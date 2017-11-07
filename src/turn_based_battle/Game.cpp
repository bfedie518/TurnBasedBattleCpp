//
// Created by fedie on 01.11.16.
//

#include "Game.h"

Game::Game() {
    std::vector<Combatant *> playerTeam;
    std::vector<Combatant *> enemyTeam;
    int numTeammates;
    int numEnemies;
    Player player = Player("Fedie", 100, 100, 10, 10, 10, 10, 10, 1, 1);
    player.addSpell(new Spell_PoisonCloud());

    playerTeam.push_back(&player);

    std::cout << "How many teammates?\n";
    std::cin >> numTeammates;

    for (int i = 0; i < numTeammates; i++) {
        playerTeam.push_back(generateCombatant(teammateName(i + 1), false));
    }

    bool cont;
    bool playerWon = true;

    do {
        cont = false;

        std::cout << "How many enemies?\n";
        std::cin >> numEnemies;
        for (int i = 0; i < numEnemies; i++) {
            enemyTeam.push_back(generateCombatant(enemyName(i + 1), true));
        }
        if (!enemyTeam.empty()) {
            Battle *battle = new Battle(playerTeam, enemyTeam);
            playerWon = battle->getPlayerWon();
            delete(battle);

            for (Combatant *e : enemyTeam) {
                delete (e);
            }
            enemyTeam.clear();
        }
        if (playerWon) {
            std::cout << "Continue? (true/false)\n";
            std::cin >> cont;
        }

    } while (cont);
}


Combatant *Game::generateCombatant(std::string name, bool isEnemy) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> randLevel(5, 15);

    int level = randLevel(rng);
    std::uniform_int_distribution<int> randSmall(level - 2, level + 2);
    std::uniform_int_distribution<int> randLarge((level - 2) * 10, (level + 2) * 10);

    if (!isEnemy) {
        return new Player(name, randLarge(rng), randLarge(rng), randSmall(rng), randSmall(rng), randSmall(rng),
                          randSmall(rng), randSmall(rng), level, std::pow(level, 3));
    } else {
        return new Blob(name, randLarge(rng), randLarge(rng), randSmall(rng), randSmall(rng), randSmall(rng),
                        randSmall(rng), randSmall(rng), level, level);
    }

}

std::string Game::teammateName(int i) {
    boost::format fmt = boost::format("Teammate # %s") % i;
    return fmt.str();
}

std::string Game::enemyName(int i) {
    return (boost::format("Blob # %s") % i).str();

    //boost::format fmt = boost::format("Blob # %s") % i;
    //return fmt.str();
}