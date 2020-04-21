// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/example.h>

namespace mylibrary {

cinder::vec2 mylibrary::ToScreen(b2Vec2 fin) {
  return cinder::vec2{fin.x, fin.y,} * kScalingFactor;
}
b2Vec2 mylibrary::ToPhysics(cinder::vec2 fin) {
  return b2Vec2{fin.x/kScalingFactor, fin.y/kScalingFactor};
} 
float mylibrary::ToScreen(float fin) {
  return fin * kScalingFactor;
}
float mylibrary::ToPhysics(float fin) {
  return fin / kScalingFactor;
}
float mylibrary::RadiansToDegrees(float radians) {
  return radians * 180.0f/M_PI;
}

}  // namespace mylibrary
