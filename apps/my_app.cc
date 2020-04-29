// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

namespace myapp {

using cinder::app::KeyEvent;


MyApp::MyApp() = default;

void MyApp::setup() {
  game_ = new tetris::Game();
  
//  b2Vec2 gravity_{0.0f, -20.0f};
//  world_ = new b2World(gravity_);
//  b2BodyDef boundary_def;
//  boundary_def.type = b2_staticBody;
//  boundary_def.position.Set(0.0f, 0.0f);
//
//  b2Body* boundary_body = world_->CreateBody(&boundary_def);
//  b2PolygonShape rectangle;
//
//  b2FixtureDef boundary_fixture;
//  boundary_fixture.shape = &rectangle;
//
//  rectangle.SetAsBox(25.0f, 1.0f, b2Vec2(0.0f,0.0f), 0); // bottom
//  boundary_body->CreateFixture(&boundary_fixture);
//  rectangle.SetAsBox(1.0f, 50.0f, b2Vec2(-25.0f, 50.0f), 0); // left wall
//  boundary_body->CreateFixture(&boundary_fixture);
//  rectangle.SetAsBox(1.0f, 50.0f, b2Vec2(25.0f, 50.0f), 0); // right wall
//  boundary_body->CreateFixture(&boundary_fixture);
//  
//  b2BodyDef falling_box_def;
//  falling_box_def.type = b2_dynamicBody;
//  falling_box_def.position.Set(0.0f, 15.0);
//  b2Body* falling_body = world_->CreateBody(&falling_box_def);
//  b2PolygonShape sq;
//  b2FixtureDef fix_def;
//  fix_def.shape = &sq;
//  fix_def.density = 20.0f;
//  sq.SetAsBox(5.0f, 5.0f);
//  falling_body->CreateFixture(&fix_def);
//  b2Vec2 s;
//  float a;
//  world_->Step(1.0f/60.0f, 8, 3);
//  float recent = 200;
//  float speedNow = falling_body->GetLinearVelocity().Length();
//  recent = 0.1 * speedNow + 0.9 * recent;
//  size_t count = 0;
//  while (recent > 2) {
//    world_->Step(1.0f/60.0f, 8, 3);
//    s = falling_body->GetPosition();
//    a = falling_body->GetAngularVelocity();
//    speedNow = falling_body->GetLinearVelocity().Length();
//    recent = 0.1 * speedNow + 0.9 * recent;
//    count++;
//  }
//  s = falling_body->GetPosition();
//  auto g = falling_body->GetLinearVelocity();
//  CI_LOG_D("HELLOW");
  
}

void MyApp::update() {
  if (game_->IsToppedOut()) {
    return;
  }
  game_->Update();
}

void MyApp::draw() {
  ci::gl::clear(ci::Color{125.0f/255.0f, 5.0f/255.0f, 119.0f/255.0f}, true);
//  cinder::gl::color(0,1,0);
//  for (float i = 0; i < 10; i++) {
//    cinder::gl::drawSolidRect(cinder::Rectf{60 + (35 * i), 40, 35 + 60 + (35 * i),75});
//  }
//  cinder::gl::color(1,0,0);
//  for (float i = 0; i < 20; i++) {
//    cinder::gl::drawSolidRect(cinder::Rectf{60, 40 + 35 * i, 95, 35*i + 35 + 40});
//  }
  const cinder::ivec2 size = {300,200};
  const cinder::vec2 location = {600.0f, 200.0f};
  const cinder::Color color = cinder::Color{1,1,1};
  const std::string score = std::to_string(game_->GetScore());
  DrawTetrisMatrix();
  ci::gl::drawString("Hold", ci::vec2{580.0f, 300.0f}, color, ci::Font{"Arial", 40});
  DrawHeldSection(game_->GetHeldType());
  game_->Draw();
  ci::gl::drawString("Score:", ci::vec2{580.0f, 150.0f}, color, ci::Font("Arial", 40));
  ci::gl::drawString(score, ci::vec2{580.0f, 200.0f}, color, ci::Font{"Arial", 40});
  
//  ci::gl::drawLine(ci::vec2{0,733},ci::vec2{400,733});
//  ci::gl::drawLine(ci::vec2{0,698}, ci::vec2{400,698});
//  ci::gl::drawLine(ci::vec2{0,663}, ci::vec2{400,663});
}

void MyApp::keyDown(KeyEvent event) {
  switch(event.getCode()) {
    case KeyEvent::KEY_LEFT:
      game_->GetCurrentPiece()->body_->ApplyForceToCenter(b2Vec2{-10000.0f, 0.0f});
      break;
    case KeyEvent::KEY_RIGHT:
      game_->GetCurrentPiece()->body_->ApplyForceToCenter(b2Vec2{10000.0f, 0.0f});
      break;
    case KeyEvent::KEY_z:
      game_->GetCurrentPiece()->body_->ApplyTorque(-90000.0f);
      break;
    case KeyEvent::KEY_c:
      game_->GetCurrentPiece()->body_->ApplyTorque(90000.0f);
      break;
    case KeyEvent::KEY_RSHIFT:
      game_->HoldCurrentPiece();
      break;
  }
}

void MyApp::mouseDown(cinder::app::MouseEvent event) {
    game_->Reset();
}

void MyApp::DrawTetrisMatrix() {
  cinder::gl::color(1, 1, 1);
  cinder::gl::drawSolidRect(cinder::Rectf{20, 40, 60, 80 + 20*kTileSize});
  cinder::gl::drawSolidRect(cinder::Rectf{60, 40 + 20*kTileSize, 60 + 10*kTileSize, 80 + 20*kTileSize});
  cinder::gl::drawSolidRect(cinder::Rectf{60 + 10*kTileSize, 40, 100 +  10*kTileSize, 80 + 20*kTileSize});
  bool is_dash_blank = true;
  for (int i = 0; i < 21; i++) {
      if (is_dash_blank) {
          cinder::gl::drawLine(ci::vec2{60.0f + i*17.5f, 100.0f}, ci::vec2{60.0f + 17.5f*i + 20, 100.0f});
      }
      is_dash_blank = !is_dash_blank;
  }
}

void MyApp::DrawHeldSection(tetris::TetrominoPieceType type) {
  cinder::vec2 location{620.0f, 450.0f};
  ci::Color color;
  switch (type) {
    case tetris::TetrominoPieceType::S: // "S" tetromino
      color = ci::Color(35.0f/255.0f,250.0f/255.0f,20.0f/255.0f); // green
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f, location.y - 35.0f, location.x + 52.5f, location.y});
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 52.5f, location.y, location.x + 17.5f, location.y + 35.0f});
      break;
    case tetris::TetrominoPieceType::Z: // "Z" Tetromino
      color = ci::Color(247.0f/255.0f,22.0f/255.0f,22.0f/255.0f); // red
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 52.5f, location.y - 35.0f, location.x + 17.5f, location.y});
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f, location.y, location.x + 52.5f, location.y + 35.0f});
      break;
    case tetris::TetrominoPieceType::O: // "O" Tetromino
      color = ci::Color(250.0f/255.0f,223.0f/255.0f,20.0f/255.0f); // yellow
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 35.0f, location.y - 35.0f, location.x + 35.0f, location.y + 35.0f});
      break;
    case tetris::TetrominoPieceType::I: // "I" Tetromino
      color = ci::Color(12.0f/255.0f,221.0f/255.0f,240.0f/255.0f); // sky blue
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f, location.y - 70.0f, location.x + 17.5f, location.y + 70.0f});
      break;
    case tetris::TetrominoPieceType::T: // "T" Tetromino
      color = ci::Color(192.0f/255.0f,20.0f/255.0f,250.0f/255.0f); // purple
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 52.5f, location.y - 35.0f, location.x + 52.5f, location.y});
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f, location.y, location.x + 17.5f, location.y + 35.0f});
      break;
    case tetris::TetrominoPieceType::J: // "J" Tetromino
      color = ci::Color(11.0f/255.0f, 65.0f/255.0f, 227.0f/255.0f); // dark blue
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f, location.y - 70.0f, location.x + 17.5f, location.y});
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 52.5f, location.y, location.x + 17.5f, location.y + 35.0f});
      break;
    case tetris::TetrominoPieceType::L:// "L" Tetromino
      color = ci::Color(240.0f/255.0f,152.0f/255.0f,12.0f/255.0f); // orange
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f, location.y - 70.0f, location.x + 17.5f, location.y});
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f, location.y, location.x + 52.5f, location.y + 35.0f});
      break;
  }
}

}  // namespace myapp
