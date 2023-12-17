#pragma once
#pragma once
#include"pch.h"
#include"PictureImplementation.h"
namespace be {
	class OpenGLPicture : public PictureImplementation
	{
	public:
		OpenGLPicture(const std::string& filePath);
		~OpenGLPicture();
		int GetWidth() const;
		int GetHeight() const;

		void Bind() override;

	private:
		unsigned int texture;
		int width;
		int height;


	};
}