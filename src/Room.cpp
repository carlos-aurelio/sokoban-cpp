#include <sstream>
#include <algorithm>
#include <exception>
#include "Room.h"
#include "Box.h"
#include "Wall.h"
#include "Target.h"
#include "Player.h"

Room::Room(int w, int h)
{
	this->w = w;
	this->h = h;
	this->objects = std::vector<Object *>();
	this->player = NULL;
}

Room::Room(std::string layout) : Room(0, 0)
{
	int x = 0;
	int y = 0;
	for (char c : layout)
	{
		switch (c)
		{
		case '\n':
		case '\r':
			this->w = std::max(this->w, x + 1);
			x = 0;
			y++;
			break;
		case 'b':
			this->AddObject(new Target(this, x, y));
			// no break
		case 'B':
			this->AddObject(new Box(this, x, y));
			break;
		case 'T':
		case 't':
			this->AddObject(new Target(this, x, y));
			break;
		case 'W':
		case 'w':
			this->AddObject(new Wall(this, x, y));
			break;
		case 'p':
			this->AddObject(new Target(this, x, y));
			// no break
		case 'P':
			if (this->player)
			{
				throw new std::exception();
			}
			else
			{
				this->player = new Player(this, x, y);
				this->AddObject(this->player);
			}
			break;
		default:
			break;
		}
		x++;
	}
	this->h = y + 1;
}

Room::~Room()
{
	for (Object * o : this->objects)
	{
		delete o;
	}
}

void Room::AddObject(Object * o)
{
	if (!o)
	{
		throw new std::exception();
	}
	this->objects.push_back(o);
}

void Room::Input(int dx, int dy)
{
	this->player->Input(dx, dy);
}

int Room::GetW()
{
	return this->w;
}

int Room::GetH()
{
	return this->h;
}

bool Room::IsClear()
{
	for (Object * o : this->objects)
	{
		if (dynamic_cast<Target *>(o) && !this->HasAt<Box *>(o->GetX(), o->GetY()))
		{
			return false;
		}
	}
	return true;
}

std::vector<Object *> * Room::GetAt(int x, int y)
{
	std::vector<Object *> * ret = new std::vector<Object *>();
	for (Object * o : this->objects)
	{
		if (o->GetX() == x && o->GetY() == y)
		{
			ret->push_back(o);
		}
	}
	return ret;
}

template <class T> bool Room::HasAt(int x, int y)
{
	std::vector<Object *> * objs = this->GetAt(x, y);
	for (Object * o : *objs)
	{
		if (dynamic_cast<T>(o))
		{
			delete objs;
			return true;
		}
	}
	delete objs;
	return false;
}

