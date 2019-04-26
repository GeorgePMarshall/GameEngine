#include "Console.h"



Console::Console()
{
	

}

Console::~Console()
{
}


void Console::Update(Input& input)
{
	inputBuffer.append(input.GetTextInput());

	if (input.GetKeyDown(Key::backspace) && inputBuffer.size() > 0)
	{
		inputBuffer.pop_back();
	}

	//std::cout << inputBuffer << std::endl;
}

void Console::Draw()
{

	//to do text & basic geom rendering first before finishing this


}