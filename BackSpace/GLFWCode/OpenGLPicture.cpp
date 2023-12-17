#pragma once
# include "pch.h"

# include "glad/glad.h"
# include "GLFW/glfw3.h"

# include "OpenGLPicture.h"

# include"../Utilities.h"

#include "stb_image.h"

namespace be
{
	OpenGLPicture::OpenGLPicture(const std::string& filePath)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);

		unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);//missing something?
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);//missing something?
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			BE_ERROR("Failed to load a picture from the file");
		}

		stbi_image_free(data);

	}
	OpenGLPicture::~OpenGLPicture()
	{
		unsigned int textures[] = { texture };
		glDeleteTextures(1, textures);
	}
	int OpenGLPicture::GetWidth() const
	{
		return width;
	}
	int OpenGLPicture::GetHeight() const
	{
		return height;
	}
	void OpenGLPicture::Bind()
	{
		// repeated??? right???
		glBindTexture(GL_TEXTURE_2D, texture);
	};

}