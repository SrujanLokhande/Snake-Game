#pragma once
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

// screen width and height for making the playable area
#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 25

#define UP    COORD {  0, -1 }
#define DOWN  COORD {  0,  1 }
#define LEFT  COORD { -1,  0 }
#define RIGHT COORD {  1,  0 }
#define ZERO  COORD {  0,  0 }

#define SNAKE_HEAD "()"
#define SNAKE_BODY "<>"
#define FRUIT "O-"

#define EMPTY "  "
#define WALL "##"

#define DRAW(X) std::cout << X 
#define PRINT(X, Y) std::cout << X << Y << std::endl << std::endl;

using namespace std;


