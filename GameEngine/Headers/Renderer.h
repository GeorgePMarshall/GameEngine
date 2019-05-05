#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <map>

#include "GameTime.h"
#include "Input.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include "Geometry.h"
#include "Camera.h"
#include "FlyCamera.h"

class Renderer
{
	private: 
		ShaderProgram geomShader;

		std::map<const char*, ShaderProgram*>shaders;
		std::map<const char*, Mesh*>meshes;

	public:

		Camera mainCamera;
		FlyCamera mainFlyCamera;

		~Renderer();

		void Initialize();
		void Update(GameTime &gameTime, Input &input);
		void Draw();

		//Creates some geometry and adds it to the mesh list
		//Renderer will clean up on shutdown
		Mesh* CreateGeom(const char* name, Geometry* mesh);
		Mesh* GetGeom(const char* name);



};

