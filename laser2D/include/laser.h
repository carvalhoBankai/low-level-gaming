#pragma once
#include "raylib.h"
#include "sprite.h"

class Laser : public Sprite
{
private:
    /* data */
public:
    Laser(Texture2D texture, Vector2 position);
    ~Laser() override;
    bool canBeDiscarded() override;
};