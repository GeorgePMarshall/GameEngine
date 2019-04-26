#include "Mesh.h"



Mesh::~Mesh()
{
	if (vertexArray != 0)
		glDeleteVertexArrays(1, &vertexArray);

	if (vertexBuffer != 0)
		glDeleteBuffers(1, &vertexBuffer);

	if (elementBuffer != 0)
		glDeleteBuffers(1, &elementBuffer);
}

void Mesh::SetShaderProgram(ShaderProgram* shader)
{
	this->shader = shader;
}


