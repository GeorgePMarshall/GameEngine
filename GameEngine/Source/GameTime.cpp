#include "GameTime.h"





void GameTime::Update()
{
	curTime = (float)glfwGetTime();
	deltaTime = curTime - prevTime;
	prevTime = curTime;
}

float GameTime::CurTime()
{
	return curTime;
}

float GameTime::DeltaTime()
{
	return deltaTime;
}


