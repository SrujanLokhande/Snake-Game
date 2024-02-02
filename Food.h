#pragma once
#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdio>
#include "Utils.h"

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 25

class Food
{
private:
    COORD foodPosition;                 // location of the food 

public:
    void GenerateFood();                    // generates food on random location

    const COORD* GetPosition() const;                    // returns the food position
};

#endif // FOOD_H
