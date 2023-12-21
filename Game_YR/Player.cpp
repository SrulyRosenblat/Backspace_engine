#include "Player.h"

Player::Player(const std::string textureRight, const std::string textureLeft, int x, int y,int boundingHieght,int boundingWidth):
	mUnit( textureRight,textureLeft,x,y ), BoundHeight(boundingHieght),BoundWidth(boundingWidth)
{
}

void Player::MoveTime()
{
	if (MovingRight && IsInBounds(Speed, 0))
		mUnit.UpdateXCoord(Speed);
	else if (MovingLeft && IsInBounds(-Speed, 0))
		mUnit.UpdateXCoord(-Speed );
	else if (MovingUp && IsInBounds(0, Speed))
		mUnit.UpdateYCoord(Speed);
	else if (MovingDown && IsInBounds(0, -Speed))
		mUnit.UpdateYCoord(-Speed);
	if (HoverUp) {
		mUnit.UpdateYCoord(1);
		HoverLevel += 1;

	}
	else {
		mUnit.UpdateYCoord(-1);
		HoverLevel -= 1;
	}
	if (HoverLevel >= HoverTop) {
		HoverUp = false;
	}
	else if (HoverLevel <= hoverBottom) {
		HoverUp = true;
	}

}

be::Unit& Player::GetUnit()
{
	return mUnit;
}

void Player::OnKeyReleased(const be::KeyReleased& e) {
	if (e.GetKeyCode() == BACKSPACE_KEY_RIGHT) {
		MovingRight = false;

	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_LEFT) {
		MovingLeft = false;
	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_UP) {
		MovingUp = false;
	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_DOWN) {
		MovingDown = false;
	}
}

void Player::OnKeyPressed(const be::KeyPressed& e) {

	if (e.GetKeyCode() == BACKSPACE_KEY_RIGHT) {

		MovingRight = true;
		FacingRight = true;
	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_LEFT) {

		MovingLeft = true;
		FacingRight = false;
	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_UP) {

		MovingUp = true;
		HoverLevel = 0;
		HoverUp = false;

	}
	else if (e.GetKeyCode() == BACKSPACE_KEY_DOWN) {

		MovingDown = true;
		HoverLevel = 0;
		HoverUp = true;
	}
}

bool Player::IsInBounds(int x, int y)
{
	int posx = mUnit.GetXCoord();
	int posy = mUnit.GetYCoord();
	int width = mUnit.GetWidth();
	int height = mUnit.GetHeight();
	if (x)
		return posx + x > 0 && posx + x + width < BoundWidth;
	else
		return posy + y + HoverTop > 0 && posy + y + height < BoundHeight;

}
