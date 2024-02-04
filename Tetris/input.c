#include "tetris.h"

extern int stage[];
extern int* tetrominoType[7][4];
extern int score;


void Input(int* currentTetrominoX, int* currentTetrominoY, int* currentTetrominoType, int* currentTetrominoRotation, float* tetrominoFallingTimer, 
            float tetrominoFallingStart, int tetrominoStartX, int tetrominoStartY, int* currentTetrominoColor)
{           
    
    // Changing tetromino rotation
    if(IsKeyPressed(KEY_SPACE))
    {
        int lastTetrominoRotation = *currentTetrominoRotation;
        (*currentTetrominoRotation)++;
        if((*currentTetrominoRotation) > 3)
        {
            *currentTetrominoRotation = 0;
        }

        if(CheckCollision(*currentTetrominoX, *currentTetrominoY, tetrominoType[*currentTetrominoType][*currentTetrominoRotation]))
        {
            *currentTetrominoRotation = lastTetrominoRotation;
        }
    }
    // Moving to the left. The stage wall protects us from overflow
    if(IsKeyPressed(KEY_LEFT))
    {
        if(!CheckCollision(*currentTetrominoX - 1, *currentTetrominoY, tetrominoType[*currentTetrominoType][*currentTetrominoRotation]))
        {
            (*currentTetrominoX)--;
        }
    }
    // Moving to the right. The stage wall protects us from overflow
    if(IsKeyPressed(KEY_RIGHT))
    {
        if(!CheckCollision(*currentTetrominoX + 1, *currentTetrominoY, tetrominoType[*currentTetrominoType][*currentTetrominoRotation]))
        {
            (*currentTetrominoX)++;
        }
    }

     // Tetromino falling when the timer decreases to 0, or when the key down is pressed
        if(*tetrominoFallingTimer <= 0 || IsKeyPressed(KEY_DOWN))
        {

            if(!CheckCollision(*currentTetrominoX, *currentTetrominoY + 1, tetrominoType[*currentTetrominoType][*currentTetrominoRotation]))
            {
                // When the tetromino doesn't collide with the stage below, it can keep up to fall
                (*currentTetrominoY)++;
                *tetrominoFallingTimer = tetrominoFallingStart;
            }
            else
            {
                // In case of collision, the score increases and the tetromino becomes part of the stage, mantaining its own color
                score += 10;

                for(int y = 0; y < TETROMINO_SIZE; y++)
                {
                    for(int x = 0; x < TETROMINO_SIZE; x++)
                    {
                        const int offset = y * TETROMINO_SIZE + x;

                        const int* tetromino = tetrominoType[*currentTetrominoType][*currentTetrominoRotation];

                        if(tetromino[offset] == 1)
                        {
                            const int stageOffset = (y + *currentTetrominoY) * STAGE_WIDTH + (x + *currentTetrominoX);

                            stage[stageOffset] = *currentTetrominoColor + 1;                           
                        }
                    }
                }

                // The line is erased and all the line above takes its place
                DeleteLines();

                // A new tetromino spawns
                *currentTetrominoX = tetrominoStartX;
                *currentTetrominoY = tetrominoStartY;
                *currentTetrominoType = GetRandomValue(0, 6);
                *currentTetrominoRotation = 0;
                *currentTetrominoColor = GetRandomValue(1, 8);

            }
            
        }
}