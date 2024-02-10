#include "tetris.h"

extern int stage[];

extern int lineCounter;
extern int increaseSpeedCounter;
extern int lines;
extern int score;

extern float checkLineTimer;
extern float checkLineStart;

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

// Function to delete a line when it gets full
void DeleteLines()
{
    for(int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        int checkLine = 1;

        for(int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;

            if(stage[offset] == 0)
            {
                checkLine = 0;
                break;
            }
        }

        // If a line on the stage is full, at first it becomes white and, when the timer runs out, it disappears and then the line above falls down         
        if(checkLine)
        {
            const int offset = y * STAGE_WIDTH + 1;

            for(int x = 0; x < STAGE_WIDTH - 2; x++)
            {
                stage[x + offset] = 1;
            }

            checkLineTimer -= GetFrameTime();

            if(checkLineTimer <= 0)
            {
                const int offset = y * STAGE_WIDTH + 1;

                for(int x = 0; x < STAGE_WIDTH - 2; x++)
                {                
                    stage[x + offset] = 0;                              
                }

                checkLineTimer = checkLineStart;

                Sound clear = LoadSound("sounds/clear.wav");

                PlaySound(clear);

                IncreaseLinesAndSpeed();

                ResetLines(y);
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
