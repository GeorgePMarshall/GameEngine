#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <iostream>
#include <sstream>

struct Key
{
	//numbers
	static const GLint zero = GLFW_KEY_0;
	static const GLint one = GLFW_KEY_1;
	static const GLint two = GLFW_KEY_2;
	static const GLint three = GLFW_KEY_3;
	static const GLint four = GLFW_KEY_4;
	static const GLint five = GLFW_KEY_5;
	static const GLint six = GLFW_KEY_6;
	static const GLint seven = GLFW_KEY_7;
	static const GLint eight = GLFW_KEY_8;
	static const GLint nine = GLFW_KEY_9;

	//alphabet
	static const GLint a = GLFW_KEY_A;
	static const GLint b = GLFW_KEY_B;
	static const GLint c = GLFW_KEY_C;
	static const GLint d = GLFW_KEY_D;
	static const GLint e = GLFW_KEY_E;
	static const GLint f = GLFW_KEY_F;
	static const GLint g = GLFW_KEY_G;
	static const GLint h = GLFW_KEY_H;
	static const GLint i = GLFW_KEY_I;
	static const GLint j = GLFW_KEY_J;
	static const GLint k = GLFW_KEY_K;
	static const GLint l = GLFW_KEY_L;
	static const GLint m = GLFW_KEY_M;
	static const GLint n = GLFW_KEY_N;
	static const GLint o = GLFW_KEY_O;
	static const GLint p = GLFW_KEY_P;
	static const GLint q = GLFW_KEY_Q;
	static const GLint r = GLFW_KEY_R;
	static const GLint s = GLFW_KEY_S;
	static const GLint t = GLFW_KEY_T;
	static const GLint u = GLFW_KEY_U;
	static const GLint v = GLFW_KEY_V;
	static const GLint w = GLFW_KEY_W;
	static const GLint x = GLFW_KEY_X;
	static const GLint y = GLFW_KEY_Y;
	static const GLint z = GLFW_KEY_Z;

	//otherKeys
	static const GLint space = GLFW_KEY_SPACE;
	static const GLint apostrophe = GLFW_KEY_APOSTROPHE;
	static const GLint comma = GLFW_KEY_COMMA;
	static const GLint minus = GLFW_KEY_MINUS;
	static const GLint period = GLFW_KEY_PERIOD;
	static const GLint slash = GLFW_KEY_SLASH;
	static const GLint leftBracket = GLFW_KEY_LEFT_BRACKET;
	static const GLint rightBracket = GLFW_KEY_RIGHT_BRACKET;
	static const GLint backslash = GLFW_KEY_BACKSLASH;
	static const GLint grave = GLFW_KEY_GRAVE_ACCENT;
	static const GLint semicolon = GLFW_KEY_SEMICOLON;
	static const GLint equal = GLFW_KEY_EQUAL;
	static const GLint escape = GLFW_KEY_ESCAPE;
	static const GLint enter = GLFW_KEY_ENTER;
	static const GLint tab = GLFW_KEY_TAB;
	static const GLint backspace = GLFW_KEY_BACKSPACE;
	static const GLint insert = GLFW_KEY_INSERT;
	static const GLint deleteKey = GLFW_KEY_DELETE;
	static const GLint pageUp = GLFW_KEY_PAGE_UP;
	static const GLint pageDown = GLFW_KEY_PAGE_DOWN;
	static const GLint home = GLFW_KEY_HOME;
	static const GLint end = GLFW_KEY_END;
	static const GLint capsLock = GLFW_KEY_CAPS_LOCK;
	static const GLint scrollLock = GLFW_KEY_SCROLL_LOCK;
	static const GLint numLock = GLFW_KEY_NUM_LOCK;
	static const GLint printScreen = GLFW_KEY_PRINT_SCREEN;
	static const GLint pause = GLFW_KEY_PAUSE;

	//arrow keys
	static const GLint right = GLFW_KEY_RIGHT;
	static const GLint left = GLFW_KEY_LEFT;
	static const GLint down = GLFW_KEY_DOWN;
	static const GLint up = GLFW_KEY_UP;

	//function keys
	static const GLint f1 = GLFW_KEY_F1;
	static const GLint f2 = GLFW_KEY_F2;
	static const GLint f3 = GLFW_KEY_F3;
	static const GLint f4 = GLFW_KEY_F4;
	static const GLint f5 = GLFW_KEY_F5;
	static const GLint f6 = GLFW_KEY_F6;
	static const GLint f7 = GLFW_KEY_F7;
	static const GLint f8 = GLFW_KEY_F8;
	static const GLint f9 = GLFW_KEY_F9;
	static const GLint f10 = GLFW_KEY_F10;
	static const GLint f11 = GLFW_KEY_F11;
	static const GLint f12 = GLFW_KEY_F12;

