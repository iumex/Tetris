#include "lineCheck.h"


void ResetLines(int startLineY)
{
    for(int y = startLineY; y > 0; y--)
    {
        for(int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int offsetBelow = (y + 1) * STAGE_WIDTH + x;

            if(GetStage(offsetBelow) == 0)
            {
                SetStage(offsetBelow, GetStage(offset));
                SetStage(offset, 0);
            }
        }
    }
}


void DeleteLines(float* timer, float* startTimer, int* lines, int* increaseSpeedCounter)
{
    for(int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        int checkLine = 1;

        for(int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;

            if(GetStage(offset) == 0)
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
                SetStage(x + offset, 1);
            }

            *timer -= GetFrameTime();

            if(*timer <= 0)
            {
                const int offset = y * STAGE_WIDTH + 1;

                for(int x = 0; x < STAGE_WIDTH - 2; x++)
                {                             
                    SetStage(x + offset, 0);                              
                }

                *timer = *startTimer;

                Sound clear = LoadSound("sounds/clear.wav");

                PlaySound(clear);

                IncreaseLinesAndSpeed(lines, increaseSpeedCounter);

                ResetLines(y);
            }                       
                        
        }
    }
}




