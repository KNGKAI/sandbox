#ifndef MESH_H
#define MESH_H

#include <string>

#include "transform.h"
#include "list.h"

class Mesh : public Transform
{
    public:
        Mesh()
        {
            this->verticies.add(Vector3(-0.5f, -0.5f, -0.5f));
            this->verticies.add(Vector3(0.5f, -0.5f, -0.5f));
            this->verticies.add(Vector3(0.5f, 0.5f, -0.5f));
            this->verticies.add(Vector3(-0.5f, 0.5f, -0.5f));
            this->verticies.add(Vector3(-0.5f, -0.5f, 0.5f));
            this->verticies.add(Vector3(0.5f, -0.5f, 0.5f));
            this->verticies.add(Vector3(0.5f, 0.5f, 0.5f));
            this->verticies.add(Vector3(-0.5f, 0.5f, 0.5f));
            this->triangles.add(0);
            this->triangles.add(1);
            this->triangles.add(2);
            this->triangles.add(1);
            this->triangles.add(3);
            this->triangles.add(2);
            return;
        }
        ~Mesh() {return;}
        List<Vector3>   verticies;
        List<Vector3>   normals;
        List<int>       triangles;
};

#endif