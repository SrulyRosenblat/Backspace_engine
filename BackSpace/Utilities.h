#pragma once



// defined in settings
#if BE_DEBUG==2 // checks if be_debug == 2

#define BE_ERROR(x) std::cout<<x<<std::endl;
#define BE_LOG(x) std::cout<<x<<std::endl;

#elif BE_DEBUG==1

#define BE_ERROR(x) std::cout<<x<<std::endl;
#define BE_LOG(x)

#else

#define BE_ERROR(x)
#define BE_LOG(x)

#endif // BE_DEBUG
#ifdef BACKSPACE_MSCPP
	#ifdef BACKSPACE_LIB
		#define BACKSPACE_API __declspec(dllexport)
	#else
		#define BACKSPACE_API __declspec(dllimport)

	#endif // DEBUG
#else
	#define BACKSPACE_API
#endif // BACKSPACE_MSCPP


// \ makes line not end dont allow spaces after
#define BACKSPACE_APPLICATION_START(ClassName) \
int main()\
{\
	ClassName::Init(); \
	ClassName::RunInterface(); \
	return(0);\
}