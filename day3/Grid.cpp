#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "GridPoint.cpp"

using namespace std;

class Grid {

	public:Grid() {
		//Add central point
		gridPoints.push_back(GridPoint(0, 0));
	}

	private:vector<GridPoint> gridPoints;
	private:vector<GridPoint> intersectionPoints;
	private:int closestIntersectionPointDistance = 0;
	private:int farthestIntersectionPointDistance = 0;

	public:void buildGrid(vector<string> gridInput) {

		int distance = 0;
		string inputCopy;
		cout << "Grid build start" << endl;

		for (int i = 0; i < gridInput.size(); i++) {
			if (gridInput[i].at(0) == 'U') {
				distance = 0;
				istringstream inputStringStream(gridInput[i].substr(1, gridInput[i].size()));
				inputStringStream >> distance;

				for (int j = 0; j < distance; j++) {
					gridPoints.push_back(GridPoint(gridPoints.back().x, gridPoints.back().y + 1));
				}
			}
			else if (gridInput[i].at(0) == 'R') {
				distance = 0;
				istringstream inputStringStream(gridInput[i].substr(1, gridInput[i].size()));
				inputStringStream >> distance;

				for (int j = 0; j < distance; j++) {
					gridPoints.push_back(GridPoint(gridPoints.back().x + 1, gridPoints.back().y));
				}
			}
			else if (gridInput[i].at(0) == 'D') {
				distance = 0;
				istringstream inputStringStream(gridInput[i].substr(1, gridInput[i].size()));
				inputStringStream >> distance;

				for (int j = 0; j < distance; j++) {
					gridPoints.push_back(GridPoint(gridPoints.back().x, gridPoints.back().y - 1));
				}
			}
			else if (gridInput[i].at(0) == 'L') {
				distance = 0;
				istringstream inputStringStream(gridInput[i].substr(1, gridInput[i].size()));
				inputStringStream >> distance;

				for (int j = 0; j < distance; j++) {
					gridPoints.push_back(GridPoint(gridPoints.back().x - 1, gridPoints.back().y));
				}
			}
		}
		cout << "Grid built end" << endl;
	}

	private:void findIntersections(Grid grid) {
		cout << "Intersections begin" << endl;
		intersectionPoints.clear();
		for (int i = 1; i < grid.gridPoints.size(); i++) {
			cout << "Intersections " << i << endl;
			for (int k = 1; k < gridPoints.size(); k++) {
				if (gridPoints[k] == grid.gridPoints[i]) {
					intersectionPoints.push_back(gridPoints[k]);
				}
			}
		}
		cout << "Intersections end" << endl;
	}

	void findIntersectionDistances(Grid grid) {

		findIntersections(grid);

		closestIntersectionPointDistance = 0;
		farthestIntersectionPointDistance = 0;

		int max = INT_MIN;
		int min = INT_MAX;

		for (int i = 0; i < intersectionPoints.size(); i++) {
			if (intersectionPoints[i].distance < min) {
				min = intersectionPoints[i].distance;
			}

			if (intersectionPoints[i].distance > max) {
				max = intersectionPoints[i].distance;
			}
		}

		farthestIntersectionPointDistance = max;
		closestIntersectionPointDistance = min;

		cout << "Close: " << closestIntersectionPointDistance << endl;
		cout << "Far: " << farthestIntersectionPointDistance << endl;
	}
};