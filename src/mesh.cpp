#include "mesh.h"

Mesh::Mesh()
{
	this->renderType = RENDER_STANDARD;
	/*
	this->verticies.add(Vector3(-1, -1));
	this->verticies.add(Vector3(1, -1));
	this->verticies.add(Vector3(1, 1));
	this->verticies.add(Vector3(-1, 1));
	this->triangles.add(0);
	this->triangles.add(1);
	this->triangles.add(2);
	this->triangles.add(0);
	this->triangles.add(3);
	this->triangles.add(2);
	*/
	int size = 11;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			this->verticies.add(Vector3(i - size / 2, 0, j - size / 2));
			if (i < size - 1 && j < size - 1)
			{
				this->triangles.add(i + j * size);
				this->triangles.add(i + 1 + j * size);
				this->triangles.add(i + 1 + (j + 1) * size);

				this->triangles.add(i + j * size);
				this->triangles.add(i + 1 + (j + 1) * size);
				this->triangles.add(i + (j + 1) * size);
			}
		}
	}
	return;
}

Mesh::~Mesh()
{
	return;
}