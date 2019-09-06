#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "vector.h"
#include "icomponent.h"

class Rigidbody : public IComponent
{
	public:
		Rigidbody() : useGravity(true) { return; }
		~Rigidbody() { return; }
		vec3 velocity;
		double mass;
		bool useGravity;
};

#endif