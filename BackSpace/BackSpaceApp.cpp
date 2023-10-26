#include "pch.h"
#include "BackSpaceApp.h"

namespace be
{
	template<typename T>
	void BackSpaceApp<typename T>::Run()
	{
		mWindow.Create("game_ps",1000, 800);
		while (mShouldContinue) 
		{
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
			
		}
	}
	template<typename T>
	void BackSpaceApp<typename T>::Init() {
		if (sInstance == nullptr) {
			sInstance = new T;
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
	BackSpaceApp<typename T>::BackSpaceApp()
	{}
}