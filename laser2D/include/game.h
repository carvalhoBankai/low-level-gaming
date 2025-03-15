#pragma once
#include "raylib.h"
#include "GameSettings.h"
#include "player.h"
class Game
{
private:
   Player *player;

public:
   Game();
   ~Game();
   void run();
};