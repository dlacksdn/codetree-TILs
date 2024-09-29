#include <iostream>
#include <vector>
using namespace std;

bool in_range(int x, int y, int n, int m) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m, ' '));

	int x_dir[4] = { 1, 0, -1, 0 };
	int y_dir[4] = { 0, 1, 0, -1 };

	int x = 0, y = 0;
	int dir = 1;

	int value;
	for (int i = 0; i < n * m; i++) {
		value = (i % 26) + 65;
		v[x][y] = value;


		int nx = x + x_dir[dir];
		int ny = y + y_dir[dir];
		if (in_range(nx, ny, n, m) && v[nx][ny] == ' ') {
			x = nx;
			y = ny;
		}
		else {
			dir = (dir + 3) % 4;
			x += x_dir[dir];
			y += y_dir[dir];
			if (!in_range(x, y, n, m) || !(v[x][y] == ' ')) {
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

/*
65 ~ 90
0 ~ 25 한 다음에 + 65하면 됨
*/