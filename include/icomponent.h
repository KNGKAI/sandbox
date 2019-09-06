#ifndef ICOMPONENT_H
#define ICOMPONENT_H

class IComponent
{
	public:
		IComponent() : enabled(true) { return; }
		bool enabled;
};

#endif