#include "Geometry.h"




Geometry::~Geometry()
{
	if (vertices != nullptr)
		delete vertices;

	if (indices != nullptr)
		delete indices;
}

void Geometry::Initialize(ShaderProgram* shader, glm::vec4 colour)
{
	SetShaderProgram(shader);
	GenerateMesh();
	CreateBuffers();
	SetColour(colour);
}


void Geometry::SetColour(glm::vec4 colour)
{
	this->colour = colour;
}


void Geometry::Draw(Transform &transform, const Camera &camera)
{
	shader->UseShader();
	shader->SetMat4("projectionView", camera.GetProjectionViewTransform());
	shader->SetMat4("transform", transform.GetTransform());
	shader->SetVec4("colour", colour);

	glBindVertexArray(vertexArray);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawElements(GL_TRIANGLES, indiciesSize, GL_UNSIGNED_INT, 0);
	shader->SetVec4("colour", glm::vec4(0));
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, indiciesSize, GL_UNSIGNED_INT, 0);


	glBindVertexArray(0);

}

void Geometry::CreateBuffers()
{
	//create VAO and VBO
	glGenVertexArrays(1, &vertexArray);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &elementBuffer);
	
	//bind VAO
	glBindVertexArray(vertexArray);

	//Buffer triangle data
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * verticiesSize, vertices, GL_STATIC_DRAW);

	//Buffer triangle indicies
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indiciesSize, indices, GL_STATIC_DRAW);

	// enable attrib 0, it has 4 floats, dont normalize, stride of 4 floats, no offset
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	//unbind 
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


}

//vertices = new GLfloat[verticiesSize]
//{
//   -0.5f, -0.5f, 0.0f, 1.0f,	//bottom left
//	0.5f, -0.5f, 0.0f, 1.0f,	//bottom right
//	0.0f,  0.5f, 0.0f, 1.0f		//top middle
//};

//TRIANGLE//
void Triangle::GenerateMesh()
{
	verticiesSize = 12;
	indiciesSize = 3;
	
	
	vertices = new GLfloat[verticiesSize]
	{
	   -0.866f, -0.5f, 0.0f, 1.0f,	//bottom left
		0.866f, -0.5f, 0.0f, 1.0f,	//bottom right
	   -0.000f,  1.0f, 0.0f, 1.0f	//top middle
	};

	indices = new GLuint[indiciesSize]
	{
		0, 1, 2
	};
}


//SQUARE//
void Square::GenerateMesh()
{
	verticiesSize = 16;
	indiciesSize = 6;
	
	
	vertices = new GLfloat[verticiesSize]
	{
		 0.5f,  0.5f, 0.0f, 1.0f,	// top right
		 0.5f, -0.5f, 0.0f, 1.0f,	// bottom right
		-0.5f, -0.5f, 0.0f, 1.0f,	// bottom left
		-0.5f,  0.5f, 0.0f, 1.0f	// top left 
	};

	indices = new GLuint[indiciesSize]
	{
		0, 3, 1,   // first triangle
		1, 3, 2    // second triangle
	};
}

void Cube::GenerateMesh()
{
	verticiesSize = 32;
	indiciesSize = 36;


	vertices = new GLfloat[verticiesSize]
	{
		//front
		-0.5f, -0.5f, 0.5f, 1.0f,	
		 0.5f, -0.5f, 0.5f, 1.0f,	
		 0.5f,  0.5f, 0.5f, 1.0f,	
		-0.5f,  0.5f, 0.5f, 1.0f,	

		//back
		-0.5f, -0.5f, -0.5f, 1.0f,	
		 0.5f, -0.5f, -0.5f, 1.0f,	
		 0.5f,  0.5f, -0.5f, 1.0f,	
		-0.5f,  0.5f, -0.5f, 1.0f	
	};

	indices = new GLuint[indiciesSize]
	{
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};
}