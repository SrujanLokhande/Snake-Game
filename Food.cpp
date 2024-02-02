#include "Food.h"

void Food::GenerateFood()                                       // generates the food at a random location
{
    foodPosition.X = (rand() % SCREEN_WIDTH - 2) + 1;
    foodPosition.Y = (rand() % SCREEN_HEIGHT - 2) + 1;
}

const COORD* Food::GetPosition() const               // returns the generated food location
{
    return &foodPosition;
}