#pragma once

namespace be {
	class ShaderImplementation 
	{
	public:
		virtual void Bind() = 0;
		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) =0;
		virtual void SetUniform2Ints(const std::string&& uniformName, int val1, int val2) = 0;
		virtual ~ShaderImplementation() {};

	};
}