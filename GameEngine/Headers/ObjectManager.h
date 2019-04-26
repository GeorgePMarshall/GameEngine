#pragma once

#include <vector>

#include "Object.h"

class ObjectManager
{
	std::vector<Object*> objects;




	public:
	ObjectManager();
	~ObjectManager();

	void Update();
	void Draw();

	Object* CreateObject(Object* object);
};

