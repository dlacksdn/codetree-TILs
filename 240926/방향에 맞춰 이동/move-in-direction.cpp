#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	int x = 0, y = 0;
	while (N--) {
		char direction; int distance;
		int dir;
		cin >> direction >> distance;

		if (direction == 'E') {
			dir = 0;
		}
		else if (direction == 'W') {
			dir = 1;
		}
		else if (direction == 'S') {
			dir = 2;
		}
		else if (direction == 'N') {
			dir = 3;
		}

		x += dx[dir] * distance;
		y += dy[dir] * distance;
	}

	cout << x << " " << y;
}