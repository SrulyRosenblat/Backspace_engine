#include "pch.h"
#include "Events.h"

be::KeyPressed::KeyPressed(int kCode): mKeyCode(kCode)
{
}
 
int be::KeyPressed::GetKeyCode() const
{
	return mKeyCode;
}

be::KeyReleased::KeyReleased(int kCode) : mKeyCode(kCode)
{
}

int be::KeyReleased::GetKeyCode() const
{
	return mKeyCode;
}
