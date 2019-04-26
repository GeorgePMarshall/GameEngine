#pragma once

#include <Application.h>
#include <ShaderProgram.h>
#include <Geometry.h>



class TestGame : public Application
{
	private:
		Object* obj;	


	protected:
		void Initialize() override;
		void Update() override;
		void Draw() override;
		void Shutdown() override;
};

