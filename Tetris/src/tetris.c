#include "tetris.h"



void IncreaseScore(int* score)
{
    *score += 10;    
}

void IncreaseLinesAndSpeed(int* lines, int* increaseSpeedCounter)
{
    *lines += 1;       
    if((*lines%2) == 0)
    {
        *increaseSpeedCounter += 1;
    }   
}


void Input(int* currentTetrominoX, int* currentTetrominoY, int* currentTetrominoType, int* currentTetrominoRotation, float* tetrominoFallingTimer, 
            float tetrominoFallingStart, int tetrominoStartX, int tetrominoStartY, int* currentTetrominoColor, int* score)
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

        if(CheckCollision(*currentTetrominoX, *currentTetrominoY, GetTetromino(*currentTetrominoType,*currentTetrominoRotation)))
        {
            *currentTetrominoRotation = lastTetrominoRotation;
        }
    }
    // Moving to the left. The stage wall protects us from overflow
    if(IsKeyPressed(KEY_LEFT))
    {
        if(!CheckCollision(*currentTetrominoX - 1, *currentTetrominoY, GetTetromino(*currentTetrominoType,*currentTetrominoRotation)))
        {
            (*currentTetrominoX)--;
        }
    }
    // Moving to the right. The stage wall protects us from overflow
    if(IsKeyPressed(KEY_RIGHT))
    {
        if(!CheckCollision(*currentTetrominoX + 1, *currentTetrominoY, GetTetromino(*currentTetrominoType,*currentTetrominoRotation)))
        {
            (*currentTetrominoX)++;
        }
    }

     // Tetromino falling when the timer decreases to 0, or when the key down is pressed
        if(*tetrominoFallingTimer <= 0 || IsKeyPressed(KEY_DOWN))
        {

            if(!CheckCollision(*currentTetrominoX, *currentTetrominoY + 1, GetTetromino(*currentTetrominoType,*currentTetrominoRotation)))
            {
                // When the tetromino doesn't collide with the stage below, it can keep up to fall
                (*currentTetrominoY)++;
                *tetrominoFallingTimer = tetrominoFallingStart;
            }
            else
            {
                // In case of collision, the score increases and the tetromino becomes part of the stage, mantaining its own color
                //score += 10;
                IncreaseScore(score);

                for(int y = 0; y < TETROMINO_SIZE; y++)
                {
                    for(int x = 0; x < TETROMINO_SIZE; x++)
                    {
                        const int offset = y * TETROMINO_SIZE + x;

                        const int* tetromino = GetTetromino(*currentTetrominoType,*currentTetrominoRotation);

                        if(tetromino[offset] == 1)
                        {
                            const int stageOffset = (y + *currentTetrominoY) * STAGE_WIDTH + (x + *currentTetrominoX); 
                            SetStage(stageOffset, *currentTetrominoColor + 1);                        
                        }
                    }
                }

              
                // A new tetromino spawns
                *currentTetrominoX = tetrominoStartX;
                *currentTetrominoY = tetrominoStartY;
                *currentTetrominoType = GetRandomValue(0, 6);
                *currentTetrominoRotation = 0;
                *currentTetrominoColor = GetRandomValue(1, 8);

            }
            
        }
}


int StopGame()
{
    for(int x = 1; x < STAGE_WIDTH - 1; x++)
    {
        if(GetStage(x) != 0)
        {
            return 1;
        }
    }

    return 0;
}



