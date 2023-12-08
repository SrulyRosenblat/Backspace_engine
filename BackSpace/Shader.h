#pragma once

#include "pch.h"
#include "Utilities.h"
#include "ShaderImplementation.h"


namespace be 
{
	class BACKSPACE_API Shader
	{
		
	public:
		Shader(const std::string& vertixSFile, const std::string& fragmentSFILE);
		void Bind();
		void SetUniform2Ints(const std::string& uniformName, int val1, int val2);
		void SetUniform2Ints(const std::string&& uniformName, int val1, int val2);

	private:
		std::unique_ptr<ShaderImplementation> mImplementation;
	};
}