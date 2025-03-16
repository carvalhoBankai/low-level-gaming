#include "game.h"
#include <stdio.h>
#include <cstdlib>

Game::Game()
{
    InitWindow(GameSettings::WINDOW_WIDTH, GameSettings::WINDOW_HEIGHT, "Space ship");
    generateStartData();
    player = new Player(LoadTexture("images/spaceship.png"), Vector2{GameSettings::WINDOW_WIDTH / 2, GameSettings::WINDOW_HEIGHT / 2});
    starTexture = LoadTexture("images/star.png");
}

void Game::generateStartData()
{
    for (int i = 0; i < 30; i++)
    {
        Vector2 pos = {static_cast<float>(rand() % GameSettings::WINDOW_WIDTH), static_cast<float>(rand() % GameSettings::WINDOW_HEIGHT)};
        float size = 0.5f + static_cast<float>(rand()) / RAND_MAX * (1.8f - 0.5f); // Random float between 0.5 and 1.6
        starData.emplace_back(pos, size);
    }
}

void Game::drawStar()
{
    for (const auto &starData : starData)
    {
        DrawTextureEx(starTexture, starData.first, 0, starData.second, WHITE);
    }
}

void Game::update()
{
    float dt = GetFrameTime();
    player->update(dt);
}

void Game::draw()
{
    BeginDrawing();
        ClearBackground({15, 10, 25, 255});
        drawStar();
        player->draw();
    EndDrawing();
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        update();
        draw();
    }
    CloseWindow();
}

Game::~Game()
{
    UnloadTexture(starTexture);
    delete player;
}
