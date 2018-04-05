#ifndef OBJECT_H_
#define OBJECT_H_

class Room;
class Object
{
protected:
	Room * room;
	bool moveable;
	int x;
	int y;
	int prev_x;
	int prev_y;

	bool Overlapping(Object * other);
	bool CanMove(int dx, int dy);
	void Move(int dx, int dy);

public:
	Object(Room * room, bool moveable, int x, int y);
	virtual ~Object() {}

	int GetX();
	int GetY();

	virtual bool OverlapsWith(Object * other) = 0;
};

#endif /* OBJECT_H_ */
