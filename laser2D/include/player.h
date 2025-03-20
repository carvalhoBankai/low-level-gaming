#pragma once
#include "sprite.h"
#include "raymath.h"
#include <functional>
class Player : public Sprite
{
private:
    std::function<void(const Vector2 &)> shootLaser;

public:
    Player(Texture2D texture, Vector2 position, std::function<void(const Vector2 &)> shootLaser);
    void update(float dt) override;
    void draw() override;
    ~Player();
    void input();
    void constraint();
};
