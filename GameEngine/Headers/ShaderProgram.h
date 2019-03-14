#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


class ShaderProgram
{
	private:
		GLuint programID = 0;

		GLuint CreateShader(const char* path, GLenum shaderType);
		
		void LinkProgram(GLuint vertexShader);
		void LinkProgram(GLuint vertexShader, GLuint fragmentShader);
		void LinkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader);


	public:
		ShaderProgram(const char * vertexShaderPath, const char* fragmentShaderPath);
		ShaderProgram(const char * vertexShaderPath, const char* geometryShaderPath, const char* fragmentShaderPath);	
		ShaderProgram(const char * vertexShaderPath, const char** varyings = nullptr, GLuint amount = 0);  //varyings for recieving Shader Output
		~ShaderProgram();

		
		//call to make Shader Program active, remains active until another shader is made active 
		void UseShader();

		//Set values within shaders
		void SetInt(const char* name, GLint value);
		void SetFloat(const char* name, GLfloat value);
		void SetVec2(const char* name, const glm::vec2 &value);
		void SetVec3(const char* name, const glm::vec3 &value);
		void SetVec4(const char* name, const glm::vec4 &value);
		void SetMat4(const char* name, const glm::mat4 &value);
		void SetFloatArray(const char* name, const float* value, GLuint amount);



		


};

