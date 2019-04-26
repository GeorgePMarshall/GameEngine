#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/ext.hpp>


class Camera
{
	private:
		glm::mat4 worldTransform;
		glm::mat4 viewTransform;
		glm::mat4 projectionTransform;
		glm::mat4 projectionViewTransform;


		void UpdateProjectionViewTransform();


	public:
		Camera();
		~Camera();

		void LookAt(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp = glm::vec3(0, 1, 0));
		
		void SetPerspective(GLfloat FOV, GLfloat aspectRatio, GLfloat nearPlane = 0.1f, GLfloat farPlane = 1000.f);
		void SetOrthographic(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top);
		void SetPosition(glm::vec3 position);
		void SetWorldTransform(const glm::mat4& transform);
		
		glm::vec3 GetPosition() const;
		const glm::mat4& GetWorldTransform() const;
		const glm::mat4& GetViewTransform() const;
		const glm::mat4& GetProjectionTransform() const;
		const glm::mat4& GetProjectionViewTransform() const;

};

