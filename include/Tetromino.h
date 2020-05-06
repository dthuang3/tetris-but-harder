//
// Created by super on 4/20/2020.
//

#ifndef FINALPROJECT_TETROMINOS_H
#define FINALPROJECT_TETROMINOS_H

#include <Box2D/Box2D.h>
#include <cinder/gl/gl.h>
#include <cinder/PolyLine.h>

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
  /**
   * Constructor a tetromino object
   * @param world the world the tetromino's body should be created in
   * @param type the type of piece // I, J, L, T, Z, S, O
   */
  Tetromino(b2World* world, TetrominoPieceType type);
  /**
   * Draws the current tetromino piece inside the cinder window
   * This function takes care of transformations / coordinate changes
   */
  void Draw();
  /**
   * Returns the type of tetromino
   * @return 
   */
  tetris::TetrominoPieceType GetType();
  /**
   * The body inside the box2d world that the tetromino is based on
   */
  b2Body* body_;
 private:
  /**
   * The type of piece the tetromino is (I, J, L, T, Z, S, O)
   */
  TetrominoPieceType type_;
  /**
   * Color of the tetromino (based on standard Tetris colors)
   */
  ci::Color color_;
};


}


#endif  // FINALPROJECT_TETROMINOS_H
