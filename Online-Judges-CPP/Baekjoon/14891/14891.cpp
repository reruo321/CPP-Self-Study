#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

#define CLOCKWISE 1
#define STOP 0
#define ANTI_CLOCKWISE -1

#define LEFT_PART 6
#define RIGHT_PART 2

using namespace std;

void finalGear() {
	string str;
	vector<deque<int>> vector_gear(4, deque<int>(8, 0));
	vector<int> vector_gearRotationDir(4, 0);
	int k, gear_no, rotation_dir;
	int score = 0;

	// input gear status
	for (int i = 0; i < 4; ++i) {
		cin >> str;
		for (int j = 0; j < 8; ++j) {
			vector_gear.at(i).at(j) = str.at(j) - '0';
		}
	}

	// input rotations
	cin >> k;

	for (int i = 0; i < k; ++i) {
		vector_gearRotationDir.assign(4, 0);
		cin >> gear_no >> rotation_dir;

		// WARNING!!!
		--gear_no;
		vector_gearRotationDir.at(gear_no) = rotation_dir;

		int gear_front;
		int gear_rear;
		gear_front = gear_rear = gear_no;

		while (--gear_front >= 0) {
			// if rear gear rotates
			if (vector_gearRotationDir.at(gear_front + 1) != 0) {
				// if front gear's RIGHT != rear gear's LEFT
				if(vector_gear.at(gear_front).at(RIGHT_PART) != vector_gear.at(gear_front + 1).at(LEFT_PART))
					// Mark front gear to rotate (opposite direction)
					vector_gearRotationDir.at(gear_front) = vector_gearRotationDir.at(gear_front + 1) * (-1);
			}
		}
		
		while (++gear_rear < 4) {
			// if front gear rotates
			if (vector_gearRotationDir.at(gear_rear - 1) != 0) {
				// if front gear's RIGHT != rear gear's LEFT
				if (vector_gear.at(gear_rear - 1).at(RIGHT_PART) != vector_gear.at(gear_rear).at(LEFT_PART))
					// Mark rear gear to rotate (opposite direction)
					vector_gearRotationDir.at(gear_rear) = vector_gearRotationDir.at(gear_rear - 1) * (-1);
			}
		}

		// Rotate four gears
		for (int i = 0; i < 4; ++i) {
			int back;
			int front;
			switch (vector_gearRotationDir.at(i)) {
			case CLOCKWISE:
				back = vector_gear.at(i).back();
				vector_gear.at(i).pop_back();
				vector_gear.at(i).push_front(back);
				break;
			case ANTI_CLOCKWISE:
				front = vector_gear.at(i).front();
				vector_gear.at(i).pop_front();
				vector_gear.at(i).push_back(front);
				break;
			default:
				break;
			}
		}

	}

	for (int i = 0; i < 4; ++i) {
		// Note that N = 0, S = 1
		score += vector_gear.at(i).front() * static_cast<int>(pow(2, i));
	}

	cout << score << endl;
}

int main() {

	finalGear();

	return 0;
}