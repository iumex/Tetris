#include "raylib.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

// Our constants
#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 512
#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 16
#define TETROMINO_SIZE 4


// File drawing.c
void DrawStage(const int offsetStartX, const int offsetStartY);

void DrawTetromino(const int offsetStartX, const int offsetStartY, int currentTetrominoX, int currentTetrominoY, const int* tetromino, const Color color);

// File checkCollision.c
int CheckCollision(const int currentTetrominoX, const int currentTetrominoY, const int* tetromino);

// File input.c
void Input(int* currentTetrominoX, int* currentTetrominoY, int* currentTetrominoType, int* currentTetrominoRotation, float* tetrominoFallingTimer, 
            float tetrominoFallingStart, int tetrominoStartX, int tetrominoStartY, int* currentTetrominoColor);

// File lineCheck.c
void ResetLines(int startLineY);

void IncreaseLinesAndSpeed();

void DeleteLines();

int StopGame();
