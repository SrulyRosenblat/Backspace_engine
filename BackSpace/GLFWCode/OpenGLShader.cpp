#pragma once
# include "pch.h"

# include "glad/glad.h"
# include "GLFW/glfw3.h"

# include "OpenGLShader.h"

# include"../Utilities.h"

namespace be 
{
	OpenGLShader::OpenGLShader(const std::string& vertexSF, const std::string& fragmentSF)
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			BE_ERROR("failed to initilize glad");
			return;
		}
		std::string vertexString = ReadWholeFile(vertexSF);
		const char* vertexShaderSource = vertexString.c_str();
		std::string fragmentString{ ReadWholeFile(fragmentSF) };
		const char* fragmentShaderSource = fragmentString.c_str();
		std::cout << vertexShaderSource << std::endl;
		std::cout << fragmentShaderSource << std::endl;

		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) 
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			BE_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}


		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) 
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			BE_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog)
		}

		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);

		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			BE_ERROR("Linking FAILED with the messegea: " << infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	};

	OpenGLShader::OpenGLShader(std::string&& vertexSF,  std::string&& fragmentSF)
	{
		// delete later
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			BE_ERROR("failed to initilize glad");
			return;
		}
		// delete later

		std::string vertexString = ReadWholeFile(move(vertexSF));
		const char* vertexShaderSource = vertexString.c_str();
		std::string fragmentString{ ReadWholeFile(move(fragmentSF)) };
		const char* fragmentShaderSource = fragmentString.c_str();

		std::cout << vertexShaderSource << std::endl;
		std::cout << fragmentShaderSource << std::endl;


		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			BE_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}


		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			BE_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog)
		}

		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);

		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			BE_ERROR("Linking FAILED with the messegea: " << infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	}
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(mShaderProgram);
	}
	

	void OpenGLShader::Bind() 
	{
		glUseProgram(mShaderProgram);

	}
	void OpenGLShader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		glUseProgram(mShaderProgram);
		GLint location{ glGetUniformLocation(mShaderProgram,uniformName.c_str()) };
		glUniform2i(location, val1, val2);

	}

	void OpenGLShader::SetUniform2Ints(const std::string&& uniformName, int val1, int val2)
	{
		glUseProgram(mShaderProgram);
		GLint location{ glGetUniformLocation(mShaderProgram,uniformName.c_str()) };
		glUniform2i(location, val1, val2);

	}
	std::string OpenGLShader::ReadWholeFile(const std::string& fileName)
	{
		std::ifstream inputFile{ fileName };
		std::string result;
		std::string nextLine;

		while (inputFile)
		{
		
			std::getline(inputFile, nextLine);
			if (!inputFile)
				break;
			result += nextLine;
			result += "\n";
		}

		return result;

	}
	std::string OpenGLShader::ReadWholeFile(std::string&& fileName)
	{
		std::ifstream inputFile{ move(fileName) };
		std::string result;
		std::string nextLine;

		while (inputFile)
		{
			std::getline(inputFile, nextLine);
			if (!inputFile)
				break;
			result += nextLine;
			result += "\n";
		}

		return result;

	}
}
