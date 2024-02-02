#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>
#include "Utils.h"

using namespace std;

class Snake
{
private:
    COORD snakePosition;                // position of snake in the level
    vector<COORD> body;

    int snakeVelocity;                  // snake velocity
    COORD snakeDirection;                // direction of the snake
    int snakeLength;                   // length of the snake

public:
    Snake(COORD initialPosition, int initialVelocity);

    void Grow();                                          // increase the snake length
    void MoveSnake();                                    // to move the snake
    void Direction(COORD changedDirection);          // changes the snakes direction

    bool WallCollision();                                    // checks collision with the walls
    bool FoodEaten(COORD food);

    const vector<COORD>* GetSnakeBody() const;                         // returns the new snake body
    const COORD* GetSnakePosition() const;                                    // returns the snake position

    void reset();                                           // generates a random position for the snake
};

#endif // SNAKE_H