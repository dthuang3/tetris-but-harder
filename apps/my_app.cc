// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

namespace myapp {

using cinder::app::KeyEvent;


MyApp::MyApp() = default;

void MyApp::setup() {
  game_ = new tetris::Game();
  cinder::audio::SourceFileRef source_file = cinder::audio::load(
      loadAsset("../assets/Disfigure - Blank [NCS Release].mp3"));
  background_music_ = cinder::audio::Voice::create(source_file);
  background_music_->start();
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
  if (!background_music_->isPlaying()) {
    background_music_->start();
  }
}

void MyApp::draw() {
  ci::gl::clear();
  if (game_->IsToppedOut()) {
    DrawEndScreen(game_->GetScore());
    return;
  }
  const cinder::ivec2 size = {300,200};
  const cinder::vec2 location = {600.0f, 200.0f};
  const cinder::Color color = cinder::Color{1,1,1};
  const std::string score = std::to_string(game_->GetScore());
  DrawTetrisMatrix();
  ci::gl::drawString("Hold", ci::vec2{580.0f, 300.0f}, 
      color, ci::Font{kNormalFont, 30});
  // hold section
  DrawSectionAt(ci::vec2{620.0f, 420.0f}, 
      game_->GetHeldType());
  // next section
  ci::gl::drawString("Next", ci::vec2{580.0f, 500.0f}, 
      color, ci::Font(kNormalFont, 30));
  DrawSectionAt(ci::vec2{620.0f, 630.0f}, 
      game_->GetNextType());
  ci::gl::drawString("Score:", ci::vec2{580.0f, 150.0f}, 
      color, ci::Font(kNormalFont, 30));
  ci::gl::drawString(score, ci::vec2{580.0f, 200.0f}, 
      color, ci::Font{kNormalFont,30});
  game_->Draw();
}

void MyApp::keyDown(KeyEvent event) {
  switch(event.getCode()) {
    case KeyEvent::KEY_LEFT:
      game_->GetCurrentPiece()->body_->ApplyForceToCenter(
          b2Vec2{-10000.0f, 0.0f});
      break;
    case KeyEvent::KEY_RIGHT:
      game_->GetCurrentPiece()->body_->ApplyForceToCenter(
          b2Vec2{10000.0f, 0.0f});
      break;
    case KeyEvent::KEY_z:
      game_->GetCurrentPiece()->body_->ApplyTorque(-90000.0f);
      break;
    case KeyEvent::KEY_c:
      game_->GetCurrentPiece()->body_->ApplyTorque(90000.0f);
      break;
    case KeyEvent::KEY_DOWN:
      game_->GetCurrentPiece()->body_->ApplyForceToCenter(
          b2Vec2{0.0f, -10000.0f});
      break;
    case KeyEvent::KEY_RSHIFT:
      game_->HoldCurrentPiece();
      break;
    case KeyEvent::KEY_p:
      game_->Pause();
      game_->IsPaused() ? background_music_->pause() : background_music_->start();
      break;
  }
}

void MyApp::mouseDown(cinder::app::MouseEvent event) {
  delete game_;
  game_ = new tetris::Game();
}

void MyApp::DrawTetrisMatrix() {
  cinder::gl::color(1, 1, 1);
  cinder::gl::drawSolidRect(cinder::Rectf{20, 40, 
                                          60, 80 + 20*kTileSize});
  cinder::gl::drawSolidRect(cinder::Rectf{60, 
                                          40 + 20*kTileSize,
                                          60 + 10*kTileSize, 
                                          80 + 20*kTileSize});
  cinder::gl::drawSolidRect(cinder::Rectf{60 + 10*kTileSize, 
                                          40, 
                                          100 +  10*kTileSize, 
                                          80 + 20*kTileSize});
  // drawing dotted line for the top threshold 
  bool is_dash_blank = true;
  for (int i = 0; i < 21; i++) {
      if (is_dash_blank) {
          cinder::gl::drawLine(
              ci::vec2{tetris::kXMargin + i * kTileSize * 0.5,100.0f}, 
              ci::vec2{tetris::kXMargin + kTileSize * 0.5f * i + 20, 
                       100.0f});
      }
      is_dash_blank = !is_dash_blank;
  }
}

void MyApp::DrawEndScreen(int32_t score) {
  cinder::gl::color(1,1,1);
  auto width = (float) ci::app::getWindowWidth();
  auto height = (float) ci::app::getWindowHeight();
  cinder::gl::drawSolidRect(cinder::Rectf{0.25f * width, 
                                          0.25f * height, 
                                          0.75f * width,
                                          0.75f * height});
  const cinder::Color color = cinder::Color{0.0f,0.0f,0.0f};
  const std::string score_str = std::to_string(score);
  cinder::gl::drawString("Final Score:", 
      ci::vec2{width * 0.5f - 130.0f, 
               height * 0.5f - 52.5f}, 
               color, 
               ci::Font{kNormalFont, 30});
  cinder::gl::drawString(score_str, 
      ci::vec2{width * 0.5f - 70.0f,
               height * 0.5f},
               color,
               ci::Font{kNormalFont, 50});
  cinder::gl::drawString("Click anywhere to restart", 
      ci::vec2{width * 0.5f - 130.0f, height * 0.7f},  
      color,
      ci::Font{kNormalFont, 15});
}

void MyApp::DrawSectionAt(const ci::vec2& location, 
    tetris::TetrominoPieceType type) {
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
  ci::gl::drawSolidRect(cinder::Rectf{location.x - kTileSize * 0.5f, 
                                      location.y,
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
  ci::gl::color(tetris::kRed);
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
  ci::gl::color(tetris::kGreen);
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
