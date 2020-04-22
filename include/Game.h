//
// Created by super on 4/21/2020.
//

#ifndef FINALPROJECT_GAME_H
#define FINALPROJECT_GAME_H
#include <Box2D/Box2D.h>

#include <random>
#include <vector>

#include "Tetromino.h"
namespace tetris {

class Game {
  b2Vec2 gravity_{0.0f, -10.0f};
 public:
  Game(); 
  void Update();
  void Reset();
  b2World* world_;
  tetris::Tetromino GetCurrentPiece();
 private:
  tetris::Tetromino* current_piece_;
  std::vector<tetris::Tetromino*> game_pieces_;
  bool is_topped_out_;
  
 private:
  void SetupTetrisBoundary();
  bool IsToppedOut();
  char GetRandomTetrimino();
  std::random_device random_device_;
};

}
#endif  // FINALPROJECT_GAME_H
