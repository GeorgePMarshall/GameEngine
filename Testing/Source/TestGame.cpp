#include "TestGame.h"
#include <ShaderProgram.h>


void TestGame::Initialize()
{
	ShaderProgram shader("DefaultShader.vert", "DefaultShader.frag");


}

void TestGame::Update()
{



	if (input.GetKeyDown(input.button.console))
	{
		std::cout << "console";
	}
	
	
	if (input.GetMouseButton(MouseButton::right))
	{
		std::cout << "RMB" << std::endl;
		
	}

	std::cout << input.GetTextInput();

}

void TestGame::Draw()
{

}

void TestGame::Shutdown()
{

}
