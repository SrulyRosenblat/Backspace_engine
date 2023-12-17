#pragma once

#include "Utilities.h"
#include "Picture.h"

namespace be {
	class BACKSPACE_API Unit
	{
	public:
		Unit(const std::string& image, int x, int y);
		Unit( std::string&& image, int x, int y);
		Unit(const std::string& image, const std::string& altImage, int x, int y);
		Unit(std::string&& image, std::string&& altImage, int x, int y);

		 int GetWidth() const;
		 int GetHeight() const;
		int GetXCoord() const;
		int GetYCoord() const;
		void setCoords(int x, int y);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);
		
	private:
		Picture mImage;
		Picture mAltImage;

		int mXPosition;
		int mYPosition;

		template<typename T> friend class BackSpaceApp;
		friend BACKSPACE_API bool UnitsOverlap(const Unit& a, const Unit& b);
	};
	BACKSPACE_API bool UnitsOverlap(const Unit& a, const Unit& b);
}