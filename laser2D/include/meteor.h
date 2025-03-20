#pragma once
#include "raylib.h"
#include "sprite.h"

class Meteor : public Sprite
{
private:
    float getRandomUniformFloat(float a, float b);
    float rotation;
    Rectangle rectangle;
public:
    Meteor(Texture2D texture);
    void draw() override;
    void update(float dt) override;
};