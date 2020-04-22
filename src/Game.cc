//
// Created by super on 4/21/2020.
//
#include <Game.h>
namespace Tetris {

Game::Game() {
  world_ = new b2World(kGravity);
  SetupTetrisBoundary();
}

void Game::SetupTetrisBoundary() {
  b2BodyDef boundary_def;
  boundary_def.type = b2_staticBody;
  boundary_def.position.Set(0.0f, 0.0f);
  
  b2Body* boundary_body = world_->CreateBody(&boundary_def);
  b2PolygonShape rectangle;
  
  b2FixtureDef boundary_fixture;
  boundary_fixture.shape = &rectangle;
  
  rectangle.SetAsBox(25.0f, 1.0f, b2Vec2(0,0), 0); // bottom
  boundary_body->CreateFixture(&boundary_fixture);
  rectangle.SetAsBox(1.0f, 50.0f, b2Vec2(-25.0f, 50.0f), 0); // left wall
  boundary_body->CreateFixture(&boundary_fixture);
  rectangle.SetAsBox(1.0f, 50.0f, b2Vec2(25.0f, 50.0f), 0); // right wall
  boundary_body->CreateFixture(&boundary_fixture);
}
}