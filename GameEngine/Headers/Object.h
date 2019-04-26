#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Mesh.h"

class Object
{
	private:
		glm::mat4 transform;
		glm::mat4 translation;
		glm::mat4 scale;
		glm::mat4 rotation;
		GLboolean transformDirty;

		Mesh* mesh;

		void UpdateTransform();

	public:
		Object();
		~Object();

		void SetMesh(Mesh* mesh);
		void Update();
		void Draw();

		void SetPosition(const glm::vec3 &value);
		void Translate(const glm::vec3 &value);
		void Scale(const glm::vec3 &scalar);
		void Rotate(GLfloat degrees,const glm::vec3 &axis);

};

