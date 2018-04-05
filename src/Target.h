#ifndef TARGET_H_
#define TARGET_H_

#include "Object.h"

class Target: public Object
{
public:
	Target(Room * room, int x, int y);

	virtual bool OverlapsWith(Object * other);
};

#endif /* TARGET_H_ */
