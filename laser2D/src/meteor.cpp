#include "meteor.h"
#include <cstdlib>

Meteor::Meteor(Texture2D texture):Sprite(texture, Vector2{(float)GetRandomValue(0, GameSettings::WINDOW_WIDTH), (float)GetRandomValue(-150, -50)},Vector2{getRandomUniformFloat(-0.5, 0.5), 1}, GetRandomValue(300, 400))
{
    rotation = 0;
    rectangle = Rectangle{0, 0, size.x, size.y};
}

float Meteor::getRandomUniformFloat(float a, float b)
{
    return a + (rand() / (RAND_MAX + 1.0)) * (b - a);
}

void Meteor::draw()
{
    Rectangle targetRectangle = Rectangle{position.x, position.y, size.x, size.y};
    DrawTexturePro(texture, rectangle, targetRectangle, Vector2{size.x/2, size.y/2},rotation, WHITE);
}

void Meteor::update(float dt)
{
    Sprite::update(dt);
    rotation += 50*dt;
}
