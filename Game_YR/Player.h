#pragma once

#include "BackSpace.h"
class Player
{
public:
    const int speed{ 30 };
    bool facingRight{ true };
    Player(const std::string textureRight, const std::string textureLeft, int x, int y, int boundingHieght, int BoundingWidth);
    ~Player() = default;

    void MoveTime();
    be::Unit& getUnit();
    void OnKeyReleased(const be::KeyReleased& e);
    void OnKeyPressed(const be::KeyPressed& e);

private:
    bool IsInBounds(int x,int y);
    int x{ 0 };
    int y{ 0 };
    be::Unit mUnit;
    int hoverLevel{ 0 };
    int hoverBottom{ -10 };
    int HoverTop{ 10 };
    int boundHeight;
    int boundWidth;
    
    bool hoverUp{ false };
    bool movingRight{ false };
    bool movingLeft{ false };
    bool movingUp{ false };
    bool movingDown{ false };
    
};