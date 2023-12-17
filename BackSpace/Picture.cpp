#include "pch.h"
#include "Picture.h"
#include "PictureImplementation.h"
#include "GLFWCode/OpenGLPicture.h"
//GetWidth

be::Picture::Picture(const std::string& filePath)
{
#ifdef BACKSPACE_MSCPP
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(filePath) };
#elif BACKSPACE_APPLE
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(filePath) };
#elif BACKSPACE_LINUX
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(filePath) };
#endif
}

void be::Picture::Bind()
{
	mImplementation->Bind();
}

 int be::Picture::GetWidth() const
{
	return mImplementation->GetWidth();
}

 int be::Picture::GetHeight() const
{
	return mImplementation->GetHeight();
}


