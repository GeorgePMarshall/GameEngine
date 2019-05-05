#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"

class Geometry : public Mesh
{
	protected:
		glm::vec4 colour;
		GLuint verticiesSize = 0;
		GLuint indiciesSize = 0;

	
	public:
		~Geometry();
	
		void Initialize(ShaderProgram* shader, glm::vec4 colour = glm::vec4(1));
		void SetColour(glm::vec4 colour);
		void Draw(Transform &transform, const Camera &camera);
	
};


class Triangle : public Geometry
{
	private:
		const GLfloat vertices[12] =
		{
		   -0.5f, -0.5f, 0.0f, 1.0f,	//bottom left
			0.5f, -0.5f, 0.0f, 1.0f,	//bottom right
			0.0f,  0.5f, 0.0f, 1.0f		//top middle
		};
	
		const GLuint indices[3] =
		{
			0, 1, 2 
		};
	
		void CreateBuffers();
	
};

class Square : public Geometry
{
	private:
		const GLfloat vertices[16] = 
		{
			 0.5f,  0.5f, 0.0f, 1.0f,	// top right
			 0.5f, -0.5f, 0.0f, 1.0f,	// bottom right
			-0.5f, -0.5f, 0.0f, 1.0f,	// bottom left
			-0.5f,  0.5f, 0.0f, 1.0f	// top left 
		};
	
		const GLuint indices[6] = 
		{  
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		};
	
		void CreateBuffers();
};

