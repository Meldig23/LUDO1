# LUDO

We have created a simple implementation of the popular board game Ludo, using SDL in C programming language(in Visual Studio). This project aims to provide a basic Ludo game experience with multiplayer functionality.

## Team Members

The team consisted of me Karan Pattanaik, Sumeet Sahoo, Atharva Tol, Prajwal P Arakeri, N Jay Roshan Devankar(all students of Btech Batch 22 at IIT Bhubaneswar )

## Features

- Supports 4 players only.
- Each player has 4 tokens.
- Roll the dice to determine the token movement.
- Tokens move based on the dice roll result.
- Tokens can knock out opponent tokens if they land on the same spot.
- Win the game by moving all your tokens to the home area.

## Controls

- Each player takes turns in a clockwise order starting from red.
- Click the dice to roll the dice. (Left Mouse Button)
- Click the token to move the token after diceroll. (Left Mouse Button)

## Graphics library

- We were able to find out various graphics libraries of C,but many of them did not work so we finally used SDL graphics for our project.
- We downloaded SDL from its official website [SDL Realeses](https://github.com/libsdl-org/SDL/releases/tag/release-2.26.5) and took  help from this youtube video [Creating a Game Loop with C & SDL (Tutorial)](https://youtu.be/XfZ6WrV5Z7Y) to download it and set it up in Visula Studio.
We used SDL_ttf for fonts in text which we added in the very end. We downloaded it from [SDL_ttf Realeases](https://github.com/libsdl-org/SDL_ttf/releases) and followed a similar process to set it up.

## Development History
The development of LUDO1 involved multiple commits, with each commit representing a specific change or feature added to the project. Here are some key milestones in the project's development:

Commit 1: We initialised the project setup, including setting up the game window and basic game loop.We made all the necessary lines and rectangles required for the Ludo board. Also there isn't a function in SDL to create circles so we thought of innovative ways to do it
Commit 2: We added player and token entities to the game.We first thought of adding them in the form of arrays but structures seemed more easy to handle so we used thm
Commit 3: We implemented dice rolling functionality. But didnt actually place the dice on the screen which you have to click. We made a version so that if you choose a token the dice rolls and then the token moves according to it. We used events in sdl to see the coordinates of the mouse click and compare them with tokens. 
Commit 4: We added token movement based on the dice roll result. Here we had to see how the dice moved in the board by implementing all the coordinates and the points where it changes direction and points where the player token goes inside. We were thinking of any other method to do that rather than just brute forcing all the coordinates but we couldn't think of any so we did it using if else if conditions.
Commit 5:We also defined playerturn and made it so that the player whose turn is the current turn can move only his token(for example if it is player 0(red's) turn then he can only move red tokens and cant touch tokens of other colours)
Commit 6: We added the display of dice and on clicking the dice the dice rolls. We were thinking of making the dice rotate but it didn't work. But we had multiple problems with it like a player can roll a dice multiple times also if he gets a 6 he gets a new turn so he can infinitely move the tokens throughout the board without rolling dice but only choosing the tokens etc.  We also added where the tokens move after going to their home squares.
Commit 7: We Added collision detection for tokens landing on the same spot.We thought of multiple different ways but finally we did it by checking for collising after every turn for all tokens except our current player.We found interesting new ways to use structure pointers. We found out that we can't change the values in a struct if we don't have a pointer to it(even in the main function). We also made another box to show whose turn it is at present. Also debugged code for dice by making it so that the dice doesn't roll if it has a number on it. Only rolls if it is initially zero. And we make the dicenumber 0 after a token has moved.
Commit 8: We added skipturn when all the tokens of a player were inside or in home squares and display the dice number he got for a short time. Also added safe squares where killing of tokens doesn't work
Commit 9: Implemented win condition for moving tokens to the home area. We displayed the colour which won and then exited the game.
Commit 10:  We were finnaly able to add texts. Added an intro text and outro winner text. We were thinking of adding music but alas we had no time.Made all the final changes, bug fixes and performance optimizations. Added necessary comments.

## Milestones

### Milestone 1: Basic Gameplay (Commit 2)
Achieved the rendering of the Ludo board 
Implemented basic player movement based on dice rolls

### Milestone 2: Token Movement and Collision Detection 
Implemented token movement within the game board (Commit 3)
Added collision detection to prevent token overlapping (Commit 7)

### Milestone 3: Game Logic and Winning Conditions 
Completed the game logic for turn-based gameplay (Commit 4 and 5)
Implemented winning conditions to determine the winner (Commit 9)

### Milestone 4: User Interface and Graphical Improvements (Commit 10)
Enhanced the user interface with text and graphics
Improved overall visual appeal of the game

## Acknowledgements

- This project utilizes the SDL and SDL_ttf libraries.
- Special thanks to the contributors of the SDL and SDL_ttf libraries for their work and support.
- Also thanks to Swayambhu Mohanty for suggesting that we use SDL for graphics

Finally this is our Submission Report and Demo Video
[Submission Report.pdf](https://github.com/Meldig23/LUDO1/files/11622097/Submission.Report.1.pdf)
[Demo Video](https://drive.google.com/file/d/1PqrLH6xIuhvdjtjOgihO33Dyga-IqdTd/view?usp=sharing)
