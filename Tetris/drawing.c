#include "tetris.h"


extern int stage[];
extern Color colorTypes[];


// Function to Draw the Tetromino
void DrawStage(const int offsetStartX, const int offsetStartY)
{
    for(int y = 0; y < STAGE_HEIGHT; y++)
    {
        for(int x = 0; x < STAGE_WIDTH; x++)
        {
            const int offsetIndex = y * STAGE_WIDTH + x;

            const int color = stage[offsetIndex];

            if(stage[offsetIndex] != 0)
            {
                DrawRectangle(x * TILE_SIZE + offsetStartX, y * TILE_SIZE + offsetStartY, TILE_SIZE, TILE_SIZE, colorTypes[color - 1]);
            }

            DrawRectangleLines(x * TILE_SIZE + offsetStartX, y * TILE_SIZE + offsetStartY, TILE_SIZE, TILE_SIZE, WHITE);
        }
    }

}

// Function to Draw the Tetromino
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