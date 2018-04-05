#include <stdio.h>
#include <cursesw.h>

#include "Player.h"
#include "Box.h"
#include "Target.h"
#include "Wall.h"
#include "Room.h"
#include "IO.h"

IO::IO()
{
	this->last_dx = 0;
	this->last_dy = 0;
	initscr();
	keypad(stdscr, TRUE);
	timeout(-1);
	noecho();
}

IO::~IO()
{
	echo();
	endwin();
}

void IO::WaitInput()
{
	this->last_dx = this->last_dy = 0;
	int key = getch();
	switch (key)
	{
	case KEY_UP:
		this->last_dy = -1;
		break;
	case KEY_DOWN:
		this->last_dy = 1;
		break;
	case KEY_LEFT:
		this->last_dx = -1;
		break;
	case KEY_RIGHT:
		this->last_dx = 1;
		break;
	}
}

int IO::GetLastDx()
{
	return this->last_dx;
}

int IO::GetLastDy()
{
	return this->last_dy;
}

void IO::PrintRoom(Room * room)
{
	for (int y = 0; y < room->GetH(); y++)
	{
		for (int x = 0; x < room->GetW(); x++)
		{
			std::vector<Object *> * objs = room->GetAt(x, y);
			std::string s;
			if (objs->size() == 0)
			{
				s = "  ";
			}
			else if (objs->size() == 1)
			{
				Object * o = objs->at(0);
				if (dynamic_cast<Wall *>(o))
				{
					s = "XX";
				}
				else if (dynamic_cast<Box *>(o))
				{
					s = "[]";
				}
				else if (dynamic_cast<Target *>(o))
				{
					s = "()";
				}
				else if (dynamic_cast<Player *>(o))
				{
					s = "><";
				}
			}
			else
			{
				bool is_target = false;
				Object * o2 = NULL;
				for (Object * o : *objs)
				{
					if (dynamic_cast<Target *>(o))
					{
						is_target = true;
					}
					else
					{
						o2 = o;
					}
				}
				if (!is_target)
				{
					s = "!!";
				}
				if (dynamic_cast<Wall *>(o2))
				{
					s = "xx";
				}
				else if (dynamic_cast<Box *>(o2))
				{
					s = "{}";
				}
				else if (dynamic_cast<Target *>(o2))
				{
					s =  "@@";
				}
				else if (dynamic_cast<Player *>(o2))
				{
					s = "><";
				}
				else
				{
					s  = "??";
				}
			}
			mvprintw(y, 2 * x, "%s", s.c_str());
			delete objs;
		}
	}
	if (room->IsClear())
	{
		mvprintw(room->GetH() + 2, 0, "Room clear!");
	}
	refresh();
}

void IO::Clear()
{
	erase();
}
