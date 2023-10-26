#pragma once

#include "Utilities.h"
#include "GameWindow.h"
// singleton class with only one instance
// design pattern = typical solution
// can not have ClassName a,b or even CLassName a becouse cant call constructer
// use static so vars are  not connected to one instance of class and accsesable to all instances
// static method = function that is not tied to any object and could be called without one but
//	can deal with only static methods and variables

namespace be
{
	template<typename T>
	class  BackSpaceApp
	{
		public:
			static void Init();
			static void RunInterface();

			virtual void OnUpdate(); // designed to be overiden its not implemented here
			void Run();// starts game

			friend typename T;
			
		private:
			// no underscores
			//cammel case
			// function names start capital
			// vars start lowercase
			// member variables start with 'm'
			BackSpaceApp();
			// inline c++ 17 and after
			inline static BackSpaceApp* sInstance{ nullptr };

			GameWindow mWindow;

			bool mShouldContinue{ true }; // used to set initial value

	};
};
#include "BackSpaceApp.cpp"