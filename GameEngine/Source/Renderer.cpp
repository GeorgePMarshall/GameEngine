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
	mainCamera.SetPerspective(90, 16.f / 9.f);
	mainFlyCamera.SetPerspective(90, 16.f / 9.f);
	//mainCamera.SetOrthographic(-8, 8, -4.5, 4.5);

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

void Renderer::Update(GameTime &gameTime, Input &input)
{
	mainFlyCamera.Update(gameTime, input);
}


void Renderer::Draw()
{
	
}