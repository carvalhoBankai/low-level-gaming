#pragma once
#include "raylib.h"
#include "sprite.h"

class Meteor : public Sprite
{
private:
    float getRandomUniformFloat(float a, float b);
public:
    Meteor(Texture2D texture);
};