#ifndef MESH_H
#define MESH_H

#include "gl.h"
#include "system.h"
#include "shader.h"
#include "texture.h"
#include "vector.h"
#include "vertex.h"

class Mesh
{
public:
	Mesh() {}
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	void Draw(Shader shader);

	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	unsigned int VAO;

private:
	unsigned int VBO;
	unsigned int EBO;

	void setupMesh();
};
#endif
