#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

#include "GameTime.h"
#include "Renderer.h"
#include "ShaderProgram.h"
#include "Input.h"
#include "Console.h"
#include "ObjectManager.h"


class Application
{		
	public:
		int Run(const char* windowName);

	protected:
		GLFWwindow* window;
		GameTime gameTime;
		Input input;
		Console console;
		Renderer renderer;
		ObjectManager objectManager;

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Shutdown() = 0;


};