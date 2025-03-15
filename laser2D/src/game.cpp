#include "game.h"

Game::Game()
{
    InitWindow(GameSettings::WINDOW_WIDTH, GameSettings::WINDOW_HEIGHT, "Space ship");
    player = new Player(LoadTexture("images/spaceship.png"), Vector2{GameSettings::WINDOW_WIDTH / 2, GameSettings::WINDOW_HEIGHT / 2});
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        player->draw();
        EndDrawing();
    }
    CloseWindow();
}

Game::~Game()
{
    delete player;
}
