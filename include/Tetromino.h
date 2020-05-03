//
// Created by super on 4/20/2020.
//

#ifndef FINALPROJECT_TETROMINOS_H
#define FINALPROJECT_TETROMINOS_H
#include <Box2dUtils.h>
#include <Box2D/Box2D.h>
namespace tetris {

const size_t kTileSize = 35;
const float kScreenScaling = 7.0f;
const float kXMargin = 60.0f;
const float kYMargin = 40.0f;
const float kXTranslation = 25.0f;
const float kYTranslation = 700.0f;
const b2Vec2 kStartingPosition{0.0f, 100.0f};
const ci::Color kGreen = ci::Color(35.0f/255.0f,250.0f/255.0f,20.0f/255.0f);
const ci::Color kRed = ci::Color(247.0f/255.0f,22.0f/255.0f,22.0f/255.0f);
const ci::Color kCyan = ci::Color(12.0f/255.0f,221.0f/255.0f,240.0f/255.0f);
const ci::Color kPurple = ci::Color(192.0f/255.0f,20.0f/255.0f,250.0f/255.0f);
const ci::Color kOrange = ci::Color(240.0f/255.0f,152.0f/255.0f,12.0f/255.0f);
const ci::Color kYellow = ci::Color(250.0f/255.0f,223.0f/255.0f,20.0f/255.0f);
const ci::Color kBlue = ci::Color(11.0f/255.0f, 65.0f/255.0f, 227.0f/255.0f);

enum TetrominoPieceType {
  I, J, L, S, Z, T, O, Empty
};

class Tetromino {
  const float kDensity = 1.0f;
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
