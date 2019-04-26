#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

#include "Renderer.h"
#include "ShaderProgram.h"
#include "Input.h"
#include "Console.h"
#include "ObjectManager.h"
#include "Camera.h"


class Application
{
	private:
		GLFWwindow* window;
		
	public:
		int Run(const char* windowName);

	protected:
		Input input;
		Console console;

		Renderer renderer;

		ObjectManager objectManager;


		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Shutdown() = 0;


};