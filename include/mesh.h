#ifndef MESH_H
#define MESH_H

#include <vector>

#include "vector.h"

using namespace std;

class Mesh
{
public:
    Mesh(/* args */);
    ~Mesh();

    vector<vec3>    vecticies;
    vector<vec3>    triangles;
};

#endif