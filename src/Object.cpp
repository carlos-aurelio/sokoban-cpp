#include <vector>
#include <exception>
#include "Room.h"
#include "Object.h"

Object::Object(Room * room, bool moveable, int x, int y)
{
	if (!room)
	{
		throw new std::exception();
	}
	this->room = room;
	this->moveable = moveable;
	this->x = this->prev_x = x;
	this->y = this->prev_y = y;
}


int Object::GetX()
{
	return this->x;
}

int Object::GetY()
{
	return this->y;
}

bool Object::Overlapping(Object * other)
{
	return this->GetX() == other->GetX() && this->GetY() == other->GetY();
}

bool Object::CanMove(int dx, int dy)
{
	if (!this->moveable)
	{
		return false;
	}
	else if (dx == 0 && dy == 0)
	{
		return false;
	}
	else if (dx != 0 && dy != 0)
	{
		return false;
	}
	else if (dx < -1 || dx > 1 || dy < -1 || dy > 1)
	{
		return false;
	}
	else
	{
		std::vector<Object *> * objs = this->room->GetAt(this->x + dx, this->y + dy);
		for (Object * o : *objs)
		{
			if (!o->OverlapsWith(this))
			{
				if (!o->CanMove(dx, dy))
				{
					delete objs;
					return false;
				}
			}
		}
		delete objs;
		return true;
	}
}

void Object::Move(int dx, int dy)
{
	if (this->CanMove(dx, dy))
	{
		std::vector<Object *> * objs = this->room->GetAt(this->x + dx, this->y + dy);
		for (Object * o : *objs)
		{
			if (!o->OverlapsWith(this))
			{
				o->Move(dx, dy);
			}
		}
		this->x += dx;
		this->y += dy;
		delete objs;
	}
}
