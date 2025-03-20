#include "game.h"
#include <stdio.h>
#include <cstdlib>

Game::Game()
{
    InitWindow(GameSettings::WINDOW_WIDTH, GameSettings::WINDOW_HEIGHT, "Space ship");
    InitAudioDevice();
    generateStartData();
    playerTexture = LoadTexture("images/spaceship.png");
    starTexture = LoadTexture("images/star.png");
    laserTexture = LoadTexture("images/laser.png");
    laserSound = LoadSound("audio/laser.wav");
    meteorTexture = LoadTexture("images/meteor.png");
    player = new Player(playerTexture, Vector2{GameSettings::WINDOW_WIDTH / 2, GameSettings::WINDOW_HEIGHT / 2}, [&](const Vector2 &position)
                        { lasers.push_back(new Laser(laserTexture, position)); 
                          PlaySound(laserSound); });
    meteorTimer = Timer(0.4, true, true, [&](){meteors.push_back(new Meteor(meteorTexture));});
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
    meteorTimer.update();
    discardSprites();
    for (const auto &laser : lasers)
    {
        laser->update(dt);
    }

    for (const auto &meteor : meteors)
    {
        meteor->update(dt);
    }
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground({15, 10, 25, 255});
    drawStar();
    player->draw();
    for (const auto &laser : lasers)
    {
        laser->draw();
    }

    for (const auto &meteor : meteors)
    {
        meteor->draw();
    }
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
    UnloadTexture(playerTexture);
    for (const auto &laser : lasers)
    {
        delete laser;
    }

    for (const auto &meteor : meteors)
    {
        delete meteor;
    }
    
    UnloadTexture(meteorTexture);
    UnloadTexture(laserTexture);
    UnloadSound(laserSound);
    CloseAudioDevice();
}

void Game::discardSprites()
{
    for (auto it = lasers.begin(); it != lasers.end();)
    {
        if ((*it)->canBeDiscarded())
        {
            delete *it;            // Delete the laser object
            it = lasers.erase(it); // Erase the laser from the vector and get the next iterator
        }
        else
        {
            ++it; // Move to the next element if it wasn't discarded
        }
    }

    for (auto it = meteors.begin(); it != meteors.end();)
    {
        if ((*it)->canBeDiscarded())
        {
            delete *it;            // Delete the meteor object
            it = meteors.erase(it); // Erase the meteor from the vector and get the next iterator
        }
        else
        {
            ++it; // Move to the next element if it wasn't discarded
        }
    }
}