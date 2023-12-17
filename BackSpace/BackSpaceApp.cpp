#include "pch.h"
#include "BackSpaceApp.h"
#include "Utilities.h"

//#include"../glad/include/glad/glad.h"
//#include "../glfw/include/GLFW/glfw3.h"
//#include "../stbi/stb_image.h"

#include "Shader.h"
#include "Picture.h"
#include "Renderer.h"
namespace be
{
	template<typename T>
	BackSpaceApp<typename T>::BackSpaceApp()
	{
		mWindow.Create("game_ps",1280,720);
		mRenderer.Init();

		SetWindowCloseCallback([this]() {DefualtWindowCloseHandler(); });//lambda [visible in function](){}

	}

	template<typename T>
	void BackSpaceApp<typename T>::Init() {
		if (sInstance == nullptr) {
			sInstance = new T;
		}
	}

	template<typename T>
	void BackSpaceApp<typename T>::Run()
	{
		///// shaders /////
		be::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl","../Assets/Shaders/DefaultFragmentShader.glsl"};
		be::Picture pic{ "../Assets/Pictures/test2.png" };

		mNextFrameTime = std::chrono::steady_clock::now();
		while (mShouldContinue)
		{
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize",mWindow.GetWidth(), mWindow.GetHeight());
			//Draw(0, 0, pic);

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}

	}

	template<typename T>
	void BackSpaceApp<typename T>::RunInterface()
	{
		sInstance->Run();
	}
	template<typename T>
	void BackSpaceApp<typename T>::OnUpdate()
	{
		
	}
	template<typename T>
	void BackSpaceApp<typename T>::Draw(int x, int y, Picture& pic)
	{
		mRenderer.Draw(x, y, pic);
	}
	template<typename T>
	void BackSpaceApp<typename T>::Draw(Unit& unit)
	{
		Draw(unit.GetXCoord(), unit.GetYCoord(), unit.mImage);
		
	}
	template<typename T>
	void BackSpaceApp<typename T>::DrawAlt(Unit& unit)
	{
		Draw(unit.GetXCoord(), unit.GetYCoord(), unit.mAltImage);

	}

	template<typename T>
	void BackSpaceApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) {
		mWindow.SetKeyPressedCallback(callbackFunc);
	}
	template<typename T>
	void BackSpaceApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) {
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}
	template<typename T>//&?
	void BackSpaceApp<T>::SetWindowCloseCallback(std::function<void()> callbackFunc) {
		mWindow.SetWindowCloseCallback(callbackFunc);
	}
	template<typename T>
	void BackSpaceApp<T>::DefualtWindowCloseHandler() {
		mShouldContinue = false;
	}


}