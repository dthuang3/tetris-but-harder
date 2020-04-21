//
// Created by super on 4/21/2020.
//
#include <Game.h>
namespace Tetris {
Game::Game() {
  world_ = new b2World(kGravity);
  SetupTetrisBoundary();
}  
}