#include "TestGame.h"

#include <Object.h>

void TestGame::Initialize()
{
	renderer.CreateGeom("triangle", new Triangle());
	renderer.CreateGeom("square", new Square());

	obj = objectManager.CreateObject(new Object());
	obj->SetMesh(renderer.GetGeom("square"));
}

void TestGame::Update()
{
	if (input.GetKey(Key::t))
	{
		obj->Translate(glm::vec3(0.001f));
	}

	if (input.GetKey(Key::y))
	{
		static int i;
		//std::cout << "scale" << i++ << std::endl;
		obj->Scale(glm::vec3(1.0001f));
	}

	if (input.GetKey(Key::u))
	{
		obj->Rotate(0.1f, glm::vec3(0, 0, 1.0f));
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
