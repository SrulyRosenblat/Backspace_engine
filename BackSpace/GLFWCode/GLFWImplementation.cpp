#include "pch.h"
#include "GLFWImplementation.h"
namespace be {
	GLFWImplementation::GLFWImplementation() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	}
	void GLFWImplementation::Create(const std::string& name, int width, int height)
	{
		mWindow = glfwCreateWindow(800, 600, "Game_yr", NULL, NULL);
	}
	int GLFWImplementation::GetHeight() const
	{
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}
	int GLFWImplementation::GetWidth() const
	{
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}
	void GLFWImplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}
	void GLFWImplementation::PollEvents()
	{
		glfwPollEvents();
	}
}