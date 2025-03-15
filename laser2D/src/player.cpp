#include "player.h"
#include <stdio.h>
#include <algorithm>
#include "GameSettings.h"
using namespace std;

Player::Player(Texture2D texture, Vector2 position) : Sprite(texture, position, Vector2{}, GameSettings::PLAYER_SPEED)
{
}

void Player::draw()
{
    DrawTextureV(texture, position, WHITE);
}

void Player::update(float dt)
{
    input();
    move(dt);
    constraint();
}

void Player::input()
{
    direction.x = int(IsKeyDown(KEY_RIGHT)) - int(IsKeyDown(KEY_LEFT));
    direction.y = int(IsKeyDown(KEY_DOWN)) - int(IsKeyDown(KEY_UP));
    direction = Vector2Normalize(direction);
}



void Player::constraint()
{
    position.x = max((float)0, min(position.x, (float)GameSettings::WINDOW_WIDTH - size.x));
    position.y = max((float)0, min((float)position.y, (float)GameSettings::WINDOW_HEIGHT - size.y));
}

