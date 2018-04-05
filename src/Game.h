#ifndef GAME_H_
#define GAME_H_

#include <vector>

class IO;
class Room;

class Game
{
private:
	IO * io;
	std::vector<Room *> rooms;

	void PlayRoom(Room * r);

public:
	Game();
	~Game();

	void AddRoom(Room * r);
	void Run();
};



#endif /* GAME_H_ */
