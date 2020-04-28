//
// Created by super on 4/20/2020.
//

#include "Tetromino.h"

#include <cinder/Rect.h>
#include <cinder/gl/gl.h>
#include <cinder/PolyLine.h>

namespace tetris {

Tetromino::Tetromino(b2World* world, size_t type) {
  b2BodyDef tetrimino_def;
  tetrimino_def.type = b2_dynamicBody;
  tetrimino_def.position.Set(0.0f, 100.0f);
  body_ = world->CreateBody(&tetrimino_def);
  b2PolygonShape shape;
  b2FixtureDef fixture_def;
  fixture_def.shape = &shape;
  fixture_def.density = 5.0f;
  type_ = type;
  switch (type) {
    case 1: // 1x1 square
      shape.SetAsBox(2.5f, 2.5f);
      break;
    case 3: // 1x3 rectangle
      shape.SetAsBox(7.5f, 2.5f);
      break;
    case 4: // 2x2 square
      shape.SetAsBox(5.0f, 5.0f);
      break;
    case 5: // 1x4 rectangle
      shape.SetAsBox(5.0f, 2.5f);
      break;
    case 6: // 2x3 rectangle
      shape.SetAsBox(7.5f, 5.0f);
      break;
  }
  body_->CreateFixture(&fixture_def);
}

void Tetromino::Draw() {
  b2Vec2 box2d_location = body_->GetPosition();
  float cinder_x = box2d_location.x + 25.0f * 7.0f + x_margin;
  float cinder_y = box2d_location.y * -7.0f + 700 + y_margin;
  float top_left_x = cinder_x - 17.5f;
  float top_left_y = cinder_y - 17.5f;
  float bottom_right_x = cinder_x + 17.5f;
  float bottom_right_y = cinder_y + 17.5f;

  ci::gl::drawSolidRect(cinder::Rectf{ top_left_x, top_left_y, bottom_right_x, bottom_right_y});
  
}


}

