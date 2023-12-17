#pragma once
#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"
#include "Events.h"
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

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)>& callbackFunc) override;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)>& callbackFunc) override;
		virtual void SetWindowCloseCallback(std::function<void()>& callbackFunc) override;
	
		
	private:
		struct Callbacks {
			std::function<void(const KeyPressed&)> KeyPressedFunc{ [](const KeyPressed&) {} };
			std::function<void(const KeyReleased&)> KeyReleasedFunc{ [](const KeyReleased&) {} };
			std::function<void()> windowCloseFunc{ []() {} };
		} mCallbacks;
		GLFWwindow* mWindow;
	};
}