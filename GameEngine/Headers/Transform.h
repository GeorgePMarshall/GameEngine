#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>


class Transform
{
	private:
		glm::mat4 transformMatrix;
		glm::mat4 translation;
		glm::mat4 scale;
		glm::mat4 rotation;
	
		GLboolean transformDirty;

	public:
		Transform();

		void Update();

		const glm::mat4& GetTransform();

		const glm::vec3 Right();
		const glm::vec3 Up();
		const glm::vec3 Forward();

		const glm::vec3 Left();
		const glm::vec3 Down();
		const glm::vec3 Backward();

		void LookAt(const glm::vec3 &value);

		void SetPosition(const glm::vec3 &value);
		const glm::vec3 GetWorldPosition();
		const glm::vec3 GetLocalPosition();

		
		void Translate(const glm::vec3 &value);
		void Scale(const glm::vec3 &scalar);
		void Rotate(GLfloat degrees, const glm::vec3 &axis);


};

