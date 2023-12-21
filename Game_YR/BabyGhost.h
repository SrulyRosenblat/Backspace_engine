#pragma once
#include "BackSpace.h"

class BabyGhost {
public:
    const int Speed{ 10 };
    bool FacingRight{ true };
    BabyGhost(const std::string textureRight, const std::string textureLeft, int x, int y, int BoundHeight, int BoundWidth);
    void MoveTo(int x, int y);
    ~BabyGhost() = default;
    void Follow(be::Unit& player);
    void MoveTime();
    void SetBoredThreshold(int threshold);
    void SetTimeToExplore(int time);
    void SetBored(bool isBored);
    bool IsInBounds(int x, int y);
    be::Unit& GetUnit();

private:
    int x{ 0 };
    int y{ 0 };
    be::Unit mUnit;
    int BoundHeight;
    int BoundWidth;

    bool bored{ false };
    int timeToExplore{ 75 };
    int exploringTime{ 0 };
    int waiting{ 0 };
    int boredThreshold{ 100 };
    int interestingX{ 0 };
    int interestingY{ 0 };

    bool MovingRight{ false };
    bool MovingLeft{ false };
    bool MovingUp{ false };
    bool MovingDown{ false };

};