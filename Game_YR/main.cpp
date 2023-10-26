#include "BackSpace.h"
#include<iostream>
class MyGame :public be::BackSpaceApp<MyGame>
{
public:
	// used to make more readable
	virtual void OnUpdate() override
	{
		std::cout << "game runnung" << std::endl;
		std::cout << "yay!" << std::endl;
	}
private:
};

BACKSPACE_APPLICATION_START(MyGame)
