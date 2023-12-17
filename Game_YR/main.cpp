#include "BackSpace.h"
#include<iostream>
class MyGame :public be::BackSpaceApp<MyGame>
{
public:
	const int SPEED{ 30 };
	const int HEIGHT{ 720 };
	const int WIDTH{ 1280 };

	MyGame() {
		SetKeyPressedCallback([this](const be::KeyPressed& e) {OnKeyPressed(e); });
		SetKeyReleasedCallback([this](const be::KeyReleased& e) {OnKeyReleased(e); });
	}
	// used to make more readable
	virtual void OnUpdate() override
	{
		Draw(0, 0, bg);
		moveHandler();
		//Draw(x, y, mUnit.mImage);
		placePLayer();
		//std::cout << "game runnung" << std::endl;
		//std::cout << "yay!" << std::endl;
	}
	void placePLayer() {
		if (facingRight)
			Draw(mUnit);
		else
			DrawAlt(mUnit);
	}
	void OnKeyPressed(const be::KeyPressed& e) {
		
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

	void moveHandler() {
		if(movingRight)
			mUnit.UpdateXCoord(SPEED);
		else if(movingLeft)
			mUnit.UpdateXCoord(-SPEED);
		else if (movingUp)
			mUnit.UpdateYCoord(SPEED);
		else if (movingDown)
			mUnit.UpdateYCoord(-SPEED);
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
			std::cout << hoverLevel << std::endl;
		}
		else if (hoverLevel <= hoverBottom) {
			hoverUp = true;
		}

	}


	void OnKeyReleased(const be::KeyReleased& e) {
		std::cout << e.GetKeyCode() << std::endl;
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

private:

	int hoverLevel{ 0 };
	int hoverBottom{ -10 };
	int HoverTop{ 10 };
	bool facingRight{ true };
	bool hoverUp{ false };
	bool movingRight{ false };
	bool movingLeft{ false };
	bool movingUp{ false };
	bool movingDown{ false };
	be::Picture mPic{ "../Assets/Pictures/ghostLeft.png" };
	be::Picture bg{ "../Assets/Pictures/haunted.png" };
	//edited unit too take two textures too
	be::Unit mUnit{ "../Assets/Pictures/ghost.png","../Assets/Pictures/ghostLeft.png",500,100};
};

BACKSPACE_APPLICATION_START(MyGame)
