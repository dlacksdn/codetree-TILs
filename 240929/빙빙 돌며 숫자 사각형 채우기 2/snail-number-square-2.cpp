#include <iostream>
#include <vector>
using namespace std;

bool in_range(int x, int y, int n, int m) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m, 0));

	int x_dir[4] = { 1, 0, -1, 0 };
	int y_dir[4] = { 0, 1, 0, -1 };

	int x = 0, y = 0;
	int dir = 0;

	for (int i = 0; i < n * m; i++) {
		v[x][y] = i + 1;
		
		
		int nx = x + x_dir[dir];
		int ny = y + y_dir[dir];
		if (in_range(nx, ny, n, m) && v[nx][ny] == 0) {
			x = nx;
			y = ny;
		}
		else {
			dir = (dir + 1) % 4;
			x += x_dir[dir];
			y += y_dir[dir];
			if (!in_range(x, y, n, m) || !(v[x][y] == 0)) {
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