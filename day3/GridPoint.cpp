#include <math.h>
#include <string>
using namespace std;

class GridPoint {

public:int x;
public:int y;
public:int distance;
public:string coordinateString;

	public:GridPoint(int pt1, int pt2) {
		x = pt1;
		y = pt2;
		distance = abs(x) + abs(y);
		coordinateString = to_string(x) + " " + to_string(y);
	}

	bool operator== (const GridPoint& obj1) {
		if (obj1.coordinateString == coordinateString) {
			return true;
		}
		else
			return false;
	}
};