#pragma once

#include "pch.h"
#include "Utilities.h"
#include "PictureImplementation.h"


namespace be
{
	class BACKSPACE_API Picture
	{

	public:
		Picture(const std::string& filePath);
		void Bind();
		int GetWidth() const;
		int GetHeight() const;



	private:
		std::unique_ptr<PictureImplementation> mImplementation;
	};
}