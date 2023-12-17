#include "pch.h"
#include "BackSpaceApp.h"
#include "Utilities.h"

#include"../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "../stbi/stb_image.h"

#include "Shader.h"

namespace be
{
	template<typename T>
	BackSpaceApp<typename T>::BackSpaceApp()
	{
		//mWindow.Create("game_ps", 1000, 800);
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
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			BE_ERROR("failed to initilize glad");
			return;
		}

		float vertices[] = {
			100.f,100.f,0.0f,0.0f,
			 300.f,100.f,1.0f,0.0f,
			100.f, 300.f,0.0f,1.0f,
			 300.f, 300.f,1.0f,1.0f
		};
		unsigned int indices[] = {
			0,1,2,
			1,2,3
		};

		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		//glBindVertexArrays();
		glBindVertexArray(VAO);

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE, 4* sizeof(float), (void*)(2*sizeof(float)));
		glEnableVertexAttribArray(1);
		///// shaders /////
		be::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl","../Assets/Shaders/DefaultFragmentShader.glsl"};
		shader.SetUniform2Ints("ScreenSize", 1000, 800);

		///// textures /////

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);

		unsigned char* data = stbi_load("../Assets/Pictures/test.png", &width, &height, &nrChannels,0 );//missing something?
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,data);//missing something?
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			BE_ERROR("Failed to load a picture from the file");
		}		

		stbi_image_free(data);

		//leave???
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		// glDeleteTextures to delete watch ~1:08 on 11/27
		while (mShouldContinue)
		{
			OnUpdate();

			glClearColor(0.3f, 0.2f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			shader.Bind();

			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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
	/*template<typename T>
	void BackSpaceApp<typename T>::Draw(int x, int y, Picture& pic)
	 {
		mRenderer.Draw(100,200,pic)
	}*/

}