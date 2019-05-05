#include "FlyCamera.h"

void FlyCamera::Update(GameTime &gameTime, Input &input)
{

	if (input.GetKey(input.button.sprint))
		isSprinting = true;
	else
		isSprinting = false;



	if(input.GetKey(input.button.forwards))
		transform.Translate(transform.Backward() * ((isSprinting) ? sprintSpeed : speed) * gameTime.DeltaTime());

	if(input.GetKey(input.button.backwards))
		transform.Translate(transform.Forward() * ((isSprinting) ? sprintSpeed : speed) * gameTime.DeltaTime());

	if(input.GetKey(input.button.left))
		transform.Translate(transform.Left() * ((isSprinting) ? sprintSpeed : speed) * gameTime.DeltaTime());

	if(input.GetKey(input.button.right))
		transform.Translate(transform.Right() * ((isSprinting) ? sprintSpeed : speed) * gameTime.DeltaTime());

	if (input.GetKey(input.button.up))
		transform.Translate(transform.Up() * ((isSprinting) ? sprintSpeed : speed) * gameTime.DeltaTime());

	if (input.GetKey(input.button.down))
		transform.Translate(transform.Down() * ((isSprinting) ? sprintSpeed : speed) * gameTime.DeltaTime());
	
	
	CalculateRotation(gameTime, input);

	UpdateProjectionViewTransform();
}

void FlyCamera::CalculateRotation(GameTime &gameTime, Input &input)
{
	mouseOffset = input.GetMousePosition() - oldMousePos;
	oldMousePos = input.GetMousePosition();

	if (glm::length2(mouseOffset) == 0) return;

	if (mouseOffset.y != 0)
	{
		transform.Rotate( -mouseOffset.y * rotateSpeed * gameTime.DeltaTime(), glm::vec3(1, 0, 0));
	}

	if (mouseOffset.x != 0)
	{
		transform.Rotate(-mouseOffset.x * rotateSpeed * gameTime.DeltaTime(), glm::vec3(viewTransform[1]));
	}

}

void FlyCamera::ToggleMouseInput(GLFWwindow* window)
{
	useMouseInput = !useMouseInput;
	
	
	if (useMouseInput)
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	else
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}
