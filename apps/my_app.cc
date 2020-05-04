// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

namespace myapp {

using cinder::app::KeyEvent;


MyApp::MyApp() = default;

void MyApp::setup() {
  game_ = new tetris::Game();
}

void MyApp::update() {
  if (game_->IsToppedOut()) {
    // enter drawing end screen
    return;
  }
  if (game_->IsPaused()) {
    // enter pause mode;
  }
  game_->Update();
}

void MyApp::draw() {
  ci::gl::clear(ci::Color{125.0f/255.0f, 5.0f/255.0f, 119.0f/255.0f}, true);
  const cinder::ivec2 size = {300,200};
  const cinder::vec2 location = {600.0f, 200.0f};
  const cinder::Color color = cinder::Color{1,1,1};
  const std::string score = std::to_string(game_->GetScore());
  DrawTetrisMatrix();
  ci::gl::drawString("Hold", ci::vec2{580.0f, 300.0f}, color, ci::Font{kNormalFont, 40});
  DrawHeldSection(game_->GetHeldType());
  ci::gl::drawString("Next", ci::vec2{580.0f, 500.0f}, color, ci::Font(kNormalFont, 40));
  DrawNextSection(game_->GetNextType());
  game_->Draw();
  ci::gl::drawString("Score:", ci::vec2{580.0f, 150.0f}, color, ci::Font("Arial", 40));
  ci::gl::drawString(score, ci::vec2{580.0f, 200.0f}, color, ci::Font{"Arial", 40});
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
    case KeyEvent::KEY_p:
      game_->Pause(); 
      break;
  }
}

void MyApp::mouseDown(cinder::app::MouseEvent event) {
  delete game_;
  game_ = new tetris::Game();
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

void MyApp::DrawNextSection (tetris::TetrominoPieceType type) {
  cinder::vec2 location{620.0f, 630.0f};
  ci::Color color;
  switch (type) {
    case tetris::TetrominoPieceType::S:  // "S" tetromino
      color =
          ci::Color(35.0f / 255.0f, 250.0f / 255.0f, 20.0f / 255.0f);  // green
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f,
                                          location.y - 35.0f,
                                          location.x + 52.5f, location.y});
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 52.5f, location.y,
                                          location.x + 17.5f,
                                          location.y + 35.0f});
      break;
    case tetris::TetrominoPieceType::Z:  // "Z" Tetromino
      color =
          ci::Color(247.0f / 255.0f, 22.0f / 255.0f, 22.0f / 255.0f);  // red
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 52.5f,
                                          location.y - 35.0f,
                                          location.x + 17.5f, location.y});
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f, location.y,
                                          location.x + 52.5f,
                                          location.y + 35.0f});
      break;
    case tetris::TetrominoPieceType::O:  // "O" Tetromino
      color = ci::Color(250.0f / 255.0f, 223.0f / 255.0f,
                        20.0f / 255.0f);  // yellow
      ci::gl::color(color);
      ci::gl::drawSolidRect(
          cinder::Rectf{location.x - 35.0f, location.y - 35.0f,
                        location.x + 35.0f, location.y + 35.0f});
      break;
    case tetris::TetrominoPieceType::I:  // "I" Tetromino
      color = ci::Color(12.0f / 255.0f, 221.0f / 255.0f,
                        240.0f / 255.0f);  // sky blue
      ci::gl::color(color);
      ci::gl::drawSolidRect(
          cinder::Rectf{location.x - 17.5f, location.y - 70.0f,
                        location.x + 17.5f, location.y + 70.0f});
      break;
    case tetris::TetrominoPieceType::T:  // "T" Tetromino
      color = ci::Color(192.0f / 255.0f, 20.0f / 255.0f,
                        250.0f / 255.0f);  // purple
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 52.5f,
                                          location.y - 35.0f,
                                          location.x + 52.5f, location.y});
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f, location.y,
                                          location.x + 17.5f,
                                          location.y + 35.0f});
      break;
    case tetris::TetrominoPieceType::J:  // "J" Tetromino
      color = ci::Color(11.0f / 255.0f, 65.0f / 255.0f,
                        227.0f / 255.0f);  // dark blue
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f,
                                          location.y - 70.0f,
                                          location.x + 17.5f, location.y});
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 52.5f, location.y,
                                          location.x + 17.5f,
                                          location.y + 35.0f});
      break;
    case tetris::TetrominoPieceType::L:  // "L" Tetromino
      color = ci::Color(240.0f / 255.0f, 152.0f / 255.0f,
                        12.0f / 255.0f);  // orange
      ci::gl::color(color);
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f,
                                          location.y - 70.0f,
                                          location.x + 17.5f, location.y});
      ci::gl::drawSolidRect(cinder::Rectf{location.x - 17.5f, location.y,
                                          location.x + 52.5f,
                                          location.y + 35.0f});
      break;
  }
}

void MyApp::DrawHeldSection(tetris::TetrominoPieceType type) {
  cinder::vec2 location{620.0f, 420.0f};
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
