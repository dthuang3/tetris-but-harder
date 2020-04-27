//
// Created by super on 4/20/2020.
//

#include "Tetromino.h"

#include <cinder/Rect.h>
#include <cinder/gl/gl.h>

namespace tetris {

Tetromino::Tetromino(b2World* world, char type) {
  b2BodyDef tetrimino_def;
  tetrimino_def.type = b2_dynamicBody;
  tetrimino_def.position.Set(0.0f, 100.0f);
  body_ = world->CreateBody(&tetrimino_def);
  b2PolygonShape shape;
  b2FixtureDef fixture_def;
  fixture_def.shape = &shape;
  fixture_def.density = 5.0f;
  shape.SetAsBox(2.5f, 2.5f);
  body_->CreateFixture(&fixture_def);
  type_ = type;
  color_ = true;
  
//  switch (type) {
//    case 'I':
//      AddFixturesForI(square, square_def);
//    case 'S':
//      AddFixturesForS(square, square_def);
//    case 'Z':
//      AddFixturesForZ(square, square_def);
//    case 'J':
//      AddFixturesForJ(square, square_def);
//    case 'L':
//      AddFixturesForL(square, square_def);
//    case 'T':
//      AddFixturesForT(square, square_def);
//    case 'O':
//      AddFixturesForO(square, square_def);
//    default:
//      AddFixturesForI(square, square_def);
//  }
  
}

void Tetromino::AddFixturesForI(b2PolygonShape shape, b2FixtureDef fixture) {
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 7.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -7.5},0);
  body_->CreateFixture(&fixture);
}

void Tetromino::AddFixturesForS(b2PolygonShape shape, b2FixtureDef fixture) {
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{5.0f, 2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{-5.0f, -2.5},0);
  body_->CreateFixture(&fixture);
}

void Tetromino::AddFixturesForZ(b2PolygonShape shape, b2FixtureDef fixture) {
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{-5.0f, 2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{5.0f, -2.5},0);
  body_->CreateFixture(&fixture);
}

void Tetromino::AddFixturesForJ(b2PolygonShape shape, b2FixtureDef fixture) {
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 7.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{-5.0f, -2.5},0);
  body_->CreateFixture(&fixture);
}

void Tetromino::AddFixturesForL(b2PolygonShape shape, b2FixtureDef fixture) {
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 7.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{5.0f, -2.5},0);
  body_->CreateFixture(&fixture);
}

void Tetromino::AddFixturesForT(b2PolygonShape shape, b2FixtureDef fixture) {
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{-5.0f, 2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, 2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{5.0f, 2.5f},0);
  body_->CreateFixture(&fixture);
  shape.SetAsBox(2.5f, 2.5f, b2Vec2{0.0f, -2.5},0);
  body_->CreateFixture(&fixture);
}

void Tetromino::AddFixturesForO(b2PolygonShape shape, b2FixtureDef fixture) {
  shape.SetAsBox(5.0f, 5.0f, b2Vec2{0.0f, 0.0f}, 0);
  body_->CreateFixture(&fixture);
}

void Tetromino::Draw() {
  b2Vec2 box2d_location = body_->GetPosition();
  float cinder_x = box2d_location.x + 50.0f * screen_scaling_ + x_margin;
  float cinder_y = box2d_location.y * -7.0f + 700 + y_margin;
  float top_left_x = cinder_x - 17.5f;
  float top_left_y = cinder_y - 17.5f;
  float bottom_right_x = cinder_x + 17.5f;
  float bottom_right_y = cinder_y + 17.5f;
  
  ci::gl::drawSolidRect(cinder::Rectf{ top_left_x, top_left_y, bottom_right_x, bottom_right_y});
  
}

}

