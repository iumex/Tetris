#ifndef STAGE_H
#define STAGE_H

#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 16

// Function to get the value of a cell of the stage at a specific index
int GetStage(int stageIndex);

// Function to set the value of a cell of the stage at a specific index
void SetStage(int stageIndex, int value);

#endif //STAGE_H