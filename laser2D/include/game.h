#pragma once
#include "raylib.h"
#include "GameSettings.h"
#include "player.h"
#include <vector>
#include "laser.h"
class Game
{
private:
   Player *player;
   std::vector<std::pair<Vector2, float>> starData;
   std::vector<Laser*> lasers;
   Texture2D starTexture;
   Texture2D laserTexture;
   void generateStartData();
   void drawStar();
   void update();
   void draw();
   
public:
   Game();
   ~Game();
   void run();
};