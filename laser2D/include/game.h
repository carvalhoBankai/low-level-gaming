#pragma once
#include "raylib.h"
#include "GameSettings.h"
#include "player.h"
#include <vector>
#include "laser.h"
#include "timer.h"
#include "meteor.h"

class Game
{
private:
   Player *player;
   std::vector<std::pair<Vector2, float>> starData;
   std::vector<Laser*> lasers;
   std::vector<Meteor*> meteors;
   Texture2D starTexture;
   Texture2D laserTexture;
   Texture2D playerTexture;
   Texture2D meteorTexture;
   Sound laserSound;
   Timer meteorTimer;
   void generateStartData();
   void drawStar();
   void update();
   void draw();
   void discardSprites();
   
public:
   Game();
   ~Game();
   void run();
};