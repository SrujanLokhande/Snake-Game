#pragma once
#ifndef COORD_EXTENSION_H
#define COORD_EXTENSION_H

#include <Windows.h>

#define INVERTED_COORD COORD { -1, -1 }

// Overload operator that allows us to multiply coords with coords
COORD operator*(const COORD& lhs, const COORD& rhs)
{
    COORD result;
    result.X = lhs.X * rhs.X;
    result.Y = lhs.Y * rhs.Y;
    return result;
}

// Overload operator that allows us to compare COORD types
bool operator==(const COORD& lhs, const COORD& rhs)
{
    bool matching_x = (lhs.X == rhs.X);
    bool matching_y = (lhs.Y == rhs.Y);

    return (matching_x && matching_y);
}

// Overload operator that allows us to compare COORD types
bool operator!=(const COORD& lhs, const COORD& rhs)
{
    return !(lhs == rhs);
}

// Overload operator that allows us to add COORD types together
COORD& operator+=(COORD& lhs, const COORD& rhs)
{
    lhs.X += rhs.X;
    lhs.Y += rhs.Y;
    return lhs;
}

#endif