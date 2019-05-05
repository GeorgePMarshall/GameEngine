#include "TestGame.h"

#include <Object.h>

void TestGame::Initialize()
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	renderer.CreateGeom("triangle", new Triangle());
	renderer.CreateGeom("square", new Square());
	renderer.CreateGeom("cube", new Cube());


	obj = objectManager.CreateObject(new Object());
	obj->SetMesh(renderer.GetGeom("cube"));
	obj->transform.SetPosition(glm::vec3(0.0f, 0.0f, -3));

}

void TestGame::Update()
{
	if (input.GetKey(Key::t))
	{
		obj->transform.Translate(glm::vec3(0.001f));
	}

	if (input.GetKey(Key::y))
	{
		static int i;
		//std::cout << "scale" << i++ << std::endl;
		obj->transform.Scale(glm::vec3(1.01f));
	}

	if (input.GetKey(Key::u))
	{
		obj->transform.Rotate(0.1f, glm::vec3(0, 0, 1.0f));
	}



	if (input.GetKeyDown(input.button.console))
	{
		std::cout << "console";
	}
	
	
	if (input.GetMouseButton(MouseButton::right))
	{
		std::cout << "RMB" << std::endl;
		
	}

	//std::cout << input.GetTextInput();

}

void TestGame::Draw()
{

}

void TestGame::Shutdown()
{

}
