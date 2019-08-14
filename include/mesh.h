#ifndef MESH_H
#define MESH_H

#include <string>

#include "ientity.h"
#include "vector3.h"
#include "list.h"

class Mesh
{
    public:
        List<Vector3>   verticies;
        List<Vector3>   normals;
        List<int>       triangles;
};

#endif