#pragma once

#include "Utilities.h"

namespace be
{
	class BACKSPACE_API KeyPressed
	{
	public:
		KeyPressed(int kCode);
		int GetKeyCode() const;

	private:
		int mKeyCode;

	};

	class BACKSPACE_API KeyReleased
	{
		
	public:
		KeyReleased(int kCode);
		int GetKeyCode() const;

	private:
		int mKeyCode;

	};

	class BACKSPACE_API WindowClosed
	{

	};
}