// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <Game.h>

using namespace tetris;

TEST_CASE("Game Current Piece", "[Game]") {
  Game* game = new Game();
  REQUIRE(game->GetCurrentPiece()->GetType() != tetris::TetrominoPieceType::Empty);
  delete game;
}

TEST_CASE("Is Topped Out", "[Game]") {
  Game* game = new Game();
  SECTION("Start of game") {
    REQUIRE_FALSE(game->IsToppedOut());
  }
  SECTION("After running for 100000 frames") {
    // run world for 10000 frames at 60 frames per iteration
    for (size_t i = 0; i < 100000; i++) {
      game->Update();
    }
    REQUIRE(game->IsToppedOut());
  }
  delete game;
}

TEST_CASE("Get Score", "[Game]") {
  Game* game = new Game();
  REQUIRE(game->GetScore() == 0);
  delete game;
}

TEST_CASE("Hold Current Piece", "[Game]") {
  Game* game = new Game();
  SECTION("Beginning nothing is held") {
    REQUIRE(game->GetHeldType() == TetrominoPieceType::Empty);
  }
  
  SECTION("After holding, it is no longer empty") {
    TetrominoPieceType to_be_held = game->GetCurrentPiece()->GetType();
    game->HoldCurrentPiece();
    game->Update();
    REQUIRE(game->GetHeldType() != TetrominoPieceType::Empty);
    REQUIRE(game->GetHeldType() == to_be_held);
  }
  delete game;
}

TEST_CASE("Get Next Type", "[Game]") {
  Game* game = new Game();
  REQUIRE(game->GetNextType() != TetrominoPieceType::Empty);
  delete game;
}

TEST_CASE("Update game", "[Game]") {
  Game* game = new Game();

  SECTION("Beginning of game") {
    REQUIRE(game->GetScore() == 0);
    REQUIRE(game->GetHeldType() == TetrominoPieceType::Empty);
  }

  SECTION("Update game one step") {
    game->Update();
    REQUIRE(game->GetScore() == 1);
    REQUIRE(game->GetHeldType() == TetrominoPieceType::Empty);
  }

  SECTION("Update game one step and hold piece") {
    TetrominoPieceType type_to_be_held = game->GetCurrentPiece()->GetType();
    game->HoldCurrentPiece();
    game->Update();
    REQUIRE(game->GetScore() == 1);
    REQUIRE(game->GetHeldType() != TetrominoPieceType::Empty);
    REQUIRE(game->GetHeldType() == type_to_be_held);
  }
  delete game;
}
