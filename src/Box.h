#ifndef BOX_H_
#define BOX_H_

#include "Object.h"

class Box: public Object
{
public:
	Box(Room * room, int x, int y);

	virtual bool OverlapsWith(Object * other);
};

#endif /* BOX_H_ */
