#ifndef MATERIAL_H
#define MATERIAL_H

struct Material
{
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

#endif