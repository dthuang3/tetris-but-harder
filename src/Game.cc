//
// Created by super on 4/21/2020.
//
#include <Game.h>
#include <cinder/app/App.h>

namespace tetris {

Game::Game() {
  world_ = new b2World(gravity_);
  SetupTetrisBoundary();
  current_piece_ = new tetris::Tetromino(world_, 1);
  game_pieces_.push_back(current_piece_);
  is_topped_out_ = false;
}

void Game::Update() {
//  if (is_topped_out_) {
//    return;
//  }
//  if (current_piece_->body_->GetLinearVelocity().Length() <= 0.5 &&
//      current_piece_->body_->GetAngularVelocity() <= 1) {
//    char letter = GetRandomTetrimino();
//    current_piece_ = new tetris::Tetromino(world_, letter);
//  }
  world_->Step(1.0f / 60.0f, 8,3);
  bool past_threshold = current_piece_->body_->GetPosition().y < 70.0f;
  if (!past_threshold && current_piece_->body_->GetLinearVelocity().Length() < 0.1f) {
    is_topped_out_ = true;
  }
  if (is_topped_out_) {
    return;
  }
  if (current_piece_->body_->GetLinearVelocity().Length() < 0.1f) {
    current_piece_ = new tetris::Tetromino(world_, 1);
    game_pieces_.push_back(current_piece_);
  }
  float recent = 200;
  float speedNow = current_piece_->body_->GetLinearVelocity().Length();
  recent = 0.1 * speedNow + 0.9 * recent;
  b2Vec2 s;
  float a;
  world_->Step(1.0f/60.0f, 8, 3);
  s = current_piece_->body_->GetPosition();
  a = current_piece_->body_->GetAngularVelocity();
  speedNow = current_piece_->body_->GetLinearVelocity().Length();
  recent = 0.1 * speedNow + 0.9 * recent;
  count++;
}

void Game::Draw() {
  for (auto& tetromino : game_pieces_) {
    tetromino->Draw();
  }
}

size_t Game::GetRandomTetrimino() {
  std::mt19937 rng(random_device_());
  std::uniform_int_distribution<int> uniform_int_distribution(0,4);
  switch (uniform_int_distribution(rng)) {
    case 0:
      return 1;
    case 1:
      return 3;
    case 2:
      return 4;
    case 3:
      return 5;
    case 4:
      return 6;
  }
}

void Game::SetupTetrisBoundary() {
  b2BodyDef boundary_def;
  boundary_def.type = b2_staticBody;
  boundary_def.position.Set(0.0f, 0.0f);
  
  b2Body* boundary_body = world_->CreateBody(&boundary_def);
  b2PolygonShape rectangle;
  
  b2FixtureDef boundary_fixture;
  boundary_fixture.shape = &rectangle;
  
  rectangle.SetAsBox(25.0f, 0.1f, b2Vec2(0,0), 0); // bottom
  boundary_body->CreateFixture(&boundary_fixture);
  rectangle.SetAsBox(0.1f, 50.0f, b2Vec2(-25.0f, 50.0f), 0); // left wall
  boundary_body->CreateFixture(&boundary_fixture);
  rectangle.SetAsBox(0.1f, 50.0f, b2Vec2(25.0f, 50.0f), 0); // right wall
  boundary_body->CreateFixture(&boundary_fixture);
}

bool Game::IsToppedOut() {
  return is_topped_out_;
}
}
