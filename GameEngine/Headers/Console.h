#pragma once

#include <string>

#include "Input.h"

class Console
{
	private:

		std::string inputBuffer;

	public:
		Console();
		~Console();


		void Update(Input& input);
		void Draw();

};

