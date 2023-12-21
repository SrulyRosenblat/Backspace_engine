#include "BabyGhost.h"

BabyGhost::BabyGhost(const std::string textureRight, const std::string textureLeft, int x, int y, int boundingHieght, int boundingWidth) :
	mUnit(textureRight, textureLeft, x, y), BoundHeight(boundingHieght), BoundWidth(boundingWidth)
{
}
void BabyGhost::MoveTo(int x, int y) {
	int babyX = mUnit.GetXCoord();
	int babyY = mUnit.GetYCoord();
	if ((babyX - x) > 10) {
		FacingRight = false;
		MovingLeft = true;
		MovingRight = false;
	}
	else if ((babyX - x) < -10) {
		FacingRight = true;
		MovingRight = true;
		MovingLeft = false;
	}
	else {
		MovingLeft = false;
		MovingRight = false;
	}

	if ((babyY - y) > 10) {
		MovingUp = false;
		MovingDown = true;
	}
	else if ((babyY - y) < -10) {
		MovingUp = true;
		MovingDown = false;
	}
	else {
		MovingUp = false;
		MovingDown = false;
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
		FacingRight = false;
		MovingLeft = true;
		MovingRight = false; 
	}
	else if ((babyX - playerEndX) < -300) {
		FacingRight = true;
		MovingRight = true;
		MovingLeft = false; 
	}
	else {
		MovingLeft = false;
		MovingRight = false; 
	}

	if ((babyY - playerY) > 10) {
		MovingUp = false;
		MovingDown = true;
	}
	else if ((babyY - playerY) < -10) {
		MovingUp = true;
		MovingDown = false;
	}
	else {

		MovingUp = false;
		MovingDown = false;

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
	if (MovingRight && IsInBounds(Speed, 0))
		mUnit.UpdateXCoord(Speed);
	else if (MovingLeft && IsInBounds(-Speed, 0))
		mUnit.UpdateXCoord(-Speed );
		
	if (MovingUp && IsInBounds(0, Speed))
		mUnit.UpdateYCoord(Speed);
	else if (MovingDown && IsInBounds(0, -Speed))
		mUnit.UpdateYCoord(-Speed);

	if (!MovingRight && !MovingLeft)
		waiting++;
	else
		waiting = 0;

	if (waiting == boredThreshold) {
		bored = true;
		interestingX = std::rand() % BoundWidth;
		interestingY = std::rand() % BoundHeight;
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
		return posx + x > 0 && posx + x + width < BoundWidth;
	else
		return posy + y > 0 && posy + y + height < BoundHeight;

}

be::Unit& BabyGhost::GetUnit()
{
	return mUnit;
}
