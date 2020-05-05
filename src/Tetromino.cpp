//
// Created by super on 4/20/2020.
//

#include "Tetromino.h"

namespace tetris {

Tetromino::Tetromino(b2World* world, TetrominoPieceType type) {
  b2BodyDef tetrimino_def;
  tetrimino_def.type = b2_dynamicBody;
  tetrimino_def.position.Set(kStartingPosition.x, kStartingPosition.y);
  body_ = world->CreateBody(&tetrimino_def);
  b2PolygonShape shape, shape2, shape3, shape4;
  b2FixtureDef fixture_def, fixture_def2, fixture_def3, fixture_def4;
  fixture_def.shape = &shape;
  fixture_def2.shape = &shape2;
  fixture_def3.shape = &shape3;
  fixture_def4.shape = &shape4;
  fixture_def.density = kDensity;
  fixture_def2.density = kDensity;
  fixture_def3.density = kDensity;
  fixture_def4.density = kDensity;
  type_ = type;
  // should be using inheritance/polymorphism
  // improvement to object design / project structure 
  switch (type_) {
    case S: // "S" tetromino
      //       |4|2|
      //     |1|3|
      shape.SetAsBox(2.5f, 2.5f, b2Vec2{-5.0f,-2.5f}, 0);  // 1
      shape2.SetAsBox(2.5f, 2.5f, b2Vec2{5.0f, 2.5f}, 0);  // 2
      shape3.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f}, 0); // 3
      shape4.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f}, 0);  // 4
      color_ = kGreen;
      break;
    case Z: // "Z" Tetromino
      //     |3|1|
      //       |2|4|
      shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f,},0);   // 1
      shape2.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f}, 0); // 2
      shape3.SetAsBox(2.5f, 2.5f, b2Vec2{-5.0f, 2.5f},0);  // 3
      shape4.SetAsBox(2.5f, 2.5f, b2Vec2{5.0f, -2.5f}, 0); // 4
      color_ = kRed;
      break;
    case O: // "O" Tetromino
      //      |1|4|
      //      |3|2|
      shape.SetAsBox(2.5f, 2.5f, b2Vec2{-2.5f, 2.5f}, 0);  // 1
      shape2.SetAsBox(2.5f, 2.5f, b2Vec2{2.5f, -2.5f},0);  // 2
      shape3.SetAsBox(2.5f, 2.5f, b2Vec2{-2.5f, -2.5f},0); // 3
      shape4.SetAsBox(2.5f, 2.5f, b2Vec2{2.5f, 2.5f},0);   // 4
      color_ = kYellow;
      break;
    case I: // "I" Tetromino
      //       |4|
      //       |1|
      //       |3|
      //       |2|
      shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f}, 0);   // 1
      shape2.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -7.5f},0);  // 2
      shape3.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f},0);  // 3
      shape4.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 7.5f},0);   // 4
      color_ = kCyan;
      break;
    case T: // "T" Tetromino
      //     |1|2|3|
      //       |4|
      shape.SetAsBox(2.5f, 2.5f, b2Vec2{-5.0f, 2.5f}, 0);  // 1
      shape2.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f},0);   // 2
      shape3.SetAsBox(2.5f, 2.5f, b2Vec2{5.0f, 2.5f},0);   // 3
      shape4.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f},0);  // 4
      color_ = kPurple;
      break;
    case J: // "J" Tetromino
      //       |2| 
      //       |1| 
      //     |3|4| 
      shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f}, 0);   // 1
      shape2.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 7.5f},0);   // 2
      shape3.SetAsBox(2.5f, 2.5f, b2Vec2{-5.0f, -2.5f},0); // 3
      shape4.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f},0);  // 4
      color_ = kBlue;
      break;
    case L: // "L" Tetromino
      //       |2|
      //       |1|
      //       |4|3|
      shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f}, 0);   // 1
      shape2.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 7.5f},0);   // 2
      shape3.SetAsBox(2.5f, 2.5f, b2Vec2{5.0f, -2.5f},0);  // 3
      shape4.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f},0);  // 4
      color_ = kOrange;
      break;
  }
  body_->CreateFixture(&fixture_def);
  body_->CreateFixture(&fixture_def2);
  body_->CreateFixture(&fixture_def3);
  body_->CreateFixture(&fixture_def4);
}

void Tetromino::Draw() {
  std::vector<ci::vec2> vertex_vector;
  // gets all the vertices of a specific shape and draws around them
  for (b2Fixture* fixture = body_->GetFixtureList(); fixture; 
  fixture = fixture->GetNext()) {
    auto* polygon_shape_ptr = (b2PolygonShape*)fixture->GetShape();
    for (size_t i = 0; i < polygon_shape_ptr->GetVertexCount(); i++) {
      b2Vec2 local_vertex = polygon_shape_ptr->GetVertex(i);
      b2Vec2 world_vertex = body_->GetWorldPoint(local_vertex);
      vertex_vector.emplace_back(
          (world_vertex.x + kXTranslation) * kScreenScaling + kXMargin,
          world_vertex.y * -kScreenScaling + kYTranslation + kYMargin);
    }
    ci::PolyLine2 cinder_vertices(vertex_vector, false);
    ci::gl::color(color_);
    ci::gl::drawSolid(cinder_vertices);
    vertex_vector.clear();
  }
}

tetris::TetrominoPieceType Tetromino::GetType() {
  return type_;
}

}

