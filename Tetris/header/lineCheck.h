#ifndef LINECHECK_H
#define LINECHECK_H

#include "tetris.h"
#include "stage.h"

#include "raylib.h"

// Function to let a line to fall down when the line below is erased
void ResetLines(int startLineY);

// Function to delete a line when it gets full
void DeleteLines(float* timer, float* startTimer, int* lines, int* increaseSpeedCounter);

#endif //LINECHECK_H