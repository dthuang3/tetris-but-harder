# Development
---
### 4/19/20

* Linked Box2D to CMake
* Reviewing documentation on Box2D and cinder::gl

### 4/20/20
* Made Tetromino class and created pseudo-skeleton functions
* Drew simple shapes to output with cinder::gl.

### 4/21/20
* Fleshed out ideas with a Game class to represent a Tetris game/round.
* Made the base matrix in Box2D for which the tetrominos will be falling into.
* Implemented functions with the tools in Box2D.
* Created bodyrefs/fixturerefs/functions to create a new body with separate fixtures to represent a single tetromino.
* Attempted to use Box2D debugDraw, but unsuccessful. Will continue to attempt in following days.
* Created a random function to generate a new tetromino. 
* Still need to:
    * [ ] Continue to finish logic for game
    * [ ] Figure out how to use DebugDraw
    * [ ] Use openGL to visualize the items within the Box2D world
    
### 4/26/2020
* Simplify tetrominos to just basic polygon, the real tetromino shapes too complex to work with in Box2D
* Re-do the physics world inside Game.cc
* Create functionality to check when an object is still still/not moving.
* Still need to:
    * [ ] Create more types of pieces with simple polygon layout (square, rectangle, triangle)
    * [ ] Finish logic for game
    * [ ] Use openGL to visualize the items within the Box2D world