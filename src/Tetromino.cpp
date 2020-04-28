//
// Created by super on 4/20/2020.
//

#include "Tetromino.h"

#include <cinder/Rect.h>
#include <cinder/gl/gl.h>
#include <cinder/PolyLine.h>

namespace tetris {

Tetromino::Tetromino(b2World* world, char type) {
  b2BodyDef tetrimino_def;
  tetrimino_def.type = b2_dynamicBody;
  tetrimino_def.position.Set(0.0f, 100.0f);
  body_ = world->CreateBody(&tetrimino_def);
  b2PolygonShape shape;
  b2PolygonShape shape2;
  b2FixtureDef fixture_def;
  b2FixtureDef fixture_def2;
  fixture_def.shape = &shape;
  fixture_def.density = 1.0f;
  fixture_def2.shape = &shape2;
  fixture_def.density = 1.0f;
  type_ = type;
  switch (type) {
    case 'S': // "S" tetromino
      shape.SetAsBox(5.0f, 2.5f, b2Vec2{-2.5f,-2.5f}, 0);
      shape2.SetAsBox(5.0f, 2.5f, b2Vec2{2.5f, 2.5f}, 0);
      color_ = ci::Color(35.0/255.0,250.0/255.0,20.0/255.0); // green
      break;
    case 'Z': // "Z" Tetromino
      shape.SetAsBox(5.0f, 2.5f, b2Vec2{-2.5f,2.5f}, 0);
      shape2.SetAsBox(5.0f, 2.5f, b2Vec2{2.5f, -2.5f}, 0);
      color_ = ci::Color(247.0/255.0,22.0/255.0,22.0/255.0); // red
      break;
    case 'O': // "O" Tetromino
      shape.SetAsBox(5.0f, 5.0f);
      color_ = ci::Color(250.0/255.0,223.0/255.0,20.0/255.0); // yellow
      break;
    case 'I': // "I" Tetromino
      shape.SetAsBox(10.0f, 2.5f);
      color_ = ci::Color(12.0/255.0,221.0/255.0,240.0/255.0); // sky blue
      break;
    case 'T': // "T" Tetromino
      shape.SetAsBox(7.5f, 2.5f, b2Vec2{0.0f,2.5f}, 0);
      shape2.SetAsBox(2.5f, 2.5f, b2Vec2{0, -2.5f}, 0);
      color_ = ci::Color(192.0/255.0,20.0/255.0,250.0/255.0); // purple
      break;
    case 'J': // "J" Tetromino
      shape.SetAsBox(2.5f, 5.0f, b2Vec2{0.0f, 5.0f}, 0);
      shape2.SetAsBox(5.0f, 2.5f, b2Vec2{-2.5f, -2.5f},0);
      color_ = ci::Color(11.0/255.0, 65.0/255.0, 227.0/255.0); // dark blue
      break;
    case 'L': // "L" Tetromino
      shape.SetAsBox(2.5f, 5.0f, b2Vec2{0.0f, 5.0f}, 0);
      shape2.SetAsBox(5.0f, 2.5f, b2Vec2{2.5f, -2.5f},0);
      color_ = ci::Color(240.0/255.0,152.0/255.0,12.0/255.0); // orange
      break;
  }
  body_->CreateFixture(&fixture_def);
  body_->CreateFixture(&fixture_def2);
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
  std::vector<ci::vec2> vertex_vector;
  for (b2Fixture* fixture = body_->GetFixtureList(); fixture; fixture = fixture->GetNext()) {
    auto* polygon_shape_ptr = (b2PolygonShape*)fixture->GetShape();
    for (size_t i = 0; i < polygon_shape_ptr->GetVertexCount(); i++) {
      b2Vec2 local_vertex = polygon_shape_ptr->GetVertex(i);
      b2Vec2 world_vertex = body_->GetWorldPoint(local_vertex);
      // vs. push_back. Nice Touch
      vertex_vector.emplace_back(
          (world_vertex.x + 25.0f) * 7.0f + x_margin,
          world_vertex.y * -7.0f + 700 + y_margin);
    }
    ci::PolyLine2 cinder_vertices(vertex_vector, false);
    ci::gl::color(color_);
    ci::gl::drawSolid(cinder_vertices);
    vertex_vector.clear();
  }

  
}


}

