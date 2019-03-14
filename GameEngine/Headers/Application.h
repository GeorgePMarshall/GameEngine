#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

#include "ShaderProgram.h"


class Application
{
	private:
		GLFWwindow* window;
		
	public:
		int Run(const char* windowName);

	protected:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Shutdown() = 0;


};