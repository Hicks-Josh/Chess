#include <iostream>
#include <string>

#include "Game.h"

int main()
{
    Game::initialize();

    do
    {
        Board::getBoard().display(std::cout);
    } while (Game::getNextPlayer().makeMove());

    exit(EXIT_SUCCESS);
}