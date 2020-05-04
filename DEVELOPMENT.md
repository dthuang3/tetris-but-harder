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
    * [x] Add scoring logic (timer)
    * [x] Add text to UI / make it prettier
    * [x] Cap physics box to prevent pieces from flying out
    * [x] Unit testing
* Extra ideas:
    * Pause feature/menu?
    * Maybe add a background?
    
### 4/28/2020
* Adjusted piece movement to be less rapid / easier to control (less torque, decreased acceleration)
* Reset game on mouse click
* Added scoring and displayed onto side bar
* Added hold piece feature and displayed on side bar
* Changed background color (may go back to black)
* Still need to:
    * [x] Unit testing
    * [x] Display next piece 
    * [x] Clean up magic numbers / use consts
    * [ ] Documentation / README.md
    * [ ] Game Over Screen to see score.
* Extra ideas (continued):
    * Pause feature/menu
    
### 4/29/20
* Display the next piece on side bar
* Replaced the "type" parameter for each tetromino with the TetrominoPieceType enum instead of using chars
* Added unit tests for Game class
* ~~Decided against having clear line function because it is hard to get infinite precision in Box2D to measure a cleared
line and even harder for user to even make a row~~
* Created a new game on mouse click rather than resetting game, logically, because it is "new" game and fixes the memory leak error due to no delete at end of game
* Added PROPOSAL.md
* Still need to:
    *[x] Clean up magic numbers / use consts / fix spacing and comments
    *[ ] Documentation / README.md
    *[ ] ~~Game Over Screen to see score~~
* Extra ideas (continued):
    * [x] Pause feature (menu if time)
        *~~menu will have resume, new game, quit~~
        
### 5/2/20
* Feature to clear lines when the row is matched end to end (10 blocks/squares/fixtures)
* Separate the tetrominos into 4 squares instead of 2 rectangles to allow them to be deleted properly when clearing lines
* Still need to: 
    *[x] Clean up magic numbers / use consts / fix spacing and comments
    *[x] Improve modularity / function usage
    *[ ] Documentation / README.md
    *[x] Pause ability (not necessarily a visible menu)
    
### 5/3/2020
* Allow player to pause/play game
* Used consts and broke long functions into smaller functions to improve readability
* Fix line spacing and deleted unnecessary lines 
* Still need to:
    * [ ] Documentation / README.md
    * [ ] Update PROPOSAL.md
    * [ ] Game end screen
