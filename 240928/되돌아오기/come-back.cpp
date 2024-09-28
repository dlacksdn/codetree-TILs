#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int x_dir[4] = { 1, -1, 0, 0 };
	int y_dir[4] = { 0, 0, -1, 1 };

	char direction; int distance;
	int x = 0, y = 0;
	int count = 0;
	bool flag = false;
	bool is_arrive = false;
	while (N--) {
		cin >> direction >> distance;

		if (direction == 'E') {
			for (int i = 0; i < distance; i++) {
				x += x_dir[0];
				y += y_dir[0];
				count++;

				if (x == 0 && y == 0) {
					flag = true;
					is_arrive = true;
					break;
				}
			}
		}
		else if (direction == 'W') {
			for (int i = 0; i < distance; i++) {
				x += x_dir[1];
				y += y_dir[1];
				count++;

				if (x == 0 && y == 0) {
					flag = true;
					is_arrive = true;
					break;
				}
			}
		}
		else if (direction == 'S') {
			for (int i = 0; i < distance; i++) {
				x += x_dir[2];
				y += y_dir[2];
				count++;

				if (x == 0 && y == 0) {
					flag = true;
					is_arrive = true;
					break;
				}
			}
		}
		else if (direction == 'N') {
			for (int i = 0; i < distance; i++) {
				x += x_dir[3];
				y += y_dir[3];
				count++;

				if (x == 0 && y == 0) {
					flag = true;
					is_arrive = true;
					break;
				}
			}
		}

		if (flag) {
			break;
		}
		
	}
	
	if (is_arrive) {
		cout << count;
	}
	else {
		cout << -1;
	}
}