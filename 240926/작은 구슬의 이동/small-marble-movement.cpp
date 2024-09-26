#include <iostream>
#include <vector>
using namespace std;

int first_direction(char c) {
	if (c == 'R') {
		return 0;
	}
	else if (c == 'D') {
		return 1;
	}
	else if (c == 'L') {
		return 2;
	}
	else if (c == 'U') {
		return 3;
	}
}

bool in_range(int x, int y, int n) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
	int n, t;
	cin >> n >> t;

	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));

	int x_dir[4] = { 0, 1, 0, -1 };
	int y_dir[4] = { 1, 0, -1, 0 };

	int r, c;
	char d;
	cin >> r >> c >> d;

	int dir = first_direction(d);

	while (t--) {
		int dx = r + x_dir[dir];
		int dy = c + y_dir[dir];

		if (in_range(dx, dy, n)) {
			r = dx;
			c = dy;
		}
		else {
			dir = (dir + 2) % 4;
		}
	}

	cout << r << " " << c;
}