// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <Box2D/Dynamics/b2Body.h>
#include <cinder/app/App.h>

namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() { }

void MyApp::setup() {

  
}

void MyApp::update() { }

void MyApp::draw() {
  DrawTetrisMatrix();
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::DrawTetrisMatrix() {
  cinder::gl::color(1, 1, 1);
  cinder::gl::drawSolidRect(cinder::Rectf{20, 20, 40, 775});
  cinder::gl::drawSolidRect(cinder::Rectf{40, 755, 500, 775});
  cinder::gl::drawSolidRect(cinder::Rectf{500, 20, 520, 775});
}
}  // namespace myapp
