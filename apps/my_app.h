// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <../blocks/Box2D/src/Box2D/Collision/Shapes/b2PolygonShape.h>
#include <../blocks/Box2D/src/Box2D/Dynamics/b2World.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <../include/mylibrary/example.h>
#include <Game.h>
namespace myapp {

const size_t kTileSize = 35;

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
 private:
  void DrawTetrisMatrix();

};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
