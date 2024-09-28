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
	int dir = 0;
	while (N--) {
		cin >> direction >> distance;

		if (direction == 'E') 
			dir = 0;
		else if (direction == 'W') 
			dir = 1;
		else if (direction == 'S') 
			dir = 2;
		else if (direction == 'N') 
			dir = 3;


		for (int i = 0; i < distance; i++) {
			x += x_dir[dir];
			y += y_dir[dir];
			count++;

			if (x == 0 && y == 0) {
				flag = true;
				is_arrive = true;
				break;
			}
		}

		if (flag) {
			break;
		}
		
	}
	
	if (is_arrive) 
		cout << count;
	else 
		cout << -1;
}