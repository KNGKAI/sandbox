#include "mesh.h"
#include "renderer.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures) : vertices(vertices), indices(indices), textures(textures)
{
	setupMesh();
}

void Mesh::Draw(Shader shader)
{
	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;
	unsigned int normalNr = 1;
	unsigned int heightNr = 1;
	unsigned int count = 0;

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		string number;
		string name = textures[i].type;
		
		count++;
		GL(glActiveTexture(GL_TEXTURE0 + i));
		if (name == DIFFUSE_TEXTURE) { number = std::to_string(diffuseNr++); }
		else if (name == SPECULAR_TEXTURE) { number = std::to_string(specularNr++); }
		else if (name == NORMAL_TEXTURE) { number = std::to_string(normalNr++); }
		else if (name == HEIGHT_TEXTURE) { number = std::to_string(heightNr++); }
		GL(glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i));
		GL(glBindTexture(GL_TEXTURE_2D, textures[i].id));
	}
	if (diffuseNr == 1)
	{
		GL(glActiveTexture(GL_TEXTURE0 + count));
		GL(glUniform1i(glGetUniformLocation(shader.ID, ((string)DIFFUSE_TEXTURE + "1").c_str()), count));
		GL(glBindTexture(GL_TEXTURE_2D, Renderer::defaultTexture()->id));
		count++;
	}
	if (specularNr == 1)
	{
		GL(glActiveTexture(GL_TEXTURE0 + count));
		GL(glUniform1i(glGetUniformLocation(shader.ID, ((string)SPECULAR_TEXTURE + "1").c_str()), count));
		GL(glBindTexture(GL_TEXTURE_2D, Renderer::defaultTexture()->id));
		count++;
	}
	if (normalNr == 1)
	{
		GL(glActiveTexture(GL_TEXTURE0 + count));
		GL(glUniform1i(glGetUniformLocation(shader.ID, ((string)NORMAL_TEXTURE + "1").c_str()), count));
		GL(glBindTexture(GL_TEXTURE_2D, Renderer::defaultTexture()->id));
		count++;
	}
	if (heightNr == 1)
	{
		GL(glActiveTexture(GL_TEXTURE0 + count));
		GL(glUniform1i(glGetUniformLocation(shader.ID, ((string)HEIGHT_TEXTURE + "1").c_str()), count));
		GL(glBindTexture(GL_TEXTURE_2D, Renderer::defaultTexture()->id));
		count++;
	}
	GL(glBindVertexArray(VAO));
	GL(glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0));
	GL(glBindVertexArray(0));
	GL(glActiveTexture(GL_TEXTURE0));
}

void Mesh::setupMesh()
{
	// create buffers/arrays
	GL(glGenVertexArrays(1, &VAO));
 	GL(glGenBuffers(1, &VBO));
	GL(glGenBuffers(1, &EBO));

	GL(glBindVertexArray(VAO));
	// load data into vertex buffers
	GL(glBindBuffer(GL_ARRAY_BUFFER, VBO));
	// A great thing about structs is that their memory layout is sequential for all its items.
	// The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
	// again translates to 3/2 floats which translates to a byte array.
	GL(glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW));

	GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO));
	GL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW));

	// set the vertex attribute pointers
	// vertex Positions
	GL(glEnableVertexAttribArray(0));
	GL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0));
	// vertex normals
	GL(glEnableVertexAttribArray(1));
	GL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal)));
	// vertex texture coords
	GL(glEnableVertexAttribArray(2));
	GL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords)));
	// vertex tangent
	GL(glEnableVertexAttribArray(3));
	GL(glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent)));
	// vertex bitangent
	GL(glEnableVertexAttribArray(4));
	GL(glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent)));

	GL(glBindVertexArray(0);)
}

