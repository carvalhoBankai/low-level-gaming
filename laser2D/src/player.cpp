#include "player.h"
#include <stdio.h>
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
}

void Player::input()
{
    direction.x = int(IsKeyDown(KEY_RIGHT)) - int(IsKeyDown(KEY_LEFT));
    direction.y = int(IsKeyDown(KEY_DOWN)) - int(IsKeyDown(KEY_UP));
    direction = Vector2Normalize(direction);
}