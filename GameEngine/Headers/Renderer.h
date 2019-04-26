#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <map>

#include "ShaderProgram.h"
#include "Mesh.h"
#include "Geometry.h"

class Renderer
{
	private: 
		ShaderProgram geomShader;

		std::map<const char*, ShaderProgram*>shaders;
		std::map<const char*, Mesh*>meshes;

	public:

		Camera mainCamera;
		

		~Renderer();

		void Initialize();

		void Draw();

		//Creates some geometry and adds it to the mesh list
		//Renderer will clean up on shutdown
		Mesh* CreateGeom(const char* name, Geometry* mesh);
		Mesh* GetGeom(const char* name);



};

