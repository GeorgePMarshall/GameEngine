#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

class GameTime
{
	private:	
		GLfloat curTime = 0;
		GLfloat prevTime = 0;
		GLfloat deltaTime = 0;

	public:
		GLfloat physicsTimeStep = 0.16f;
		
		void Update();

		GLfloat CurTime();
		GLfloat DeltaTime();
};

