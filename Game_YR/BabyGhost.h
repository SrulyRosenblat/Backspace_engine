#pragma once
#include "BackSpace.h"

class BabyGhost {
public:
    const int speed{ 10 };
    bool facingRight{ true };
    BabyGhost(const std::string textureRight, const std::string textureLeft, int x, int y, int boundHeight, int boundWidth);
    void MoveTo(int x, int y);
    ~BabyGhost() = default;
    void Follow(be::Unit& player);
    void MoveTime();
    void SetBoredThreshold(int threshold);
    void SetTimeToExplore(int time);
    void SetBored(bool isBored);
    bool IsInBounds(int x, int y);
    be::Unit& getUnit();

private:
    int x{ 0 };
    int y{ 0 };
    be::Unit mUnit;
    int boundHeight;
    int boundWidth;

    bool bored{ false };
    int timeToExplore{ 75 };
    int exploringTime{ 0 };
    int waiting{ 0 };
    int boredThreshold{ 100 };
    int interestingX{ 0 };
    int interestingY{ 0 };

    bool movingRight{ false };
    bool movingLeft{ false };
    bool movingUp{ false };
    bool movingDown{ false };

};