set(HEADER_FILES 
	include/BackSpace.h
	BackSpaceApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	)
set(SOURCE_FILES
	GameWindow.cpp
	#placeholder.cpp
	GLFWCode/GLFWImplementation.cpp
)


add_definitions(-DBE_DEBUG=2)
add_definitions(-DBACKSPAC_LIB=2)
include_directories(../BackSpace)

include_directories(../glfw/include)

add_library(BackSpace SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(BackSpace PRIVATE pch.h)

target_link_libraries(BackSpace glfw)