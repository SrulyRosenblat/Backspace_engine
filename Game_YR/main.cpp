#include "BackSpace.h"
#include<iostream>
#include "Player.h"
#include "BabyGhost.h"
class MyGame :public be::BackSpaceApp<MyGame>
{
public:
	const int SPEED{ 30 };
	const int HEIGHT{ 720 };
	const int WIDTH{ 1280 };

	MyGame() {
		SetKeyPressedCallback([this](const be::KeyPressed& e) {player.OnKeyPressed(e); });
		SetKeyReleasedCallback([this](const be::KeyReleased& e) {player.OnKeyReleased(e); });
	}
	// used to make more readable
	virtual void OnUpdate() override
	{
		Draw(0, 0, bg);
		//Draw(x, y, mUnit.mImage);
		player.MoveTime();
		placePLayer();
	
		baby.Follow(player.getUnit());
		baby.MoveTime();
		placeBaby();

	}
	void placePLayer() {
		be::Unit& unit = player.getUnit();
		if (player.facingRight)
			Draw(unit);
		else
			DrawAlt(unit);
	}
	void placeBaby() {
		be::Unit& unit = baby.getUnit();
		if (baby.facingRight)
			Draw(unit);
		else
			DrawAlt(unit);
	}
private:

	BabyGhost baby{ "../Assets/Pictures/BabyGhost.png","../Assets/Pictures/BabyGhostLeft.png",500,100 ,HEIGHT,WIDTH };
	Player player{ "../Assets/Pictures/ghost.png","../Assets/Pictures/ghostLeft.png",500,100,HEIGHT,WIDTH };
	be::Picture mPic{ "../Assets/Pictures/ghostLeft.png" };
	be::Picture bg{ "../Assets/Pictures/haunted.png" };
	//edited unit to take two textures too
	be::Unit mUnit{ "../Assets/Pictures/ghost.png","../Assets/Pictures/ghostLeft.png",500,100};
};

BACKSPACE_APPLICATION_START(MyGame)
