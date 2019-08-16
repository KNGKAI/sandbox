#ifndef MESH_H
#define MESH_H

#include <string>

#include "icomponent.h"
#include "vector3.h"
#include "list.h"

#define RENDER_NONE 0
#define RENDER_STANDARD 1
#define RENDER_WIRE 2

class Mesh
{
    public:
		Mesh();
		~Mesh();
        List<Vector3>   verticies;
        List<Vector3>   normals;
        List<int>       triangles;
		unsigned int	renderType;
};

#endif