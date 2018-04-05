#include "IO.h"
#include "Room.h"
#include "Game.h"

Game::Game()
{
	this->io = new IO();
	this->rooms = std::vector<Room *>();
}

Game::~Game()
{
	for (Room * r : this->rooms)
	{
		delete r;
	}
	delete this->io;
}

void Game::PlayRoom(Room * r)
{
	bool done = false;
	while (!done)
	{
		this->io->PrintRoom(r);
		io->WaitInput();
		r->Input(io->GetLastDx(), io->GetLastDy());
		if (r->IsClear())
		{
			io->PrintRoom(r);
			done = true;
			io->WaitInput();
			io->Clear();
		}
	}
}

void Game::AddRoom(Room * r)
{
	this->rooms.push_back(r);
}

void Game::Run()
{
	for (Room * r : this->rooms)
	{
		this->PlayRoom(r);
	}
}

