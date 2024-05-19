#include "drawStage.h"


void DrawStage(const int offsetStartX, const int offsetStartY)
{
    for(int y = 0; y < STAGE_HEIGHT; y++)
    {
        for(int x = 0; x < STAGE_WIDTH; x++)
        {
            const int offsetIndex = y * STAGE_WIDTH + x;

            const int color = GetStage(offsetIndex);

            if(GetStage(offsetIndex) != 0)
            {
                DrawRectangle(x * TILE_SIZE + offsetStartX, y * TILE_SIZE + offsetStartY, TILE_SIZE, TILE_SIZE, GetColorType(color - 1));
            }

            DrawRectangleLines(x * TILE_SIZE + offsetStartX, y * TILE_SIZE + offsetStartY, TILE_SIZE, TILE_SIZE, WHITE);
        }
    }

}