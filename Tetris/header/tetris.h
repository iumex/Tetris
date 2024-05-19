#ifndef TETRIS_H
#define TETRIS_H

#include "stage.h"
#include "checkCollision.h"
#include "tetromino.h"
#include "raylib.h"

// Function to add 10 points each time a tetromino reaches the current bottom of the stage
void IncreaseScore(int* score);

// Function to increase the number of completed lines and speed of the falling tetrominos
void IncreaseLinesAndSpeed(int* lines, int* increaseSpeedCounter);

// Inputs of our game with increase of the score
void Input(int* currentTetrominoX, int* currentTetrominoY, int* currentTetrominoType, int* currentTetrominoRotation, float* tetrominoFallingTimer,
            float tetrominoFallingStart, int tetrominoStartX, int tetrominoStartY, int* currentTetrominoColor, int* score);


// Function to close the game if the stage is filled up to the top
int StopGame();

#endif // TETRIS_H
