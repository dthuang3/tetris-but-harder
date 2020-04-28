// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <Box2D/Dynamics/b2Body.h>
#include <cinder/app/App.h>
#include <cinder/Log.h>
#include <Box2dUtils.h>
#include <Game.h>
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
  ci::gl::clear();
//  cinder::gl::color(0,1,0);
//  for (float i = 0; i < 10; i++) {
//    cinder::gl::drawSolidRect(cinder::Rectf{60 + (35 * i), 40, 35 + 60 + (35 * i),75});
//  }
//  cinder::gl::color(1,0,0);
//  for (float i = 0; i < 20; i++) {
//    cinder::gl::drawSolidRect(cinder::Rectf{60, 40 + 35 * i, 95, 35*i + 35 + 40});
//  }
  ci::gl::color(0, 0, 0);
  DrawTetrisMatrix();
  ci::gl::color(0,1,0);
  game_->Draw();
  ci::gl::color(1,0,0);
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
      game_->GetCurrentPiece()->body_->ApplyTorque(-9000.0f);
      break;
    case KeyEvent::KEY_c:
      game_->GetCurrentPiece()->body_->ApplyTorque(9000.0f);
      break;
  }
}

void MyApp::DrawTetrisMatrix() {
  cinder::gl::color(1, 1, 1);
  cinder::gl::drawSolidRect(cinder::Rectf{20, 40, 60, 80 + 20*kTileSize});
  cinder::gl::drawSolidRect(cinder::Rectf{60, 40 + 20*kTileSize, 60 + 10*kTileSize, 80 + 20*kTileSize});
  cinder::gl::drawSolidRect(cinder::Rectf{60 + 10*kTileSize, 40, 100 +  10*kTileSize, 80 + 20*kTileSize});
}
}  // namespace myapp
