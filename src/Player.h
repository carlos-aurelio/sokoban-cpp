#ifndef PLAYER_H_
#define PLAYER_H_

#include "Object.h"

class Player: public Object
{
public:
	Player(Room * room, int x, int y);

	void Input(int dx, int dy);

	virtual bool OverlapsWith(Object * other);
};

#endif /* PLAYER_H_ */
