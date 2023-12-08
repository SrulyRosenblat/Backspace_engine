#include "pch.h"
#include"Shader.h"
#include "GLFWCode/OpenGLShader.h"
namespace be {
	Shader::Shader(const std::string& vertixSFile, const std::string& fragmentSFILE)
	{
		
#ifdef BACKSPACE_MSCPP
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertixSFile,fragmentSFILE)};
#elif BACKSPACE_APPLE
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertixSFile,fragmentSFILE) };
#elif BACKSPACE_LINUX
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertixSFile,fragmentSFILE) };
#endif

	}
	void Shader::Bind()
	{
		mImplementation->Bind();
	}
	void Shader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(uniformName, val1, val2);
	}
	void Shader::SetUniform2Ints(const std::string&& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(move(uniformName), val1, val2);
	}
}
