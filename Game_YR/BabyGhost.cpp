#include "BabyGhost.h"

BabyGhost::BabyGhost(const std::string textureRight, const std::string textureLeft, int x, int y, int boundingHieght, int boundingWidth) :
	mUnit(textureRight, textureLeft, x, y), boundHeight(boundingHieght), boundWidth(boundingWidth)
{
}
void BabyGhost::MoveTo(int x, int y) {
	int babyX = mUnit.GetXCoord();
	int babyY = mUnit.GetYCoord();
	if ((babyX - x) > 10) {
		facingRight = false;
		movingLeft = true;
		movingRight = false;
	}
	else if ((babyX - x) < -10) {
		facingRight = true;
		movingRight = true;
		movingLeft = false;
	}
	else {
		movingLeft = false;
		movingRight = false;
	}

	if ((babyY - y) > 10) {
		movingUp = false;
		movingDown = true;
	}
	else if ((babyY - y) < -10) {
		movingUp = true;
		movingDown = false;
	}
	else {
		movingUp = false;
		movingDown = false;
	}
}
void BabyGhost::Follow(be::Unit& player)
{
	int playerX = player.GetXCoord();
	int playerY = player.GetYCoord();
	int playerEndX = playerX + player.GetWidth() / 2;
	int babyX = mUnit.GetXCoord();
	int babyY = mUnit.GetYCoord();
	if (bored) {
		MoveTo(interestingX,interestingY);
		return;
	}
	if ((babyX - playerX) > 300) {
		facingRight = false;
		movingLeft = true;
		movingRight = false; 
	}
	else if ((babyX - playerEndX) < -300) {
		facingRight = true;
		movingRight = true;
		movingLeft = false; 
	}
	else {
		movingLeft = false;
		movingRight = false; 
	}

	if ((babyY - playerY) > 10) {
		movingUp = false;
		movingDown = true;
	}
	else if ((babyY - playerY) < -10) {
		movingUp = true;
		movingDown = false;
	}
	else {

		movingUp = false;
		movingDown = false;

	}
}

void BabyGhost::MoveTime()
{
	if (bored) {
		exploringTime--;
		if (exploringTime <= 0) {
			bored = false;
			waiting = 0;
		}
	}
	if (movingRight && IsInBounds(speed, 0))
		mUnit.UpdateXCoord(speed);
	else if (movingLeft && IsInBounds(-speed, 0))
		mUnit.UpdateXCoord(-speed );
		
	if (movingUp && IsInBounds(0, speed))
		mUnit.UpdateYCoord(speed);
	else if (movingDown && IsInBounds(0, -speed))
		mUnit.UpdateYCoord(-speed);

	if (!movingRight && !movingLeft)
		waiting++;
	else
		waiting = 0;

	if (waiting == boredThreshold) {
		bored = true;
		interestingX = std::rand() % boundWidth;
		interestingY = std::rand() % boundHeight;
		exploringTime = timeToExplore;
	}
		



}
void BabyGhost::SetBoredThreshold(int threshold)
{
	boredThreshold = threshold;
}
void BabyGhost::SetTimeToExplore(int time)
{
	timeToExplore = time;
}
void BabyGhost::SetBored(bool isBored)
{
	bored = isBored;
}
bool BabyGhost::IsInBounds(int x, int y)
{
	int posx = mUnit.GetXCoord();
	int posy = mUnit.GetYCoord();
	int width = mUnit.GetWidth();
	int height = mUnit.GetHeight();
	if (x)
		return posx + x > 0 && posx + x + width < boundWidth;
	else
		return posy + y > 0 && posy + y + height < boundHeight;

}

be::Unit& BabyGhost::getUnit()
{
	return mUnit;
}
