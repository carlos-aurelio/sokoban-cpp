#ifndef WALL_H_
#define WALL_H_

#include "Object.h"

class Wall: public Object
{
public:
	Wall(Room * room, int x, int y);

	virtual bool OverlapsWith(Object * other);
};

#endif /* WALL_H_ */
