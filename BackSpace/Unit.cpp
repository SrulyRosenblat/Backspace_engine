#include "pch.h"
#include "Unit.h"

namespace be {
	Unit::Unit(const std::string& image, int x, int y):
		mImage(image),mAltImage(image), mXPosition(x), mYPosition(y)
	{
	}

	Unit::Unit( std::string&& image, int x, int y) :
		mImage(std::move(image)), mAltImage(std::move(image)), mXPosition(x), mYPosition(y)
	{
	}

	Unit::Unit(const std::string& image, const std::string& altImage, int x, int y):
		mImage(image), mAltImage(altImage), mXPosition(x), mYPosition(y)
	{
	}

	Unit::Unit(std::string&& image, std::string&& altImage, int x, int y) :
		mImage(std::move(image)), mAltImage(std::move(altImage)), mXPosition(x), mYPosition(y)
	{
	}



	int Unit::GetWidth() const
	{
		return mImage.GetWidth();
	}

	 int Unit::GetHeight() const
	{
		return mImage.GetHeight();
	}

	int Unit::GetXCoord() const
	{
		return mXPosition;
	}

	int Unit::GetYCoord() const
	{
		return mYPosition;
	}

	void Unit::setCoords(int x, int y)
	{
		mXPosition = x;
		mYPosition = y;
	}

	void Unit::UpdateXCoord(int amount)
	{
		mXPosition += amount;
	}

	void Unit::UpdateYCoord(int amount)
	{
		mYPosition += amount;

	}

	bool UnitsOverlap(const Unit& a, const Unit& b)
	{
		int left_a{ a.mXPosition };
		int right_a{ a.mXPosition + a.mImage.GetWidth() };
		int left_b{ b.mXPosition };
		int right_b{ b.mXPosition + b.mImage.GetWidth() };

		bool x_intersection{(left_a <= left_b and left_b <= right_a) or (left_b <= left_a and left_a <= right_b)};

		int bot_a{ a.mYPosition };
		int top_a{ a.mYPosition + a.mImage.GetHeight() };
		int bot_b{ b.mYPosition };
		int top_b{ b.mYPosition + b.mImage.GetHeight() };

		bool y_intersection{(bot_a <= bot_b and bot_b <= top_a) or (bot_b <= bot_a and bot_a <= top_b)};

		return x_intersection and y_intersection;

	}

}