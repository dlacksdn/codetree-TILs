#include <iostream>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;

	int x_dir[4] = { 0, 1, 0, -1 };
	int y_dir[4] = { 1, 0, -1, 0 };

	int x = 0, y = 0;
	int dir = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'L') {
			dir = (dir + 3) % 4;
		}
		else if (str[i] == 'R') {
			dir = (dir + 1) % 4;
		}
		else if (str[i] == 'F') {
			x += x_dir[dir];
			y += y_dir[dir];
		}
	}

	cout << x << " " << y;
}