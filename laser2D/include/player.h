#pragma once
#include "sprite.h"
class Player : public Sprite
{
private:
    /* data */
public:
    Player(Texture2D texture, Vector2 position);
    void update(int dt) override;
    void draw() override;
};
