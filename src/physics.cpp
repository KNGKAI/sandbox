#include "physics.h"
#include "sandbox.h"

void Physics::process()
{
	List<IEntity *>* objects = Sandbox::scene()->objects();
	IEntity *obj;

	for (int i = 0; i < objects->length(); i++)
	{
		obj = objects->get(i);
		if (obj->rigidbody.enabled)
		{
			obj->transform.position += obj->rigidbody.velocity * Sandbox::deltaTime();
			if (obj->rigidbody.useGravity) { obj->rigidbody.velocity.y -= 9.8 * Sandbox::deltaTime(); }
			if (obj->transform.position.y < 0)
			{
				obj->rigidbody.velocity.y = 0;
				obj->transform.position.y = 0;
			}
		}
	}
}