#include "Camera.h"

Camera::Camera()
{
	worldTransform = glm::identity<glm::mat4>();


}

Camera::~Camera()
{

}



void Camera::UpdateProjectionViewTransform()
{
	viewTransform = glm::inverse(worldTransform);
	projectionViewTransform = projectionTransform * viewTransform;
}

void Camera::LookAt(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp)
{
	worldTransform = glm::inverse(glm::lookAt(position, target, worldUp));
	UpdateProjectionViewTransform();
}



void Camera::SetPerspective(GLfloat FOV, GLfloat aspectRatio, GLfloat nearPlane, GLfloat farPlane)
{
	projectionTransform = glm::perspective(FOV, aspectRatio, nearPlane, farPlane);
	UpdateProjectionViewTransform();
}
void Camera::SetOrthographic(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top)
{
	projectionTransform = glm::ortho(left, right, bottom, top);
	UpdateProjectionViewTransform();
}
void Camera::SetWorldTransform(const glm::mat4& transform)
{
	worldTransform = transform;
	UpdateProjectionViewTransform();
}
void Camera::SetPosition(glm::vec3 position)
{
	worldTransform[3] = glm::vec4(position, 1);
	UpdateProjectionViewTransform();
}


glm::vec3 Camera::GetPosition() const
{
	return worldTransform[3].xyz;
}
const glm::mat4& Camera::GetWorldTransform() const
{
	return worldTransform;
}
const glm::mat4& Camera::GetViewTransform() const
{
	return viewTransform;
}
const glm::mat4& Camera::GetProjectionTransform() const
{
	return projectionTransform;
}
const glm::mat4& Camera::GetProjectionViewTransform() const
{
	return projectionViewTransform;
}
