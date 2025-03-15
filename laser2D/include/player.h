#pragma once
#include "sprite.h"
#include "raymath.h"
class Player : public Sprite
{
private:
    /* data */
public:
    Player(Texture2D texture, Vector2 position);
    void update(float dt) override;
    void draw() override;
    void input();
    void constraint();
};
