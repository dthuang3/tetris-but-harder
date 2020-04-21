//
// Created by super on 4/21/2020.
//

#ifndef FINALPROJECT_GAME_H
#define FINALPROJECT_GAME_H
#include <Box2D/Box2D.h>
namespace Tetris {
const b2Vec2 kGravity = new b2Vec2(0.0f, -10.0f);
class Game {
 public:
  Game() explicit;
  void Step();
  void Reset();
 private:
  std::vector<Tetris::Tetromino> tetrominos_;
  b2World world_;
 private:
  void SetupTetrisBoundary();
};

}
#endif  // FINALPROJECT_GAME_H
