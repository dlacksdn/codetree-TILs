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
		char direction;
		int distance;
		cin >> direction >> distance;

		if (direction == 'E') {
			for (int i = 0; i < distance; i++) {
				x += dx[0]; y += dy[0];
			}
		}
		else if (direction == 'W') {
			for (int i = 0; i < distance; i++) {
				x += dx[1]; y += dy[1];
			}
		}
		else if (direction == 'S') {
			for (int i = 0; i < distance; i++) {
				x += dx[2]; y += dy[2];
			}
		}
		else if (direction == 'N') {
			for (int i = 0; i < distance; i++) {
				x += dx[3]; y += dy[3];
			}
		}
	}

	cout << x << " " << y;
}