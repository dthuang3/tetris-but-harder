//
// Created by super on 4/21/2020.
//

#ifndef FINALPROJECT_GAME_H
#define FINALPROJECT_GAME_H

#include <Box2D/Box2D.h>
#include <random>
#include <vector>
#include "Tetromino.h"
#include <cinder/app/App.h>

namespace tetris {

class Game {
  const b2Vec2 kGravity_ = {0.0f, -10.0f};
  const float kTopOutHeight = 90.0f; 
  const size_t kFixturesToClearRow = 10;
 public:
  /**
   * Constructor for new game
   */
  Game(); 
  /**
   * Delete operator for game
   */
  ~Game();
  /**
   * Updates the current game by one frame equal to 1/60 seconds
   */
  void Update();
  /**
   * Returns the current piece that is falling
   * @return pointer to the current tetromino piece 
   */
  tetris::Tetromino* GetCurrentPiece();
  /**
   * Issues command to hold current piece
   */
  void HoldCurrentPiece();
  /**
   * Returns if the pieces have topped out / reached the threshold
   * @return true if reached threshold, false if below threshold
   */
  bool IsToppedOut();
  /**
   * Returns if the current game is paused
   * @return true if paused, false if not paused
   */
  bool IsPaused();
  /**
   * Pause/Resume the current game
   */
  void Pause();
  /**
   * Draws the current game state including all the pieces and their orientation
   */
  void Draw();
  /**
   * Returns the current player score
   * @return unsigned integer score
   */
  int32_t GetScore();
  /**
   * Returns the type of the currently held tetromino
   * @return type of the piece in the hold chamber
   */
  tetris::TetrominoPieceType GetHeldType();
  /**
   * Returns the type of the next piece in the rotation
   * @return type of the next piece to come
   */
  tetris::TetrominoPieceType GetNextType();
  /**
   * The physics world that the game uses
   */
  b2World* world_;
 private:
  /**
   * Sets the boundaries for the game, including the ground, ceiling, and left
   * and right walls
   */
  void SetupTetrisBoundary();
  /**
   * Returns a random tetromino type from a uniform distribution of integers
   * @return 
   */
  tetris::TetrominoPieceType GetRandomTetrimino();
  /**
   * Holds the current piece into the hold chamber 
   */
  void HoldPiece();
  /**
   * Checks if the first row has a full line
   * @return 
   */
  bool HasFullLine();
  /**
   * Clears the first row 
   */
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
