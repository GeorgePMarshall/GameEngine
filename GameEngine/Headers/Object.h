#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Transform.h"
#include "Mesh.h"

class Object
{
	private:
		Mesh* mesh;

	public:
		Transform transform;

		Object();
		~Object();

		void SetMesh(Mesh* mesh);
		void Update();
		void Draw(const Camera &camera);
};

