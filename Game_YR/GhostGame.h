#include "BackSpace.h"
#include<iostream>
#include "Player.h"
#include "BabyGhost.h"
class GhostGame :public be::BackSpaceApp<GhostGame>
{
public:
	const int SPEED{ 30 };
	const int HEIGHT{ 720 };
	const int WIDTH{ 1280 };

	GhostGame();
	// used to make more readable
	virtual void OnUpdate() override;
	void placePLayer();
	void placeBaby();
private:

	BabyGhost baby{ "../Assets/Pictures/BabyGhost.png","../Assets/Pictures/BabyGhostLeft.png",500,100 ,HEIGHT,WIDTH };
	Player player{ "../Assets/Pictures/ghost.png","../Assets/Pictures/ghostLeft.png",500,100,HEIGHT,WIDTH };
	be::Picture mPic{ "../Assets/Pictures/ghostLeft.png" };
	be::Picture bg{ "../Assets/Pictures/haunted.png" };
	//edited unit to take two textures too
	be::Unit mUnit{ "../Assets/Pictures/ghost.png","../Assets/Pictures/ghostLeft.png",500,100 };
};
