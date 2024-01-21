#include "tetris.h"

extern int stage[];

extern int lineCounter;
extern int increaseSpeedCounter;
extern int lines;
extern int score;

// Function to let a line to fall down when the line below is erased
void ResetLines(int startLineY)
{
    for(int y = startLineY; y > 0; y--)
    {
        for(int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int offsetBelow = (y + 1) * STAGE_WIDTH + x;

            if(stage[offsetBelow] == 0)
            {
                stage[offsetBelow] = stage[offset];
                stage[offset] = 0;
            }
        }
    }
}


// Function to increase the number of completed lines and speed of the falling tetrominos
void IncreaseLinesAndSpeed()
{
    lines++;    
    lineCounter++;
    if((lineCounter%2) == 0)
    {
        increaseSpeedCounter++;
    }   
}



// Function to Delete a line when completed
void DeleteLines()
{

    for(int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        int checkline = 1;

        for(int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;

            if(stage[offset] == 0)
            {
                checkline = 0;
                break;
            }
        }

        if(checkline)
        {
            const int offset = y * STAGE_WIDTH + 1;

            memset(stage + offset, 0, (STAGE_WIDTH - 2) * (sizeof(int)));

            Sound clear = LoadSound("sounds/clear.wav");

            PlaySound(clear);

            IncreaseLinesAndSpeed();

            ResetLines(y);
        }
    }
}

// Function to close the game if the stage is filled up to the top
int StopGame()
{
    for(int x = 1; x < STAGE_WIDTH - 1; x++)
    {
        if(stage[x] != 0)
        {
            return 1;
        }
    }

    return 0;
}
