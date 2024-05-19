#include "color.h"

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


const Color GetColorType(const int colorIndex)
{
    return colorTypes[colorIndex];
}