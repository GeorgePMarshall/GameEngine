#pragma once

#include <Application.h>


class TestGame : public Application
{
	protected:
		void Initialize() override;
		void Update() override;
		void Draw() override;
		void Shutdown() override;
};

