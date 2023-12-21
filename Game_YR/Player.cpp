#include "Player.h"

Player::Player(const std::string textureRight, const std::string textureLeft, int x, int y,int boundingHieght,int boundingWidth):
	mUnit( textureRight,textureLeft,x,y ), boundHeight(boundingHieght),boundWidth(boundingWidth)
{
}

void Player::MoveTime()
{
	if (movingRight && IsInBounds(speed, 0))
		mUnit.UpdateXCoord(speed);
	else if (movingLeft && IsInBounds(-speed, 0))
		mUnit.UpdateXCoord(-speed );
	else if (movingUp && IsInBounds(0, speed))
		mUnit.UpdateYCoord(speed);
	else if (movingDown && IsInBounds(0, -speed))
		mUnit.UpdateYCoord(-speed);
	if (hoverUp) {
		mUnit.UpdateYCoord(1);
		hoverLevel += 1;

	}
	else {
		mUnit.UpdateYCoord(-1);
		hoverLevel -= 1;
	}
	if (hoverLevel >= HoverTop) {
		hoverUp = false;
	}
	else if (hoverLevel <= hoverBottom) {
		hoverUp = true;
	}

}

be::Unit& Player::getUnit()
{
	return mUnit;
}

void Player::OnKeyReleased(const be::KeyReleased& e) {
	if (e.GetKeyCode() == BACKSPACE_KEY_RIGHT) {
		movingRight = false;

	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_LEFT) {
		movingLeft = false;
	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_UP) {
		movingUp = false;
	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_DOWN) {
		movingDown = false;
	}
}

void Player::OnKeyPressed(const be::KeyPressed& e) {

	if (e.GetKeyCode() == BACKSPACE_KEY_RIGHT) {

		movingRight = true;
		facingRight = true;
	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_LEFT) {

		movingLeft = true;
		facingRight = false;
	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_UP) {

		movingUp = true;
		hoverLevel = 0;
		hoverUp = false;

	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_DOWN) {

		movingDown = true;
		hoverLevel = 0;
		hoverUp = true;
	}
}

bool Player::IsInBounds(int x, int y)
{
	int posx = mUnit.GetXCoord();
	int posy = mUnit.GetYCoord();
	int width = mUnit.GetWidth();
	int height = mUnit.GetHeight();
	if (x)
		return posx + x > 0 && posx + x + width < boundWidth;
	else
		return posy + y + HoverTop > 0 && posy + y + height < boundHeight;

}
