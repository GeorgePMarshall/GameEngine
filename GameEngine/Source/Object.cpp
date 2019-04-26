#include "Object.h"



Object::Object()
{
	transform = glm::identity<glm::mat4>();
	translation = glm::identity<glm::mat4>();
	scale = glm::identity<glm::mat4>();
	rotation = glm::identity<glm::mat4>();

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
	if (transformDirty)
	{
		UpdateTransform();
		transformDirty = false;
	}
}


void Object::Draw()
{
	if (mesh != nullptr)
	{
		mesh->Draw(transform);
	}
}

void Object::UpdateTransform()
{
	transform = translation * scale * rotation;
}

void Object::SetPosition(const glm::vec3 &value)
{
	translation = glm::translate(glm::identity<glm::mat4>(), value);
	transformDirty = true;
}

void Object::Translate(const glm::vec3 &value)
{
	translation = glm::translate(translation, value);
	transformDirty = true;
}

void Object::Scale(const glm::vec3 &scalar)
{
	scale = glm::scale(scale, scalar);
	transformDirty = true;
}

void Object::Rotate(GLfloat degrees, const glm::vec3 &axis)
{
	rotation = glm::rotate(rotation, glm::radians(degrees), axis);
	transformDirty = true;
}