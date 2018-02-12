#ifndef __AOBJECT__
#define __AOBJECT__

#include "IObject.hh"

class AObject : public IObject
{
public:
	AObject(objectType _type);
	~AObject();

	virtual objectType getType() const;
	virtual void setType(objectType);
private:
	objectType type;
};

#endif
