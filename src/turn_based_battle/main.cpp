#include "stdafx.h"
#include "Game.h"


int main() {
    bool restart;
    do {
        Game();
        std::cout << "Restart? (true/false)\n";
        std::cin >> restart;
    } while (restart);

    return 0;
}

