// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2World.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <Game.h>
#include <Box2D/Dynamics/b2Body.h>
#include <cinder/app/App.h>
#include <cinder/Log.h>
#include <Box2dUtils.h>
namespace myapp {

const char kNormalFont[] = "Arial";
const size_t kTileSize = 35;

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void mouseDown(cinder::app::MouseEvent) override;
 private:
  static void DrawTetrisMatrix();
  static void DrawSectionAt(const ci::vec2& location, tetris::TetrominoPieceType type);
  static void DrawZPiece(const ci::vec2& location);
  static void DrawLPiece(const ci::vec2& location);
  static void DrawJPiece(const ci::vec2& location);
  static void DrawOPiece(const ci::vec2& location);
  static void DrawIPiece(const ci::vec2& location);
  static void DrawTPiece(const ci::vec2& location);
  static void DrawSPiece(const ci::vec2& location);
  tetris::Game* game_;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
