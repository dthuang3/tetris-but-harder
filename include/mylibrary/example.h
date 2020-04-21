// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#include "cinder/Vector.h"
#include "Box2D/Box2D.h"

namespace mylibrary {

const float kScalingFactor = 50.0f;

cinder::vec2 ToScreen(b2Vec2 fin);
b2Vec2 ToPhysics(cinder::vec2 fin);
float ToPhysics(float fin);
float ToScreen(float fin);
float RadiansToDegrees(float radians);


}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
