#ifndef __IOBJECT__
#define __IOBJECT__

enum objectType { 
	FOOD = 0,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME,
	PLAYER_N,
	EGG,
	GROUND,
	PLAYER_O,
	PLAYER_S,
	PLAYER_E
 };

class IObject
{
public:
	IObject() {};
	virtual ~IObject() {};
	virtual objectType getType() const = 0;
	virtual void 	setType(objectType) = 0;
};

#endif
