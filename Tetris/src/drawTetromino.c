#include "drawTetromino.h"



void DrawTetromino(const int offsetStartX, const int offsetStartY, int currentTetrominoX, int currentTetrominoY, const int* tetromino, const Color color)
{
    for(int y = 0; y < TETROMINO_SIZE; y++)
    {
        for(int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offsetIndex = y * TETROMINO_SIZE + x;

            if(tetromino[offsetIndex] == 1)
            {
                DrawRectangle((x + currentTetrominoX) * TILE_SIZE + offsetStartX, (y + currentTetrominoY) * TILE_SIZE + offsetStartY, TILE_SIZE, TILE_SIZE, color);
            }
        }
    }
}