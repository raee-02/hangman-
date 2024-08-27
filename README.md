# Hangman Game with SFML

## Overview

This project is a simple Hangman game implemented in C++ using the [SFML](https://www.sfml-dev.org/) library for graphics. The game supports two players taking turns to guess a word, with visual representation of the hangman state on the screen.

## Features

- **Graphical Interface**: The game uses SFML to render the hangman graphics and game text.
- **Two Players**: Supports two players taking turns guessing the word.
- **Score Tracking**: Keeps track of each player's score across multiple rounds.
- **Game Over Conditions**: Displays messages when the game is won or lost.

## Requirements

- C++11 or later
- SFML 2.5.1 or later
- CMake (for building the project)

## Setup and Build

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/hangman-game.git
   cd hangman-game

## Installation and Build Instructions

### Install SFML

Follow the instructions on the [SFML website](https://www.sfml-dev.org/) to install SFML on your system.

### Build the Project

1. **Create a build directory and navigate into it:**

    ```bash
    mkdir build
    cd build
    ```

2. **Generate the build files using CMake:**

    ```bash
    cmake ..
    ```

3. **Build the project:**

    ```bash
    cmake --build .
    ```

4. **Run the game:**

    ```bash
    ./HangmanGame
    ```


## Usage

### Start the Game

- The game window will open, and Player 1 will be prompted to enter a word.
- Player 2 will then guess letters to try to figure out the word.

### Game Play

- Player 2 types guesses into the keyboard. The game will display the state of the hangman and update the guessed word as well as the number of incorrect guesses.
- Players take turns guessing until the word is guessed or the hangman is fully drawn.

### Scoring

- The player who guesses the word correctly wins the round and earns a point.
- Scores are displayed after each round.

### Game Over

- The game will display a message indicating whether Player 2 won or lost the round.
- The game continues to the next round until the window is closed.

## Files

- `main.cpp`: Entry point of the application.
- `HangmanDrawer.cpp` and `HangmanDrawer.hpp`: Handles the drawing of the hangman and game text.
- `HangmanGame.cpp` and `HangmanGame.hpp`: Contains the main game logic and player management.
- `Player.cpp` and `Player.hpp`: Defines the player class and score tracking.

## Contributing

Feel free to submit issues or pull requests if you have suggestions or improvements for the project.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Special thanks to the [SFML](https://www.sfml-dev.org/) team for their wonderful graphics library.
- Font used in the project: Arial (Make sure to include `arial.ttf` in the project directory).

