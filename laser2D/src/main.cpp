#include "game.h"

int main()
{
    Game * game = new Game();
    game->run();
    delete game;
    return 0;
}