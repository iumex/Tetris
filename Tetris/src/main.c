#include "tetris.h"
#include "tetromino.h"
#include "drawTetromino.h"
#include "color.h"
#include "stage.h"
#include "drawStage.h"
#include "lineCheck.h"

#include "raylib.h"
#include <time.h>
#include <string.h>
#include <stdio.h>


#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 512
#define WINDOW_TITLE "Tetris"


int main(int argc, char** argv)
{
    // Offset we start to draw our stage from
    const int offsetStartX = (WINDOW_WIDTH / 2) - (STAGE_WIDTH / 2) * TILE_SIZE;
    const int offsetStartY = (WINDOW_HEIGHT / 2) - (STAGE_HEIGHT / 2) * TILE_SIZE;

    // Start position of the spawning tetromino
    const int tetrominoStartX = STAGE_WIDTH / 2;
    const int tetrominoStartY = 0;

    // Current position of the tetromino along our stage
    int currentTetrominoX = tetrominoStartX;
    int currentTetrominoY = tetrominoStartY;

    // Creation of the seed to manage random values
    time_t unixTime;
    time(&unixTime);
    SetRandomSeed(unixTime);

    // Timer variables
    float tetrominoFallingTimer = 1;
    const float tetrominoFallingStart = 1;

    // Timer for the falling complete line
    float checkLineTimer = 0.3;
    float checkLineStart = 0.3;

    // multiplier of the Tetromino's falling speed
    int increaseSpeedCounter = 1;

    // Counter of completed lines
    int lines = 0;

    // Current type, rotation and color of the falling tetromino
    int currentTetrominoType = GetRandomValue(0, 6);
    int currentTetrominoRotation = 0;    
    int currentTetrominoColor = GetRandomValue(1, 8);

    // Current score
    int score = 0;

    // Initialization of our window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    // Initialization of the audio device
    InitAudioDevice();

    // Loading the soundtrack
    Music music = LoadMusicStream("sounds/Tetris.mp3");


    // Setting the frame rate
    SetTargetFPS(60);

    while(!WindowShouldClose() && !StopGame())
    {
        UpdateMusicStream(music);

        PlayMusicStream(music);

        SetMusicVolume(music, 0.25);
        
        // Timer decreasing by the delta time multiplied by the speed increasing when a line is completed
        //tetrominoFallingTimer -= GetFrameTime() * increaseSpeedCounter;
        tetrominoFallingTimer -= GetFrameTime() * increaseSpeedCounter;
      

        DeleteLines(&checkLineTimer, &checkLineStart, &lines, &increaseSpeedCounter);
        
        Input(&currentTetrominoX, &currentTetrominoY, &currentTetrominoType, &currentTetrominoRotation, &tetrominoFallingTimer,
                tetrominoFallingStart, tetrominoStartX, tetrominoStartY, &currentTetrominoColor, &score);
       

        BeginDrawing();

        ClearBackground(BLACK);

        // Drawing the texts of the score and the erased lines               
        DrawText(TextFormat("Score: %i", score), 30, 20, 20, WHITE);
        DrawText(TextFormat("Lines: %i", lines), 250, 20, 20, WHITE);

        // Drawing our stage
        DrawStage(offsetStartX, offsetStartY);

        // Drawing the falling tetromino
        DrawTetromino(offsetStartX, offsetStartY, currentTetrominoX, currentTetrominoY, GetTetromino(currentTetrominoType,currentTetrominoRotation), GetColorType(currentTetrominoColor));

        EndDrawing();
    }

    return 0;
}