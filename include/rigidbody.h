#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "vector3.h"
#include "icomponent.h"

class Rigidbody : public Component
{
	public:
		Rigidbody() : useGravity(false) { return; }
		~Rigidbody() { return; }
		Vector3 velocity;
		double mass;
		bool useGravity;
};

#endif