#include "Camera.h"


void Camera::UpdateProjectionViewTransform()
{
	viewTransform = glm::inverse(transform.GetTransform());
	projectionViewTransform = projectionTransform * viewTransform;
}

void Camera::SetPerspective(GLfloat FOV, GLfloat aspectRatio, GLfloat nearPlane, GLfloat farPlane)
{
	projectionTransform = glm::perspective(glm::radians(FOV), aspectRatio, nearPlane, farPlane);
	UpdateProjectionViewTransform();
}
void Camera::SetOrthographic(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat nearPlane, GLfloat farPlane)
{
	projectionTransform = glm::ortho(left, right, bottom, top, nearPlane, farPlane);
	UpdateProjectionViewTransform();
}
void Camera::SetPosition(glm::vec3 position)
{
	transform.SetPosition(position);
	UpdateProjectionViewTransform();
}

void Camera::LookAt(glm::vec3 target)
{
	transform.LookAt(target);
	UpdateProjectionViewTransform();
}

const Transform& Camera::GetWorldTransform() const
{
	return transform;
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
