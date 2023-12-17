#pragma once

#include "Picture.h"

namespace be {
	class RendererImplementation
	{
	public:
		virtual void Init() = 0;
		virtual void Draw(int x, int y, Picture& pic) = 0;
		virtual void Clear() = 0;
		virtual ~RendererImplementation() {};


	private:

	};

}