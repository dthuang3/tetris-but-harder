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
      color_ = ci::Color(240.0/255.0,152.0/255.0,12.0/255.0); // orange
      break;
    case 3: // 1x3 rectangle
      shape.SetAsBox(7.5f, 2.5f);
      color_ = ci::Color(35.0/255.0,250.0/255.0,20.0/255.0); // green
      break;
    case 4: // 2x2 square
      shape.SetAsBox(5.0f, 5.0f);
      color_ = ci::Color(250.0/255.0,223.0/255.0,20.0/255.0); // yellow
      break;
    case 5: // 1x4 rectangle
      shape.SetAsBox(5.0f, 2.5f);
      color_ = ci::Color(12.0/255.0,221.0/255.0,240.0/255.0); // sky blue
      break;
    case 6: // 2x3 rectangle
      shape.SetAsBox(7.5f, 5.0f);
      color_ = ci::Color(192.0/255.0,20.0/255.0,250.0/255.0); // purple
      break;
  }
  body_->CreateFixture(&fixture_def);
}

void Tetromino::Draw() {
//  b2Vec2 box2d_location = body_->GetPosition();
//  float cinder_x = box2d_location.x + 25.0f * 7.0f + x_margin;
//  float cinder_y = box2d_location.y * -7.0f + 700 + y_margin;
//  float top_left_x = cinder_x - 17.5f;
//  float top_left_y = cinder_y - 17.5f;
//  float bottom_right_x = cinder_x + 17.5f;
//  float bottom_right_y = cinder_y + 17.5f;
//  ci::gl::drawSolidRect(cinder::Rectf{ top_left_x, top_left_y, bottom_right_x, bottom_right_y});
  ci::PolyLine2 cinder_vertices;
  b2PolygonShape* polygon_shape_ptr = (b2PolygonShape*) body_->GetFixtureList()->GetShape();
  for (size_t i = 0; i < polygon_shape_ptr->GetVertexCount(); i++) {
    b2Vec2 local_vertex = polygon_shape_ptr->GetVertex(i);
    b2Vec2 world_vertex = body_->GetWorldPoint(local_vertex);
    cinder_vertices.push_back(ci::vec2(
        (world_vertex.x + 25.0f) * 7.0f + x_margin, 
        world_vertex.y * -7.0f + 700 + y_margin));
  }
  ci::gl::color(color_);
  ci::gl::drawSolid(cinder_vertices);
  
}


}

