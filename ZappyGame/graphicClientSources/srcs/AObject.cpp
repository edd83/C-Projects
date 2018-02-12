#include "../headers/AObject.hh"

AObject::AObject(objectType _type) : type(_type)
{

}

AObject::~AObject() {}

objectType AObject::getType() const
{
	return (type);
}

void	AObject::setType(objectType newType)
{
	type = newType;
}
