#ifndef MESH_H
#define MESH_H

#include "gl.h"
#include "shader.h"
#include "texture.h"
#include "vector.h"

struct Vertex {
	vec3 position;
	vec3 normal;
	vec2 texCoords;
	vec3 tangent;
	vec3 bitangent;
};

struct Bone
{
	string name;
	ivec3 IDs;
	vec3 Weights;
	mat4 offset;
};

class Mesh
{
public:
	Mesh() {}
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures, vector<Bone> bones);
	void Draw(Shader shader);

	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	vector<Bone> bones;
	unsigned int VAO;

private:
	unsigned int VBO;
	unsigned int EBO;

	void setupMesh();
};
#endif
