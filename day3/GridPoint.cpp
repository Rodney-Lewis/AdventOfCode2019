#include <math.h>

class GridPoint {

public:int x;
public:int y;
public:int distance;

	public:GridPoint(int pt1, int pt2) {
		x = pt1;
		y = pt2;
		distance = abs(x + y);
	}

	bool operator== (const GridPoint& obj1) {
		if (obj1.x == x && obj1.y == y) {
			return true;
		}
		else
			return false;
	}
};