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
    * [x] Continue to finish logic for game
    * [ ] ~~Figure out how to use DebugDraw~~
    * [x] Use openGL to visualize the items within the Box2D world
    
### 4/26/2020
* Simplify tetrominos to just basic polygon, the real tetromino shapes are too complex to work with in Box2D
* Re-do the physics world inside Game.cc
* Create functionality to check when an object is still still/not moving.
* Still need to:
    * [ ] ~~Create more types of pieces with simple polygon layout (square, rectangle, triangle)~~ 
    * [x] Finish logic for game
    * [x] Use openGL to visualize the items within the Box2D world
* Visualized boxes falling in game with openGL
* Still need to:
    * [x] Add object rotation / transformation with keypress
    
### 4/27/20
* Change tetrominos back to the original shapes (I figured it out!)
* Implement Draw() functions for tetrominos
* Allow object to rotate and move left/right freely while falling through keypress
* Added colors to each tetromino and make densities of each one equal
* Fix scalars for the physics world to cinder openGL screen
* Still need to:
    * [ ] Add scoring logic (timer)
    * [ ] Add text to UI / make it prettier
    * [ ] Cap physics box to prevent pieces from flying out
    * [ ] Unit testing
* Extra ideas:
    * Pause feature/menu?
    * Maybe add a background?
    