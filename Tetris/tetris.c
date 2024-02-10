#include "tetris.h"


// Our global variables
int lineCounter = 0;
int increaseSpeedCounter = 1;
int lines = 0;
int score = 0;
int line = 0;

// Timer for the tilt of the line if it gets full
float checkLineTimer = 0.3;
float checkLineStart = 0.3;

// This is our stage
int stage[] = 
{
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};


// These are our Tetrominos
const int lTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,
};

const int lTetromino90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    1, 0, 0, 0,
    0, 0, 0, 0,
};

const int lTetromino180[] = 
{
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int lTetromino270[] = 
{
    0, 0, 1, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};



const int jTetromino0[] = 
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0
};

const int jTetromino90[] = 
{
    1, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int jTetromino180[] = 
{
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int jTetromino270[] = 
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 0, 1, 0,
    0, 0, 0, 0
};

const int oTetromino0[] =
{
    1, 1, 0, 0,
    1, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int sTetromino0[] =
{
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0,
    0, 0, 0, 0
};

const int sTetromino90[] =
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 1, 0
};

const int sTetromino180[] =
{
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 1, 1, 0,
    1, 1, 0, 0
};

const int sTetromino270[] =
{
    0, 0, 0, 0,
    1, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0
};

const int zTetromino0[] =
{
    0, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 1, 0,
    0, 0, 0, 0
};

const int zTetromino90[] =
{
    0, 0, 0, 0,
    0, 0, 1, 0,
    0, 1, 1, 0,
    0, 1, 0, 0
};

const int zTetromino180[] =
{
    0, 0, 0, 0,
    0, 0, 0, 0,
    1, 1, 0, 0,
    0, 1, 1, 0
};

const int zTetromino270[] =
{
    0, 0, 0, 0,
    0, 1, 0, 0,
    1, 1, 0, 0,
    1, 0, 0, 0
};

const int tTetromino0[] =
{
    0, 0, 0, 0,
    1, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int tTetromino90[] =
{
    0, 1, 0, 0,
    1, 1, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int tTetromino180[] =
{
    0, 1, 0, 0,
    1, 1, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int tTetromino270[] =
{
    0, 1, 0, 0,
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 0
};

const int iTetromino0[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0
};

const int iTetromino90[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const int iTetromino180[] =
{
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0,
    0, 1, 0, 0
};

const int iTetromino270[] =
{
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0
};


// Bidimensional array containing all the types of tetrominos and their rotations
const int* tetrominoType[7][4] = 
{
    {zTetromino0, zTetromino90, zTetromino180, zTetromino270},
    {sTetromino0, sTetromino90, sTetromino180, sTetromino270},
    {tTetromino0, tTetromino90, tTetromino180, tTetromino270},
    {oTetromino0, oTetromino0, oTetromino0, oTetromino0},
    {iTetromino0, iTetromino90, iTetromino180, iTetromino270},
    {jTetromino0, jTetromino90, jTetromino180, jTetromino270},
    {lTetromino0, lTetromino90, lTetromino180, lTetromino270}
};

// Array of our colors
const Color colorTypes[] =
{
    {255, 255, 255, 255},    
    {255, 255, 85, 255},
    {85, 43, 158, 255},
    {56, 191, 85, 255},
    {101, 255, 56, 255},
    {23, 72, 137, 255},
    {98, 158, 79, 255},
    {201, 98, 151, 255},
    {78, 25, 253, 255},
};




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

    // Current type, rotation and color of the falling tetromino
    int currentTetrominoType = GetRandomValue(0, 6);
    int currentTetrominoRotation = 0;    
    int currentTetrominoColor = GetRandomValue(1, 8);

    // Initialization of our window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetris");

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
        
        // Timer decreasing by the delta time multiplied by the speed increasing when a line is completed
        tetrominoFallingTimer -= GetFrameTime() * increaseSpeedCounter;

        // If a line on the stage is full, at first it becomes white and, when the timer runs out, it disappears and then the line above falls takes its place 
        DeleteLines();

        
        Input(&currentTetrominoX, &currentTetrominoY, &currentTetrominoType, &currentTetrominoRotation, &tetrominoFallingTimer,
                tetrominoFallingStart, tetrominoStartX, tetrominoStartY,&currentTetrominoColor);
       

        BeginDrawing();

        ClearBackground(BLACK);

        // Drawing the texts of the score and the erased lines
        DrawText(TextFormat("Score: %i", score), 30, 20, 20, WHITE);
        DrawText(TextFormat("Lines: %i", lines), 250, 20, 20, WHITE);

        // Drawing our stage
        DrawStage(offsetStartX, offsetStartY);

        // Drawing the falling tetromino
        DrawTetromino(offsetStartX, offsetStartY, currentTetrominoX, currentTetrominoY, tetrominoType[currentTetrominoType][currentTetrominoRotation], colorTypes[currentTetrominoColor]);

        EndDrawing();
    }

    return 0;
}