	//numpad
	static const GLint numPadZero = GLFW_KEY_KP_0;
	static const GLint numPadOne = GLFW_KEY_KP_1;
	static const GLint numPadTwo = GLFW_KEY_KP_2;
	static const GLint numPadThree = GLFW_KEY_KP_3;
	static const GLint numPadFour = GLFW_KEY_KP_4;
	static const GLint numPadFive = GLFW_KEY_KP_5;
	static const GLint numPadSix = GLFW_KEY_KP_6;
	static const GLint numPadSeven = GLFW_KEY_KP_7;
	static const GLint numPadEight = GLFW_KEY_KP_8;
	static const GLint numPadNine = GLFW_KEY_KP_9;
	static const GLint numPadPeriod = GLFW_KEY_KP_DECIMAL;
	static const GLint numPadDivide = GLFW_KEY_KP_DIVIDE;
	static const GLint numPadMultiply = GLFW_KEY_KP_MULTIPLY;
	static const GLint numPadSubtract = GLFW_KEY_KP_SUBTRACT;
	static const GLint numPadAdd = GLFW_KEY_KP_ADD;
	static const GLint numPadEqual = GLFW_KEY_KP_EQUAL;

	//modifier keys
	static const GLint leftShift = GLFW_KEY_LEFT_SHIFT;
	static const GLint leftControl = GLFW_KEY_LEFT_CONTROL;
	static const GLint leftAlt = GLFW_KEY_LEFT_ALT;
	static const GLint rightShift = GLFW_KEY_RIGHT_SHIFT;
	static const GLint RightControl = GLFW_KEY_RIGHT_CONTROL;
	static const GLint rightAlt = GLFW_KEY_RIGHT_ALT;
	static const GLint menu = GLFW_KEY_MENU;
};

struct MouseButton
{
	static const GLint left = GLFW_MOUSE_BUTTON_1;
	static const GLint right = GLFW_MOUSE_BUTTON_2;
	static const GLint middle = GLFW_MOUSE_BUTTON_3;
	static const GLint back = GLFW_MOUSE_BUTTON_4;
	static const GLint forward = GLFW_MOUSE_BUTTON_5;
};

//for unique rebindable Buttons
struct Button
{
	GLint console = Key::grave;

	GLint forwards = Key::w;
	GLint backwards = Key::s;
	GLint left = Key::a;
	GLint right = Key::d;
	GLint up = Key::space;
	GLint down = Key::leftControl;
	GLint sprint = Key::leftShift;
};

class Input
{
	private:
		GLFWwindow* window;
	
		GLboolean curKeyState[1024];
		GLboolean prevKeyState[1024];

		GLboolean curMouseButtonState[10];
		GLboolean prevMouseButtonState[10];
	
		glm::vec2 mousePosition;
	
		std::string textInputBuffer;

		//keyboard callbacks
		static void StaticKeyCallback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mods);
		void KeyCallback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mode);

		//text callbacks
		static void StaticCharCallback(GLFWwindow* window, GLuint character);
		void CharCallback(GLFWwindow* window, GLuint character);
	
		//Mouse Button callbacks
		static void StaticMouseButtonCallBack(GLFWwindow* window, GLint button, GLint action, GLint mods);
		void MouseButtonCallBack(GLFWwindow* window, GLint button, GLint action, GLint mods);

		//Mouse pos callbacks
		static void StaticMousePosCallBack(GLFWwindow* window, GLdouble xPos, GLdouble yPos);
		void MousePosCallBack(GLFWwindow* window, GLdouble xPos, GLdouble yPos);
	
	public:

		Button button;

		//setup callbacks and keystates !REQUIRED before use
		void Initialize(GLFWwindow* window);
		//run after main update
		void LateUpdate();
	
		///KEYBOARD///
		//returns true if key is pressed
		bool GetKey(GLint key);
		//returns true only on the frame the key is pressed
		bool GetKeyDown(GLint key);
		//returns true only on the frame the key is released
		bool GetKeyUp(GLint key);
		//Returns a string with all the characters entered since last frame
		const std::string GetTextInput();

		
		///MOUSE///
		//returns true if button is pressed
		bool GetMouseButton(GLint button);
		//returns true only on the frame the button is pressed
		bool GetMouseButtonDown(GLint button);
		//returns true only on the frame the button is released
		bool GetMouseButtonUp(GLint button);

		//returns the mouse position in screen space
		glm::vec2 GetMousePosition();
		//sets the mouse position
		void SetMousePosition(glm::vec2 position);
	

};




