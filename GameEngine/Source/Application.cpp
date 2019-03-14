#include "Application.h"


void ErrorCallback(int error, const char* description)
{
	std::cout << "GLFW Error: " << error << "  " << description << std::endl;
}

//resize frame buffer when window resizes
void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


int Application::Run(const char* windowName)
{

	//Initialize glfw
	if (!glfwInit())
	{
		std::cout << "Application Error:  Glfw Failed To Initialize" << std::endl;
		return -1;
	}
	
	//Create window
	window = glfwCreateWindow(1920, 1080, windowName, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "Application Error:  Glfw Failed To Create Window" << std::endl;
		return -2;
	}

	glfwMakeContextCurrent(window);

	//Initialize Glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		std::cout << "Application Error:  Glad failed to initialize" << std::endl;
		return -3;
	}


	//set opengl version and profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//set frame buffer to same dimensions as window
	int frameBufferWidth, frameBufferHeight;
	glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
	glViewport(0, 0, frameBufferWidth, frameBufferHeight);

	//set Callbacks
	glfwSetErrorCallback(ErrorCallback);
	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);

	Initialize();

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Update();
		Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	Shutdown();
	
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}



