# Wordle Game - README

## Introduction
Welcome to the Wordle Game. This is a terminal-based word guessing game inspired by the popular Wordle game. The objective is to guess a randomly selected word within six attempts. The game provides feedback for each guess to help you get closer to the correct answer.

## Rules of the Game
1. At the start of the game the player has to selects a word of the specified length (5, 6, 7, or 8 letters).
2. Each word has unique letters (no repetitions).
3. You have six attempts to guess the word.
4. Feedback is provided for each guess:
   - **Green**: The letter is in the correct position.
   - **Yellow**: The letter is in the word but in the wrong position.
   - **Red**: The letter is not in the word at all.
5. Guesses must consist only of lowercase alphabetic characters. Invalid inputs will prompt you to enter the guess again.

## How to Play
### Prerequisites
- Ensure you have a C compiler installed (e.g., GCC).
- Make sure text files (`5.txt`, `6.txt`, `7.txt`, `8.txt`) containing words of the respective lengths are present in the same directory as the executable. Each file should have one word per line.

### Compilation and Execution
1. Compile the program using a C compiler:
   ```bash
   gcc -o wordle_game wordle_game.c
   ```
2. Run the executable:
   ```bash
   ./wordle_game
   ```

## File Requirements
- `5.txt`, `6.txt`, `7.txt`, and `8.txt` files should each contain words of their respective lengths.
- Each file must have one word per line.
- Ensure the words do not contain spaces, special characters, or uppercase letters.

Enjoy the game!

