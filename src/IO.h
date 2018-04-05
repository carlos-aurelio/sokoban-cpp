#ifndef IO_H_
#define IO_H_

class Room;

class IO
{
private:
	int last_dx;
	int last_dy;
public:
	IO();
	virtual ~IO();

	void WaitInput();
	int GetLastDx();
	int GetLastDy();
	void PrintRoom(Room * room);
	void Clear();
};

#endif
