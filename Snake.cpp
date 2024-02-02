#include "Snake.h"
#include "CoordExtensions.h"

Snake::Snake(COORD initialPosition, int initialVelocity)
{
    this->snakePosition = initialPosition;
    this->snakeVelocity = initialVelocity;

    snakeDirection = ZERO;
    snakeLength = 1;                                            // initial Snake Length

    body.push_back(initialPosition);                            // using a list to make the snake grow in size
}

void Snake::Direction(COORD changedDirection)                // changes the snakes direction
{

    if (snakeDirection == (changedDirection * INVERTED_COORD))
    {
        return;
    }

    snakeDirection = changedDirection;
}

void Snake::Grow()                                          // increases the snake length
{
    snakeLength++;
}

const COORD* Snake::GetSnakePosition() const                                      // returns the updated position
{
    return &snakePosition;
}

const vector<COORD>* Snake::GetSnakeBody() const                                 // returns the updated snake body
{
    return &body;
}

void Snake::MoveSnake()                                // move the snake up and down
{
    snakePosition += snakeDirection;
    body.push_back(snakePosition);
    if (body.size() > snakeLength) body.erase(body.begin());            // removes the first snake element from list
}

bool Snake::WallCollision()
{
    if (snakePosition.Y < 1 || snakePosition.Y > SCREEN_HEIGHT - 2)        // if the snake touches the bounds
    {
        return true;
    }

    if (snakePosition.X > SCREEN_WIDTH - 2)          // if the snake collides with the side walls then spawn from the opposite wall
    {
        snakePosition.X = 0;
        return false;
    }
    if (snakePosition.X < 1)                            // if the snake collides with the side walls then spawn from the opposite wall
    {
        snakePosition.X = SCREEN_WIDTH - 2;
        return false;
    }

    for (int i = 0; i < snakeLength - 1; i++)
    {
        if (snakePosition.X == body[i].X && snakePosition.Y == body[i].Y)                       // if the snake collides with its own body part
        {
            return true;
        }
    }
    return false;
}

bool Snake::FoodEaten(COORD food)
{
    if (snakePosition.X == food.X && snakePosition.Y == food.Y)             // if the snake position is same as the food position
    {
        return true;
    }
    return false;
}

void Snake::reset()
{
    // Generate a random position for the snake
    COORD new_pos = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT };

    // Create a new Snake object with the random position and initial length of 1
    Snake new_snake(new_pos, 1);

    // Copy the new snake's state (position, direction, body) to this snake object
    snakePosition = new_snake.snakePosition;
    snakeDirection = ZERO;
    snakeLength = new_snake.snakeLength;
    body = new_snake.body;
}