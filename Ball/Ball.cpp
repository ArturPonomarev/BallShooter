#include "Game.h"
#include <iostream>

int main()
{
    Game game;

    game.Init();

    game.GameLoop();

    game.Leave();

    std::cout << "End";
}

