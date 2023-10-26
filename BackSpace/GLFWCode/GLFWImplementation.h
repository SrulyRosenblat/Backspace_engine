#pragma once
#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

namespace be
{
	class GLFWImplementation : public WindowImplementation {
	public:
		GLFWImplementation();
		virtual void Create(const std::string& name, int width, int height) override;
		virtual int GetHeight() const override;
		virtual int GetWidth() const override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		
	private:
		GLFWwindow* mWindow;
	};
}