#include "sprite.h"
#include <stdio.h>

Sprite::~Sprite()
{
}

Sprite::Sprite(Texture2D texture, Vector2 position, Vector2 direction, int speed) : texture(texture), position(position), direction(direction), speed(speed)
{
    size = {(float)texture.width, (float)texture.height};
}

Sprite::Sprite() : texture{}, position{}, direction{}, speed{}, size{}{}

void Sprite::draw()
{
    DrawTextureV(texture, position, WHITE);
}

void Sprite::update(float dt)
{
    move(dt);
}

void Sprite::move(float dt)
{
    position.x += direction.x * speed * dt;
    position.y += direction.y * speed * dt;
}

bool Sprite::canBeDiscarded()
{
    return position.y <= -300 || position.y >= GameSettings::WINDOW_HEIGHT + 300;
}