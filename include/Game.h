//
// Created by super on 4/21/2020.
//

#ifndef FINALPROJECT_GAME_H
#define FINALPROJECT_GAME_H
#include <Box2D/Box2D.h>

#include "Tetromino.h"
#include <vector>
namespace tetris {

class Game {
  b2Vec2 gravity_{0.0f, -10.0f};
 public:
  Game(); 
  void Step();
  void Reset();
  b2World* world_;
  tetris::Tetromino GetCurrentPiece();
 private:
  tetris::Tetromino* current_piece_;
  std::vector<tetris::Tetromino*> game_pieces_;
  
 private:
  void SetupTetrisBoundary();
  bool IsToppedOut();
};

}
#endif  // FINALPROJECT_GAME_H
