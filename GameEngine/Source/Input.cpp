#include "Input.h"



void Input::Initialize(GLFWwindow* window)
{
	this->window = window;

	//Send reference to this instace though window so callback can call this class
	glfwSetWindowUserPointer(window, this);

	//setup calbacks to static functions that will call this class
	glfwSetKeyCallback(window, StaticKeyCallback);
	glfwSetCharCallback(window, StaticCharCallback);
	glfwSetCursorPosCallback(window, StaticMousePosCallBack);
	glfwSetMouseButtonCallback(window, StaticMouseButtonCallBack);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	//init all keystates
	for (int i = 0; i < 1024; i++)
	{
		curKeyState[i] = GLFW_RELEASE;
		prevKeyState[i] = GLFW_RELEASE;
	}

	textInputBuffer.reserve(512U);
}

void Input::LateUpdate()
{
	textInputBuffer.clear();
}

//key callbacks
void Input::StaticKeyCallback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mods)
{
	//call input member function using pointer stored in window
	static_cast<Input*>(glfwGetWindowUserPointer(window))->KeyCallback(window, key, scancode, action, mods);
}
void Input::KeyCallback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mods)
{
	curKeyState[key] = action;
	
	////REMOVE REPEAT FOR NOW   FIX LATER (maybe?)/////
	if (action == GLFW_REPEAT)
		curKeyState[key] = GLFW_PRESS;
	////REMOVE REPEAT FOR NOW   FIX LATER (maybe?)/////

	if (action == GLFW_RELEASE)
		prevKeyState[key] = GLFW_PRESS;
	
}

//Text callbacks
void Input::StaticCharCallback(GLFWwindow* window, GLuint character)
{
	static_cast<Input*>(glfwGetWindowUserPointer(window))->CharCallback(window, character);
}
void Input::CharCallback(GLFWwindow* window, GLuint character)
{
	textInputBuffer += (char)character;
}

//mouse Callbacks
void Input::StaticMouseButtonCallBack(GLFWwindow* window, GLint button, GLint action, GLint mods)
{
	//call input member function using pointer stored in window
	static_cast<Input*>(glfwGetWindowUserPointer(window))->MouseButtonCallBack(window, button, action, mods);
}
void Input::MouseButtonCallBack(GLFWwindow* window, GLint button, GLint action, GLint mods)
{
	curMouseButtonState[button] = action;

	if (action == GLFW_RELEASE)
		prevMouseButtonState[button] = GLFW_PRESS;
}

void Input::StaticMousePosCallBack(GLFWwindow* window, GLdouble xPos, GLdouble yPos)
{
	//call input member function using pointer stored in window
	static_cast<Input*>(glfwGetWindowUserPointer(window))->MousePosCallBack(window, xPos, yPos);
}
void Input::MousePosCallBack(GLFWwindow* window, GLdouble xPos, GLdouble yPos)
{
	mousePosition.x = (float)xPos;
	mousePosition.y = (float)yPos;
}


//keyboard
bool Input::GetKey(GLint key)
{
	if (curKeyState[key] == GLFW_PRESS)
		return true;
	return false;
}

bool Input::GetKeyDown(GLint key)
{
	//if key not pressed set old state to not pressed
	if (curKeyState[key] == GLFW_RELEASE)
	{
		prevKeyState[key] = GLFW_RELEASE;
		return false;
	}

	//if key is pressed and was not presed last frame
	if (curKeyState[key] == GLFW_PRESS && prevKeyState[key] == GLFW_RELEASE)
	{
		prevKeyState[key] = GLFW_PRESS;
		return true;
	}

	return false;
}

bool Input::GetKeyUp(GLint key)
{
	if (curKeyState[key] == GLFW_RELEASE && prevKeyState[key] == GLFW_PRESS)
	{
		prevKeyState[key] = GLFW_RELEASE;
		return true;
	}
	return false;
}

const std::string Input::GetTextInput()
{
	return textInputBuffer;
}

//Mouse buttons
bool Input::GetMouseButton(GLint button)
{
	if (curMouseButtonState[button] == GLFW_PRESS)
		return true;
	return false;
}

bool Input::GetMouseButtonDown(GLint button)
{
	//if key not pressed set old state to not pressed
	if (curMouseButtonState[button] == GLFW_RELEASE)
	{
		prevMouseButtonState[button] = GLFW_RELEASE;
		return false;
	}

	//if key is pressed and was not presed last frame
	if (curMouseButtonState[button] == GLFW_PRESS && prevMouseButtonState[button] == GLFW_RELEASE)
	{
		prevMouseButtonState[button] = GLFW_PRESS;
		return true;
	}

	return false;
}

bool Input::GetMouseButtonUp(GLint button)
{
	if (curMouseButtonState[button] == GLFW_RELEASE && prevMouseButtonState[button] == GLFW_PRESS)
	{
		prevMouseButtonState[button] = GLFW_RELEASE;
		return true;
	}
	return false;
}



//mouse postion
glm::vec2 Input::GetMousePosition()
{
	return mousePosition;
}

void Input::SetMousePosition(glm::vec2 position)
{
	glfwSetCursorPos(window, position.x, position.y);
}