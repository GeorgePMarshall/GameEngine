#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderProgram.h"

class Mesh
{
	private:

	protected:
		GLuint vertexArray = 0;
		GLuint vertexBuffer = 0;
		GLuint elementBuffer = 0;

		ShaderProgram* shader;


	public:
		~Mesh();

		virtual void CreateBuffers() = 0;
		void SetShaderProgram(ShaderProgram* shader);
		virtual void Draw(glm::mat4 transform) = 0;
};

