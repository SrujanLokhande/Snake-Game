#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include "Snake.h"
#include "Food.h"

class Renderer {
public:
    static void render(const Snake& snake, const Food& food, int score);
};

#endif