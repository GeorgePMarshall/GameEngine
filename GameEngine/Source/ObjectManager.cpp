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

void ObjectManager::Draw()
{
	for (Object* obj : objects)
	{
		obj->Draw();
	}
}


Object* ObjectManager::CreateObject(Object* object)
{
	objects.push_back(object);
	return object;
}
