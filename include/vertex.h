#ifndef VERTEX_H
#define VERTEX_H

#include "vector.h"

struct Vertex {
	vec3 Position;
	vec3 Normal;
	vec2 TexCoords;
	vec3 Tangent;
	vec3 Bitangent;
};

#endif