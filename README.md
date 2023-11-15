# C++ Word-Search Puzzle Game - README

Overview
This Word Search Puzzle Game allows players to search for a hidden word in a dynamically generated puzzle. The player can choose the difficulty level and input the word they want to find. The game generates a grid filled with random letters, with the chosen word hidden in it.

How to Play
Start the Game: Run the game executable ./test.
Input the Word: Enter a lowercase word that you want to search for in the puzzle. The word should be between 3 to 10 letters long.
Select Difficulty: Choose your difficulty level from "easy", "medium", or "hard". This affects the size of the puzzle grid.
Solve the Puzzle: The game displays a puzzle grid with coordinates. Your task is to find the hidden word in the grid.
Locating the Word: Once you spot the word, enter the starting row and column location, and specify the direction of the word ("n", "e", "s", or "w" for north, east, south, or west, respectively).
Winning the Game: If you correctly identify the location and direction of the word, the game congratulates you. The game also displays the time taken to solve the puzzle.
Code Structure
BadJumbleException: A custom exception class for handling invalid inputs.
JumblePuzzle: The main class responsible for generating the puzzle grid, hiding the word, and providing accessors for game details.
Random Character Generation: The game uses a random number generator to fill the grid with letters, ensuring a unique puzzle every time.
Word Placement: The game intelligently places the chosen word in the grid in a random location and direction.

Requirements
C++ compiler
Standard C++ libraries

Notes
The game is designed to be simple and intuitive.
The puzzle's difficulty affects the size of the grid, making the game suitable for various skill levels.
The game measures the time taken to find the word, adding a challenge for players who wish to improve their speed.
Enjoy finding hidden words in this engaging and challenging Word Search Puzzle Game!





