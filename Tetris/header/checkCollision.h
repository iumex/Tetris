#ifndef CHECKCOLLISION_H
#define CHECKCOLLISION_H

#include "tetromino.h"
#include "stage.h"

// Function to check if a tetromino collides with the left, right and bottom sides of our stage
int CheckCollision(const int currentTetrominoX, const int currentTetrominoY, const int* tetromino);

#endif //CHECKCOLLISION_H