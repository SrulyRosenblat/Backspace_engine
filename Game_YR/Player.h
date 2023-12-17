#pragma once
#pragma once

#include <BackSpace.h>

class Player
{
public:
    Player(const std::string& textureRight, const std::string& textureLeft, int x, int y);
    ~Player() = default;

    void MoveOnX(int amount);
    void MoveOnY(int amount);

private:
    int x;
    int y;
    be::Unit mUnit;
};