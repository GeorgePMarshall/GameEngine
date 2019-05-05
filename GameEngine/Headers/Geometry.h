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

		GLfloat* vertices = nullptr;
		GLuint* indices = nullptr;

		void CreateBuffers();
		virtual void GenerateMesh() = 0;
	
	public:
		~Geometry();
	
		void Initialize(ShaderProgram* shader, glm::vec4 colour = glm::vec4(1));
		void SetColour(glm::vec4 colour);
		void Draw(Transform &transform, const Camera &camera);

	
};


class Triangle : public Geometry
{
	private:	
		void GenerateMesh();
	
};

class Square : public Geometry
{
	private:
		void GenerateMesh();

};

class Cube : public Geometry
{
	private:
		void GenerateMesh();

};

