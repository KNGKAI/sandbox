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
            return;
        }
        Mesh(std::string name)
        {
            this->_name = name;
            return;
        }
        ~Mesh() {return;}
        List<Vector3>   verticies;
        List<Vector3>   normals;
        List<int>       triangles;

        Object_Type type() { return(T_Mesh); }
};

#endif