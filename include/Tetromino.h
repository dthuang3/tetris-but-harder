//
// Created by super on 4/20/2020.
//

#ifndef FINALPROJECT_TETROMINOS_H
#define FINALPROJECT_TETROMINOS_H
#include <Box2dUtils.h>
#include <Box2D/Box2D.h>
namespace Tetris {

class Tetromino {
  const size_t tile_size_ = 35;
 public:
  Tetromino(char letter_type);
  ~Tetromino();
  void Draw();
  void update(); 
  float GetX();
  float GetY();
  void Rotate();
  b2Body* body_;
  float radius_;
 private:
  
};


}


#endif  // FINALPROJECT_TETROMINOS_H
