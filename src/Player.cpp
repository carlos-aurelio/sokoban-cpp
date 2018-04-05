#include "Room.h"
#include "Target.h"
#include "Player.h"

Player::Player(Room * room, int x, int y): Object(room, true, x, y) {}

void Player::Input(int dx, int dy)
{
	this->Move(dx, dy);
}

bool Player::OverlapsWith(Object * other)
{
	if (dynamic_cast<Target *>(other))
	{
		return true;
	}
	else
	{
		return false;
	}
}


