#include <iostream>
#include <vector>
using namespace std;

bool in_range(int x, int y, int n) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0));

	int x_dir[4] = { 0, -1, 0, 1 };
	int y_dir[4] = { -1, 0, 1, 0 };
	int dir = 0;

	int x = n - 1, y = n - 1;
	for (int i = n * n; i >= 1; i--) {
		v[x][y] = i;

		int dx = x + x_dir[dir];
		int dy = y + y_dir[dir];

		if (in_range(dx, dy, n) && v[dx][dy] == 0) {
			x = dx;
			y = dy;
		}
		else {
			dir = (dir + 1) % 4;
			x += x_dir[dir];
			y += y_dir[dir];

			if (!in_range(x, y, n) || (v[x][y] != 0)) {
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}