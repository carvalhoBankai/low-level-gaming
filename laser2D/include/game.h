#pragma once
#include "raylib.h"
#include "GameSettings.h"
#include "player.h"
#include <vector>
class Game
{
private:
   Player *player;
   std::vector<std::pair<Vector2, float>> starData;
   Texture2D starTexture;
   void generateStartData();
public:
   Game();
   ~Game();
   void run();
   void drawStar();
   void update();
   void draw();
};