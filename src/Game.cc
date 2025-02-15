//
// Created by super on 4/21/2020.
//
#include <Game.h>

namespace tetris {

Game::Game() {
  world_ = new b2World(kGravity_);
  SetupTetrisBoundary();
  current_piece_ = new tetris::Tetromino(*world_, GetRandomTetrimino());
  next_piece_type_ = GetRandomTetrimino();
  game_pieces_.push_back(current_piece_);
  is_topped_out_ = false;
  score_ = 0;
  should_hold_piece_ = false;
  held_piece_type_ = tetris::TetrominoPieceType::Empty;
  already_held_current_turn_ = false;
  is_paused = false;
}

Game::~Game() {
  delete world_;
  for (auto& piece : game_pieces_) {
    delete piece;
  }
  game_pieces_.clear();
}

void Game::Update() {
  if (is_topped_out_ || is_paused) {
    return;
  }
  world_->Step(1.0f / 60.0f, 8,3);
  score_++;
  bool past_threshold = current_piece_->body_->GetPosition().y < kTopOutHeight;
  if (!past_threshold && current_piece_->body_->GetLinearVelocity().Length() < 0.1f) {
    is_topped_out_ = true;
  }
  if (should_hold_piece_ && !already_held_current_turn_) {
      HoldPiece();
  } else if (current_piece_->body_->GetLinearVelocity().Length() < 0.1f) {
    if (HasFullLine()) {
      ClearLine();
      score_ += 10000;
    }
    current_piece_ = new tetris::Tetromino(*world_, next_piece_type_); 
    game_pieces_.push_back(current_piece_);
    already_held_current_turn_ = false;
    next_piece_type_ = GetRandomTetrimino();
  }
  should_hold_piece_ = false;
}

void Game::Draw() {
  for (auto& tetromino : game_pieces_) {
    tetromino->Draw();
  }
}

tetris::TetrominoPieceType Game::GetRandomTetrimino() {
  std::mt19937 rng(random_device_());
  std::uniform_int_distribution<int> uniform_int_distribution(0,6);
  switch (uniform_int_distribution(rng)) {
    case 0:
      return I;
    case 1:
      return J;
    case 2:
      return L;
    case 3:
      return Z;
    case 4:
      return S;
    case 5:
      return O;
    case 6:
      return T;
    default:
      return Z;
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
  rectangle.SetAsBox(0.1f, 70.0f, b2Vec2(-25.0f, 50.0f), 0); // left wall
  boundary_body->CreateFixture(&boundary_fixture);
  rectangle.SetAsBox(0.1f, 70.0f, b2Vec2(25.0f, 50.0f), 0); // right wall
  boundary_body->CreateFixture(&boundary_fixture);
  rectangle.SetAsBox(25.0f, 0.1f, b2Vec2(0,120.0f), 0); // top
  boundary_body->CreateFixture(&boundary_fixture);
}

bool Game::IsToppedOut() {
  return is_topped_out_;
}

bool Game::IsPaused() {
  return is_paused; 
}

void Game::Pause() {
  is_paused = !is_paused;
}

tetris::Tetromino* Game::GetCurrentPiece() {
  return current_piece_;
}

int32_t Game::GetScore() { 
  return score_;
}

void Game::HoldCurrentPiece() {
  should_hold_piece_ = true;
}

tetris::TetrominoPieceType Game::GetHeldType() {
  return held_piece_type_;
}

tetris::TetrominoPieceType Game::GetNextType() {
  return next_piece_type_;
}

void Game::HoldPiece() {
  tetris::TetrominoPieceType temp = held_piece_type_;
  held_piece_type_ = current_piece_->GetType();
  game_pieces_.pop_back();
  world_->DestroyBody(current_piece_->body_);
  if (temp == tetris::TetrominoPieceType::Empty) {
    current_piece_ =
        new tetris::Tetromino(*world_, next_piece_type_);
    next_piece_type_ = GetRandomTetrimino();
  } else {
    current_piece_ = new tetris::Tetromino(*world_, temp);
  }
  game_pieces_.push_back(current_piece_);
  already_held_current_turn_ = true;
}

bool Game::HasFullLine() {
  const size_t all_vertices = 4;
  size_t count = 0;
  const float line_threshold = 5.25f;
  // iterates through to check if first line is full 
  for (auto& piece : game_pieces_) {
    for (b2Fixture* fixture = piece->body_->GetFixtureList(); fixture; 
    fixture = fixture->GetNext()) {
      size_t v = 0;
      auto* polygon_shape_ptr = (b2PolygonShape*)fixture->GetShape();
      for (size_t i = 0; i < polygon_shape_ptr->GetVertexCount(); i++) {
        b2Vec2 local_vertex = polygon_shape_ptr->GetVertex(i);
        b2Vec2 world_vertex = piece->body_->GetWorldPoint(local_vertex);
        if (world_vertex.y <= line_threshold) {
          v++;
        }
        if (v == all_vertices) {
          count++;
        }
      }
    }
  }
  return count == kFixturesToClearRow;
}

void Game::ClearLine() {
  const float line_threshold = 5.25f;
  const size_t all_vertices = 4;
  // Not a map because there are repeated body references
  std::vector<std::pair<b2Body*, b2Fixture*>> fixtures_to_remove;
  // iterate through pieces to know which ones to delete
  for (auto& piece : game_pieces_) {
    for (b2Fixture* fixture = piece->body_->GetFixtureList(); fixture; 
    fixture = fixture->GetNext()) {
      size_t v = 0;
      auto* polygon_shape_ptr = (b2PolygonShape*)fixture->GetShape();
      for (size_t i = 0; i < polygon_shape_ptr->GetVertexCount(); i++) {
        b2Vec2 local_vertex = polygon_shape_ptr->GetVertex(i);
        b2Vec2 world_vertex = piece->body_->GetWorldPoint(local_vertex);
        if (world_vertex.y <= line_threshold) {
          v++;
        }
        if (v == all_vertices) {
          fixtures_to_remove.emplace_back(piece->body_, fixture);
        }
      }
    }
  }
  for (auto& body_fixture_pair : fixtures_to_remove) {
    // body_fixture_pair.first = b2Body*
    // body_fixture_pair.second = b2Fixture*
    body_fixture_pair.first->DestroyFixture(body_fixture_pair.second);
  }
}
}
