// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <Box2D/Dynamics/b2Body.h>
#include <cinder/app/App.h>
#include <Box2dUtils.h>
#include <Game.h>
namespace myapp {

using cinder::app::KeyEvent;


MyApp::MyApp() { }

void MyApp::setup() {
  
}

void MyApp::update() { }

void MyApp::draw() {
  
//  cinder::gl::color(0,1,0);
//  for (float i = 0; i < 10; i++) {
//    cinder::gl::drawSolidRect(cinder::Rectf{60 + (35 * i), 40, 35 + 60 + (35 * i),75});
//  }
//  cinder::gl::color(1,0,0);
//  for (float i = 0; i < 20; i++) {
//    cinder::gl::drawSolidRect(cinder::Rectf{60, 40 + 35 * i, 95, 35*i + 35 + 40});
//  }
}

void MyApp::keyDown(KeyEvent event) {}

void MyApp::DrawTetrisMatrix() {
  cinder::gl::color(1, 1, 1);
  cinder::gl::drawSolidRect(cinder::Rectf{20, 40, 60, 80 + 20*kTileSize});
  cinder::gl::drawSolidRect(cinder::Rectf{60, 40 + 20*kTileSize, 60 + 10*kTileSize, 80 + 20*kTileSize});
  cinder::gl::drawSolidRect(cinder::Rectf{60 + 10*kTileSize, 40, 100 +  10*kTileSize, 80 + 20*kTileSize});
}
}  // namespace myapp
