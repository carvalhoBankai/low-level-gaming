#include "player.h"
Player::Player(Texture2D texture, Vector2 position) : Sprite(texture, position, Vector2{}, GameSettings::PLAYER_SPEED)
{
}

void Player::draw(){
    DrawTextureV(texture, position, WHITE);    
}

void Player::update(int dt)
{

}