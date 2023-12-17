#include"pch.h"
#include "GameWindow.h"
#include "GLFWCode/GLFWImplementation.h"
namespace be {
	GameWindow::GameWindow()
	{
#ifdef BACKSPACE_MSCPP
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif BACKSPACE_APPLE
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif BACKSPACE_LINUX
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#endif

	
	}
	void GameWindow::Create(const std::string& name, int width, int height)
	{
		mImplementation->Create(name, width, height);
	}
	int GameWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}
	int GameWindow::GetWidth() const
	{
		return mImplementation->GetWidth();
	}
	void GameWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}
	void GameWindow::PollEvents()
	{
		mImplementation->PollEvents();
	}

	void GameWindow::SetKeyPressedCallback(std::function<void(const KeyPressed&)>& callbackFunc)
	{
		mImplementation->SetKeyPressedCallback(callbackFunc);
	}
	void GameWindow::SetKeyReleasedCallback(std::function<void(const KeyReleased&)>& callbackFunc) {
		mImplementation->SetKeyReleasedCallback(callbackFunc);
	}
	void GameWindow::SetWindowCloseCallback(std::function<void()>& callbackFunc) {
		mImplementation->SetWindowCloseCallback(callbackFunc);
	}
}