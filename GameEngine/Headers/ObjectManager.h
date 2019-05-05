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
	void Draw(const Camera &camera);

	Object* CreateObject(Object* object);
};

