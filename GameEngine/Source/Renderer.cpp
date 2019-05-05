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
	float ratio = 16.f / 9.f;
	//mainCamera.SetOrthographic(-ratio, ratio, -1, 1);

	geomShader.CreateShaderProgram("BasicGeometry.vert", "BasicGeometry.frag");
}

void Renderer::Update(GameTime &gameTime, Input &input)
{
	mainCamera.Update(gameTime, input);
}

void Renderer::Draw()
{
	
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


