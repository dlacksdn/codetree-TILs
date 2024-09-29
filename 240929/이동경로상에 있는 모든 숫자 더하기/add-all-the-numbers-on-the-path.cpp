#include <iostream>
#include <vector>
using namespace std;

bool in_range(int x, int y, int n) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
	int N, T;
	cin >> N >> T;

	vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));

	string str;
	cin >> str;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> v[i][j];
		}
	}

	int x_dir[4] = { -1, 0, 1, 0 };
	int y_dir[4] = { 0, 1, 0, -1 };
	int x, y;
	x = y = N / 2 + 1;

	int score = v[x][y];
	int dir = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'L') {
			dir = (dir + 3) % 4;
		}
		else if (str[i] == 'R') {
			dir = (dir + 1) % 4;
		}
		else if (str[i] == 'F') {
			int dx = x + x_dir[dir];
			int dy = y + y_dir[dir];
			
			if (in_range(dx, dy, N)) {
				x = dx;
				y = dy;

				score += v[x][y];
			}
		}
	}

	cout << score;
}