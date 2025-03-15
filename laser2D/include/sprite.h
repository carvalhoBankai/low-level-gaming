#pragma once
#include "GameSettings.h"
#include "raylib.h"

class Sprite
{
protected:
    /* data */
    Texture2D texture;
    Vector2 position;
    Vector2 direction;
    int speed;

public:
    Sprite(Texture2D texture, Vector2 position, Vector2 direction, int speed);
    virtual ~Sprite();
    virtual void update(int dt);
    virtual void draw();
};
