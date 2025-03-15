#include "sprite.h"
#include <stdio.h>
Sprite::Sprite(Texture2D texture, Vector2 position, Vector2 direction, int speed):texture(texture),position(position),direction(direction),speed(speed){}

Sprite::~Sprite(){
    
}

void Sprite::draw()
{

}

void Sprite::update(float dt)
{

}

void Sprite::move(float dt)
{
    position.x += direction.x * speed * dt;
    position.y += direction.y * speed * dt;
}