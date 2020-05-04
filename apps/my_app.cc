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
  // hold section
  DrawSectionAt(ci::vec2{620.0f, 420.0f}, game_->GetHeldType());
  // next section
  ci::gl::drawString("Next", ci::vec2{580.0f, 500.0f}, color, ci::Font(kNormalFont, 40));
  DrawSectionAt(ci::vec2{620.0f, 630.0f}, game_->GetNextType());
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
  // drawing dotted line for the top threshold 
  bool is_dash_blank = true;
  for (int i = 0; i < 21; i++) {
      if (is_dash_blank) {
          cinder::gl::drawLine(ci::vec2{tetris::kXMargin + i*kTileSize*0.5, 100.0f}, ci::vec2{tetris::kXMargin + kTileSize * 0.5f * i + 20, 100.0f});
      }
      is_dash_blank = !is_dash_blank;
  }
}

void MyApp::DrawSectionAt(const ci::vec2& location, tetris::TetrominoPieceType type) {
 switch (type) {
   case tetris::TetrominoPieceType::S:
     DrawSPiece(location);
     break;
   case tetris::TetrominoPieceType::Z:
     DrawZPiece(location);
     break;
   case tetris::TetrominoPieceType::J:
     DrawJPiece(location);
     break;
   case tetris::TetrominoPieceType::O:
     DrawOPiece(location);
     break;
   case tetris::TetrominoPieceType::L:
     DrawLPiece(location);
     break;
   case tetris::TetrominoPieceType::I:
     DrawIPiece(location);
     break;
   case tetris::TetrominoPieceType::T:
     DrawTPiece(location);
     break;
   default:
     return; // draw nothing if empty
 }
}

void MyApp::DrawIPiece(const ci::vec2& location) {
  ci::gl::color(tetris::kCyan);
  ci::gl::drawSolidRect(ci::Rectf{location.x - tetris::kTileSize * 0.5f, 
                                      location.y - kTileSize * 2.0f,
                                      location.x + kTileSize * 0.5f,
                                      location.y + kTileSize * 2.0f});
}

void MyApp::DrawOPiece(const ci::vec2& location) {
  ci::gl::color(tetris::kYellow);
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize,
                                      location.y - kTileSize,
                                      location.x + kTileSize,
                                      location.y + kTileSize});
}

void MyApp::DrawLPiece(const ci::vec2& location) {
  ci::gl::color(tetris::kOrange);
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 0.5f,
                                      location.y - kTileSize * 2.0f,
                                      location.x + kTileSize * 0.5f,
                                      location.y});
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 0.5f, location.y,
                                      location.x + kTileSize * 1.5f,
                                      location.y + kTileSize});
}
  

void MyApp::DrawJPiece(const ci::vec2& location) {
  ci::gl::color(tetris::kBlue);
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 0.5f,
                                      location.y - 70.0f,
                                      location.x + kTileSize * 0.5f,
                                      location.y});
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 1.5f,
                                      location.y,
                                      location.x + kTileSize * 0.5f,
                                      location.y + kTileSize});
}

void MyApp::DrawTPiece(const ci::vec2& location) {
  ci::gl::color(tetris::kPurple);
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 1.5f,
                                      location.y - kTileSize,
                                      location.x + kTileSize * 1.5f,
                                      location.y});
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 0.5f,
                                      location.y,
                                      location.x + kTileSize * 0.5f,
                                      location.y + kTileSize});
}

void MyApp::DrawZPiece(const ci::vec2& location) {
  ci::gl::color(tetris::kGreen);
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 1.5f,
                                      location.y - kTileSize,
                                      location.x + kTileSize * 0.5f,
                                      location.y});
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 0.5f,
                                      location.y,
                                      location.x + kTileSize * 1.5f,
                                      location.y + kTileSize});
}

void MyApp::DrawSPiece(const ci::vec2& location) {
  ci::gl::color(tetris::kRed);
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 0.5f,
                                      location.y - kTileSize,
                                      location.x + kTileSize * 1.5f,
                                      location.y});
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 1.5f,
                                      location.y,
                                      location.x + kTileSize * 0.5f,
                                      location.y + kTileSize});

}

}  // namespace myapp
