//
// Created by super on 4/21/2020.
//

#ifndef FINALPROJECT_GAME_H
#define FINALPROJECT_GAME_H
#include <Box2D/Box2D.h>

#include "Tetromino.h"
#include <vector>
namespace Tetris {

class Game {
 public:
  Game(); 
  void Step();
  void Reset();
  b2World* world_;
 private:
  b2Vec2 kGravity{0.0f, -10.0f};
 private:
  void SetupTetrisBoundary();
};

}
#endif  // FINALPROJECT_GAME_H
