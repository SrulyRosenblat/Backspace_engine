set(HEADER_FILES 
	include/BackSpace.h
	BackSpaceApp.h
	Events.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLPicture.h
	GLFWCode/OpenGLRenderer.h
	GLFWCode/OpenGLShader.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
	Utilities.h
	WindowImplementation.h
	Keys.h
	)
set(SOURCE_FILES
	Events.cpp
	GameWindow.cpp
	#placeholder.cpp
	GLFWCode/GLFWImplementation.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLShader.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)


add_definitions(-DBE_DEBUG=2)
# used to be
#add_definitions(-DBACKSPAC_LIB)
add_definitions(-DBACKSPACE_LIB)

include_directories(../BackSpace)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

add_library(BackSpace SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(BackSpace PRIVATE pch.h)

target_link_libraries(BackSpace glfw)
target_link_libraries(BackSpace glad)
target_link_libraries(BackSpace stbi)