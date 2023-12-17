#pragma once

#include "RendererImplementation.h"

namespace be {
	class OpenGLRenderer : public RendererImplementation
	{
	public:
		virtual void Init() override;
		virtual void Draw(int x, int y, Picture& pic);
		virtual void Clear() override;
	};
}