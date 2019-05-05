#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Transform.h"


class Camera
{
	protected:
		Transform transform;
		glm::mat4 viewTransform;
		glm::mat4 projectionTransform;
		glm::mat4 projectionViewTransform;


		void UpdateProjectionViewTransform();

	public:	
		void SetPerspective(GLfloat FOV, GLfloat aspectRatio, GLfloat nearPlane = 0.1f, GLfloat farPlane = 100.f);
		void SetOrthographic(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat nearPlane = 0.1f, GLfloat farPlane = 100.f);
		void SetPosition(glm::vec3 position);
		
		void LookAt(glm::vec3 target);
		
		const Transform& GetWorldTransform() const;
		const glm::mat4& GetViewTransform() const;
		const glm::mat4& GetProjectionTransform() const;
		const glm::mat4& GetProjectionViewTransform() const;

};

