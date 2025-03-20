#include "laser.h"
#include <stdio.h>

Laser::Laser(Texture2D texture, Vector2 position):Sprite(texture, position, Vector2{0, -1}, GameSettings::LASER_SPEED){}

bool Laser::canBeDiscarded()
{
    return Sprite::canBeDiscarded();
}

Laser::~Laser()
{
    
}