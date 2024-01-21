#include "tetris.h"

extern int stage[];

// Function to check if a tetromino collides with the left, right and bottom sides of our stage
int CheckCollision(const int currentTetrominoX, const int currentTetrominoY, const int* tetromino)
{
    for(int y = 0; y < TETROMINO_SIZE; y++)
    {
        for(int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if(tetromino[offset] == 1)
            {
                const int stageOffset = (y + currentTetrominoY) * STAGE_WIDTH + (x + currentTetrominoX);

                if(stage[stageOffset] != 0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}