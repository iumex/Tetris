#ifndef DRAWTETROMINO_H
#define DRAWTETROMINO_H

#include "raylib.h"
#include "tetromino.h"
#include "stage.h"

// Function to Draw the Tetromino
void DrawTetromino(const int offsetStartX, const int offsetStartY, int currentTetrominoX, int currentTetrominoY, const int* tetromino, const Color color);

#endif //DRAWTETROMINO_H