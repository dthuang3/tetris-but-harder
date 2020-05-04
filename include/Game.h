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
  const b2Vec2 kGravity_ = {0.0f, -10.0f};
  const float kTopOutHeight = 90.0f; 
  const size_t kFixturesToClearRow = 10;
 public:
  Game(); 
  ~Game();
  void Update();
  b2World* world_;
  tetris::Tetromino* GetCurrentPiece();
  void HoldCurrentPiece();
  bool IsToppedOut();
  bool IsPaused();
  bool Pause();
  void Draw();
  int32_t GetScore();
  tetris::TetrominoPieceType GetHeldType();
  tetris::TetrominoPieceType GetNextType();
 private:
  void SetupTetrisBoundary();
  tetris::TetrominoPieceType GetRandomTetrimino();
  void HoldPiece();
  bool HasFullLine();
  void ClearLine();
 private:
  tetris::Tetromino* current_piece_;
  std::vector<tetris::Tetromino*> game_pieces_;
  tetris::TetrominoPieceType next_piece_type_;
  bool is_topped_out_;
  bool is_paused;
  int32_t score_; 
  tetris::TetrominoPieceType held_piece_type_;
  bool should_hold_piece_;
  bool already_held_current_turn_;
  std::random_device random_device_;
};

}
#endif  // FINALPROJECT_GAME_H
