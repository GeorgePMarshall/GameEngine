#include "Geometry.h"




Geometry::~Geometry()
{
}

void Geometry::Initialize(ShaderProgram* shader, glm::vec4 colour)
{
	SetShaderProgram(shader);
	CreateBuffers();
	SetColour(colour);
}


void Geometry::SetColour(glm::vec4 colour)
{
	this->colour = colour;
}


void Geometry::Draw(glm::mat4 transform)
{
	shader->UseShader();
	shader->SetMat4("projectionView", glm::identity<glm::mat4>());
	shader->SetMat4("transform", transform);
	shader->SetVec4("colour", colour);

	glBindVertexArray(vertexArray);

	glDrawElements(GL_TRIANGLES, indiciesSize, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);

}




//TRIANGLE//

void Triangle::CreateBuffers()
{
	verticiesSize = 12;
	indiciesSize = 3;

	

	//create VAO and VBO
	glGenVertexArrays(1, &vertexArray);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &elementBuffer);
	
	//bind VAO
	glBindVertexArray(vertexArray);

	//Buffer triangle data
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Buffer triangle indicies
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// enable attrib 0, it has 4 floats, dont normalize, stride of 4 floats, no offset
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	//unbind 
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


}


//SQUARE//

void Square::CreateBuffers()
{
	verticiesSize = 16;
	indiciesSize = 6;

	//create VAO and VBO and EBO
	glGenVertexArrays(1, &vertexArray);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &elementBuffer);

	//bind VAO
	glBindVertexArray(vertexArray);

	//Buffer square verticies
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Buffer square indicies
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// enable attrib 0, it has 4 floats, dont normalize, stride of 4 floats, no offset
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	//unbind 
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}


