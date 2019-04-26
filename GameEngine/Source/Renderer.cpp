#include "Renderer.h"

Renderer::~Renderer()
{
	for (auto const& mesh : meshes)
	{
		delete mesh.second;
	}
}

void Renderer::Initialize()
{
	geomShader.CreateShaderProgram("BasicGeometry.vert", "BasicGeometry.frag");
}


Mesh* Renderer::CreateGeom(const char* name, Geometry* mesh)
{
	//check if name used more than once
	assert(meshes.count(name) == 0);

	mesh->Initialize(&geomShader);

	meshes[name] = mesh;
	return mesh;

}

Mesh* Renderer::GetGeom(const char* name)
{
	return meshes[name];
}

void Renderer::Draw()
{
	
}