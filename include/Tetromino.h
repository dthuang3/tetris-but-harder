//
// Created by super on 4/20/2020.
//

#ifndef FINALPROJECT_TETROMINOS_H
#define FINALPROJECT_TETROMINOS_H
#include <Box2dUtils.h>
#include <Box2D/Box2D.h>
namespace tetris {

enum TetrominoPieceType {
  I, J, L, S, Z, T, O, Empty
};

class Tetromino {
  const size_t tile_size_ = 35;
  const float screen_scaling_ = 3.5;
  const float x_margin = 60;
  const float y_margin = 40;
 public:
  Tetromino(b2World* world, TetrominoPieceType type);
  b2Body* body_;
  void Draw();
  tetris::TetrominoPieceType GetType();
 private:
  TetrominoPieceType type_;
  ci::Color color_;

};


}


#endif  // FINALPROJECT_TETROMINOS_H
