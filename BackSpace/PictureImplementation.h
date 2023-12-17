#pragma once

namespace be {
	class PictureImplementation
	{
	public:
		virtual void Bind() = 0;
		virtual ~PictureImplementation() {};
		virtual  int GetWidth() const =0;
		virtual  int GetHeight() const = 0;
	};
}