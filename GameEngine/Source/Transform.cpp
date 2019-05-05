#include "..\Headers\Transform.h"


Transform::Transform()
{
	transformMatrix = glm::identity<glm::mat4>();
	translation = glm::identity<glm::mat4>();
	scale = glm::identity<glm::mat4>();
	rotation = glm::identity<glm::mat4>();
}


void Transform::Update() 
{
	if (transformDirty)
	{
		transformMatrix = translation * scale * rotation;
		transformDirty = false;
	}
}

const glm::mat4& Transform::GetTransform()
{
	Update();
	return transformMatrix;
}

const glm::vec3 Transform::Right()
{
	Update();
	return transformMatrix[0];
}
const glm::vec3 Transform::Up()
{
	Update();
	return transformMatrix[1];
}
const glm::vec3 Transform::Forward()
{
	Update();
	return transformMatrix[2];
}

const glm::vec3 Transform::Left()
{
	Update();
	return -transformMatrix[0];
}
const glm::vec3 Transform::Down()
{
	Update();
	return -transformMatrix[1];
}
const glm::vec3 Transform::Backward()
{
	Update();
	return -transformMatrix[2];
}

void Transform::LookAt(const glm::vec3 &value)
{
	Update();
	transformMatrix = glm::lookAt(GetWorldPosition(), value, glm::vec3(0, 1, 0));
}


void Transform::SetPosition(const glm::vec3 &value) 
{
	translation = glm::translate(glm::identity<glm::mat4>(), value);
	transformDirty = true;
}

const glm::vec3 Transform::GetWorldPosition()
{
	Update();
	return transformMatrix[3];
}
const glm::vec3 Transform::GetLocalPosition()
{
	return translation[3];
}

void Transform::Translate(const glm::vec3 &value)
{
	translation = glm::translate(translation, value);
	transformDirty = true;
}
void Transform::Scale(const glm::vec3 &scalar)
{
	scale = glm::scale(scale, scalar);
	transformDirty = true;
}
void Transform::Rotate(GLfloat degrees, const glm::vec3 &axis)
{
	//rotation = glm::translate(rotation, glm::vec3(0.0f, -0.1f, 0.0f));
	rotation = glm::rotate(rotation, glm::radians(degrees), axis);
	//rotation = glm::translate(rotation, glm::vec3(0.0f, 0.1f, 0.0f));

	transformDirty = true;
}