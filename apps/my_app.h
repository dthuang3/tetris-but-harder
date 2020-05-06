// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2World.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <cinder/audio/audio.h>
#include <Game.h>
#include <Box2D/Dynamics/b2Body.h>
#include <cinder/app/App.h>
#include <cinder/Log.h>

namespace myapp {

const char kNormalFont[] = "Press Start 2P";
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
  /**
   * Draws the tetris matrix for pieces to fall into
   */
  static void DrawTetrisMatrix();
  /**
   * Draws the end screen to display user's final score
   * @param score player's final score
   */
  static void DrawEndScreen(int32_t score);
  /**
   * Draws a piece at designated section
   * @param location ci::vec2 location on cinder window
   * @param type type of piece to be drawn
   */
  static void DrawSectionAt(const ci::vec2& location, tetris::TetrominoPieceType type);
  /**
   * Draws the Z tetromino at given location
   * @param location where to draw Z piece
   */
  static void DrawZPiece(const ci::vec2& location);
  /**
   * Draws the L tetromino at given location
   * @param location where to draw L piece
   */
  static void DrawLPiece(const ci::vec2& location);
  /**
   * Draws the J tetromino at given location
   * @param location where to draw J piece
   */
  static void DrawJPiece(const ci::vec2& location);
  /**
   * Draws the O tetromino at given location
   * @param location where to draw O piece
   */
  static void DrawOPiece(const ci::vec2& location);
  /**
   * Draws the I tetromino at given location
   * @param location where to draw I piece
   */
  static void DrawIPiece(const ci::vec2& location);
  /**
   * Draws the T tetromino at given location
   * @param location where to draw T piece
   */
  static void DrawTPiece(const ci::vec2& location);
  /**
   * Draws the S tetromino at given location
   * @param location where to draw S piece
   */
  static void DrawSPiece(const ci::vec2& location);
  /**
   * The current running game in the app
   */
  tetris::Game* game_;
  /**
   * Voiceref to song playing in the background
   */
  ci::audio::VoiceRef background_music_;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
