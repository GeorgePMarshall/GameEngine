#include "Object.h"



Object::Object()
{


}


Object::~Object()
{
}

void Object::SetMesh(Mesh* mesh)
{
	this->mesh = mesh;
}


void Object::Update()
{
	transform.Update();
}


void Object::Draw(const Camera &camera)
{
	if (mesh != nullptr)
	{
		mesh->Draw(transform, camera);
	}
}
