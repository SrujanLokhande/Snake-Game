#include "Utils.h"
#include "Snake.h"
#include "Food.h"
#include "Renderer.h"
#include "SoundPlayer.h"


void update(Snake& snake, Food& food, bool& game_over, int& score);
void start_game();

Snake snake({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, 1);
Food food;

int score;

SoundPlayer collect_sound = SoundPlayer{ "EatApple.wav" };
SoundPlayer lose_sound = SoundPlayer{ "HitSomething.wav" };


int main()
{
    while (true)
    {
        start_game();
        bool game_over = false;
        // Initialise stuff and set values to 0

        while (!game_over)
        {
            // Call the update function to update the game state and render the game
            update(snake, food, game_over, score);

            // Sleep for a short period to control the game speed
            this_thread::sleep_for(chrono::milliseconds(75));

            // Clear the console before the next frame is rendered
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        }
    }
}

void update(Snake& snake, Food& food, bool& game_over, int& score)
{
    if (_kbhit())                                   // checks the console for key strokes
    {
        switch (_getch())                           // gets the key stroke for keyboard strokes
        {
        case 'w':
            snake.Direction(UP);
            break;
        case 'a':
            snake.Direction(LEFT);
            break;
        case 's':
            snake.Direction(DOWN);
            break;
        case 'd':
            snake.Direction(RIGHT);
            break;
        }
    }

    if (snake.WallCollision())                      // if the snake collides with the wall then game over
    {
        game_over = true;
        lose_sound.Play();
        return;
    }

    if (snake.FoodEaten(*food.GetPosition()))                    // if the snake has eaten the food
    {
        food.GenerateFood();                                    // generate new food item
        snake.Grow();                                           // increase the snake length
        collect_sound.Play();                                   // plays the collect sound
        score = score + 10;                                     // increase the score
    }

    snake.MoveSnake();
    Renderer::render(snake, food, score);                       // Render the game  

}
void start_game()
{
    snake.reset();
    system("cls");
    score = 0;
    srand(time(NULL));
    food.GenerateFood();
}