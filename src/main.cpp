#include "Room.h"
#include "Game.h"

int main() {
	std::string s1 =
			"WWWWWW\n"
			"W    W\n"
			"W  P W\n"
			"WtB  W\n"
			"W    W\n"
			"WWWWWW\n"
			;
	std::string s2 =
			"  WWWWW \n"
			"WWW   W \n"
			"WtPB  W \n"
			"WWW BtW \n"
			"WtWWB W \n"
			"W W t WW\n"
			"WB bBBtW\n"
			"W   t  W\n"
			"WWWWWWWW"
			;
	Game * g = new Game();
	g->AddRoom(new Room(s1));
	g->AddRoom(new Room(s2));
	g->Run();
	return 0;
}
