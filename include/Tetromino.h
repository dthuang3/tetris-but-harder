//
// Created by super on 4/20/2020.
//

#ifndef FINALPROJECT_TETROMINOS_H
#define FINALPROJECT_TETROMINOS_H
#include <Box2dUtils.h>
#include <Box2D/Box2D.h>
namespace tetris {

class Tetromino {
  const size_t tile_size_ = 35;
  const float screen_scaling_ = 3.5;
  const float x_margin = 60;
  const float y_margin = 40;
 public:
  Tetromino(b2World* world, char type);
  b2Body* body_;
  void Draw();
 private:
  char type_;
 private:
  void AddFixturesForI(b2PolygonShape shape, b2FixtureDef fixture);
  void AddFixturesForS(b2PolygonShape shape, b2FixtureDef fixture);
  void AddFixturesForZ(b2PolygonShape shape, b2FixtureDef fixture);
  void AddFixturesForJ(b2PolygonShape shape, b2FixtureDef fixture);
  void AddFixturesForL(b2PolygonShape shape, b2FixtureDef fixture);
  void AddFixturesForT(b2PolygonShape shape, b2FixtureDef fixture);
  void AddFixturesForO(b2PolygonShape shape, b2FixtureDef fixture);

};


}


#endif  // FINALPROJECT_TETROMINOS_H
