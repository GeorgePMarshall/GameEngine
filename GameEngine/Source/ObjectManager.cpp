#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
	for (Object* obj : objects)
	{
		delete obj;
	}
}

void ObjectManager::Update()
{
	for (Object* obj : objects)
	{
		obj->Update();
	}
}

void ObjectManager::Draw(const Camera &camera)
{
	for (Object* obj : objects)
	{
		obj->Draw(camera);
	}
}


Object* ObjectManager::CreateObject(Object* object)
{
	objects.push_back(object);
	return object;
}
