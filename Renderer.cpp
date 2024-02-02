#include <array>
#include "Renderer.h"
#include <string>

void Renderer::render(const Snake& snake, const Food& food, int score)
{
    const COORD* snake_pos = snake.GetSnakePosition();
    const COORD* food_pos = food.GetPosition();
    const vector<COORD>* snake_body = snake.GetSnakeBody();

    array<array<string, SCREEN_WIDTH>, SCREEN_HEIGHT> board;

    // Initialize the game board with empty spaces and walls
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            if (i == 0 || i == SCREEN_HEIGHT - 1 || j == 0 || j == SCREEN_WIDTH - 1) {
                board[i][j] = WALL;
            }
            else {
                board[i][j] = EMPTY;
            }
        }
    }

    // Place snake body
    for (const auto& body_part : *snake_body)
    {
        board[body_part.Y][body_part.X] = SNAKE_BODY;
    }

    // Place snake head
    board[snake_pos->Y][snake_pos->X] = SNAKE_HEAD;

    // Place food
    board[food_pos->Y][food_pos->X] = FRUIT;

    // Render the game board
    string buffer;
    buffer.reserve((SCREEN_WIDTH + 1) * SCREEN_HEIGHT);
    buffer += "SCORE : " + to_string(score) + "\n\n";

    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        if (i != 0) {
            buffer += "\n";
        }

        if (i == 0 || i == SCREEN_HEIGHT - 1) {
            buffer += string(SCREEN_WIDTH * 2, '#');
        }

        else
        {
            for (int j = 0; j < SCREEN_WIDTH; j++) {
                buffer += board[i][j];
            }
        }
    }

    cout << buffer;
}