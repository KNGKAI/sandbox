#include <iostream>
#include <fstream>
#include <string>

#include "mesh.h"

Mesh::Mesh()
{
	this->renderType = RENDER_STANDARD;
	this->color = Vector3(1, 1, 1);
	return;
}

Mesh::~Mesh()
{
	return;
}

Vector3 Mesh::Reader::getVectorFromLine(std::string path)
{
	Vector3 v;

	return (v);
}

Mesh Mesh::Reader::loadMesh(std::string path)
{
	std::ifstream file(path);
	std::string line;
	Mesh m;

	while (std::getline(file, line))
	{
		if (line.find("v ") != std::string::npos)
		{
			Vector3 v;
			line = &line[line.find(" ") + 1];
			v.x = std::atof(line.c_str());
			line = &line[line.find(" ") + 1];
			v.y = std::atof(line.c_str());
			line = &line[line.find(" ") + 1];
			v.z = std::atof(line.c_str());
			m.verticies.add(v);
		}
		else if (line.find("f ") != std::string::npos)
		{
			int base;
			int current;
			int prev;

			line = &line[line.find(" ") + 1];
			base = std::atoi(line.c_str()) - 1;
			line = &line[line.find(" ") + 1];
			prev = std::atoi(line.c_str()) - 1;
			while (line.find(" ") != std::string::npos)
			{
				line = &line[line.find(" ") + 1];
				current = std::atoi(line.c_str()) - 1;
				m.triangles.add(base);
				m.triangles.add(prev);
				m.triangles.add(current);
				prev = current;
			}
		}
	}
	return (m);
}

Mesh Mesh::Primitive::Cube()
{
	Mesh m;

	m.verticies.add(Vector3(0, 0, 0));
	m.verticies.add(Vector3(1, 0, 0));
	m.verticies.add(Vector3(1, 1, 0));
	m.verticies.add(Vector3(0, 1, 0));
	m.verticies.add(Vector3(0, 0, 1));
	m.verticies.add(Vector3(1, 0, 1));
	m.verticies.add(Vector3(1, 1, 1));
	m.verticies.add(Vector3(0, 1, 1));
	//
	m.triangles.add(0);
	m.triangles.add(2);
	m.triangles.add(1);

	m.triangles.add(0);
	m.triangles.add(3);
	m.triangles.add(2);
//
	m.triangles.add(4);
	m.triangles.add(6);
	m.triangles.add(5);

	m.triangles.add(4);
	m.triangles.add(7);
	m.triangles.add(6);
//
	m.triangles.add(0);
	m.triangles.add(5);
	m.triangles.add(1);

	m.triangles.add(0);
	m.triangles.add(4);
	m.triangles.add(5);
//
	m.triangles.add(1);
	m.triangles.add(6);
	m.triangles.add(2);

	m.triangles.add(1);
	m.triangles.add(5);
	m.triangles.add(6);
	//
	m.triangles.add(2);
	m.triangles.add(6);
	m.triangles.add(3);

	m.triangles.add(2);
	m.triangles.add(5);
	m.triangles.add(6);
//
	m.triangles.add(3);
	m.triangles.add(4);
	m.triangles.add(0);

	m.triangles.add(3);
	m.triangles.add(7);
	m.triangles.add(4);

	return (m);
}

Mesh Mesh::Primitive::Plane()
{
	Mesh m;
	int size;

	size = 11;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			m.verticies.add(Vector3(i - size / 2, 0, j - size / 2));
			if (i < size - 1 && j < size - 1)
			{
				m.triangles.add(i + j * size);
				m.triangles.add(i + 1 + j * size);
				m.triangles.add(i + 1 + (j + 1) * size);

				m.triangles.add(i + j * size);
				m.triangles.add(i + 1 + (j + 1) * size);
				m.triangles.add(i + (j + 1) * size);
			}
		}
	}
	return (m);
}