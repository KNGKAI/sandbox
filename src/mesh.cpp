#include "mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	// now that we have all the required data, set the vertex buffers and its attribute pointers.
	setupMesh();
}

// render the mesh
void Mesh::Draw(Shader shader)
{
	// bind appropriate textures
	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;
	unsigned int normalNr = 1;
	unsigned int heightNr = 1;
	for (unsigned int i = 0; i < textures.size(); i++)
	{
		GL(glActiveTexture(GL_TEXTURE0 + i)); // active proper texture unit before binding
		// retrieve texture number (the N in diffuse_textureN)
		string number;
		string name = textures[i].type;
		if (name == "texture_diffuse")
			number = std::to_string(diffuseNr++);
		else if (name == "texture_specular")
			number = std::to_string(specularNr++); // transfer unsigned int to stream
		else if (name == "texture_normal")
			number = std::to_string(normalNr++); // transfer unsigned int to stream
		else if (name == "texture_height")
			number = std::to_string(heightNr++); // transfer unsigned int to stream

													// now set the sampler to the correct texture unit
		GL(glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i));
		// and finally bind the texture
		GL(glBindTexture(GL_TEXTURE_2D, textures[i].id));
	}

	// draw mesh
	GL(glBindVertexArray(VAO));
	GL(glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0));
	GL(glBindVertexArray(0));

	// always good practice to set everything back to defaults once configured.
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

