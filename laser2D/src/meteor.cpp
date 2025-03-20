#include "meteor.h"
#include <cstdlib>

Meteor::Meteor(Texture2D texture):Sprite(texture, Vector2{(float)GetRandomValue(0, GameSettings::WINDOW_WIDTH), (float)GetRandomValue(-150, -50)},Vector2{getRandomUniformFloat(-0.5, 0.5), 1}, GetRandomValue(300, 400))
{
    //position = Vector2{(float)GetRandomValue(0, GameSettings::WINDOW_WIDTH), (float)GetRandomValue(-150, -50)};
    //speed = GetRandomValue(300, 400);
   // direction = Vector2{getRandomFloat(-0.5, 0.5), 1};
   // Sprite(texture, position, direction, speed);
}

float Meteor::getRandomUniformFloat(float a, float b)
{
    return a + (rand() / (RAND_MAX + 1.0)) * (b - a);
}
