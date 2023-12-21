#pragma once

#include "BackSpace.h"
class Player
{
public:
    const int Speed{ 30 };
    bool FacingRight{ true };
    Player(const std::string textureRight, const std::string textureLeft, int x, int y, int boundingHieght, int BoundingWidth);
    ~Player() = default;

    void MoveTime();
    be::Unit& GetUnit();
    void OnKeyReleased(const be::KeyReleased& e);
    void OnKeyPressed(const be::KeyPressed& e);

private:
    bool IsInBounds(int x,int y);
    int x{ 0 };
    int y{ 0 };
    be::Unit mUnit;
    int HoverLevel{ 0 };
    int hoverBottom{ -10 };
    int HoverTop{ 10 };
    int BoundHeight;
    int BoundWidth;
    
    bool HoverUp{ false };
    bool MovingRight{ false };
    bool MovingLeft{ false };
    bool MovingUp{ false };
    bool MovingDown{ false };
    
};