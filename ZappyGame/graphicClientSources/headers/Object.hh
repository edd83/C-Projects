#ifndef __OBJECT_HH__
#define __OBJECT_HH__

#include "AObject.hh"

class Object : public AObject
{
public:
	Object(objectType _type);
	~Object();
};

#endif
