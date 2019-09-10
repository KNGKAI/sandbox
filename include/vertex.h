#ifndef VERTEX_H
#define VERTEX_H

#include "vector.h"

struct Vertex {
	// position
	vec3 Position;
	// normal
	vec3 Normal;
	// texCoords
	vec2 TexCoords;
	// tangent
	vec3 Tangent;
	// bitangent
	vec3 Bitangent;
};

#endif