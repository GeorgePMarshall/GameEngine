#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/norm.hpp>

#include "Camera.h"
#include "GameTime.h"
#include "Input.h"

class FlyCamera : public Camera
{
	private:
		GLfloat speed = 5.0f; 
		GLfloat sprintSpeed = 10.0f;
		GLfloat rotateSpeed = 4.0f;
		glm::vec2 mouseOffset;
		glm::vec2 oldMousePos;
		
		GLboolean isSprinting = false;
		GLboolean useMouseInput = false;

		void CalculateRotation(GameTime &time, Input &input);

	public:		
		void Update(GameTime &gameTime, Input &input);
		void ToggleMouseInput(GLFWwindow* window);
};

