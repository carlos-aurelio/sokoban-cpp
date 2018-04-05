#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include <vector>

class Object;
class Player;

class Room
{
private:
	int w;
	int h;
	std::vector<Object *> objects;
	Player * player;

public:
	Room(int w, int h);
	Room(std::string layout);
	virtual ~Room();

	void AddObject(Object * o);
	void Input(int dx, int dy);
	int GetW();
	int GetH();
	bool IsClear();
	std::vector<Object *> * GetAt(int x, int y);
	template <class T> bool HasAt(int x, int y);
};



#endif /* ROOM_H_ */
