#include "pch.h"
#include "Renderer.h"
#include "GLFWCode/OpenGLRenderer.h"

be::Renderer::Renderer() {
#ifdef BACKSPACE_MSCPP
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif BACKSPACE_APPLE
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif BACKSPACE_LINUX
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
}

void be::Renderer::Renderer::Init() {
	mImplementation->Init();
}

void be::Renderer::Renderer::Draw(int x, int y, Picture& pic) {
	mImplementation->Draw(x, y, pic);
}

void be::Renderer::Renderer::Clear() {
	mImplementation->Clear();
}