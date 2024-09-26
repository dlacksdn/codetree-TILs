#include <iostream>
#include <vector>
using namespace std;

int n;

bool process(int x, int y) {
	return ((1 <= x && x <= n) && (1 <= y && y <= n));
}

int main() {
	
	cin >> n;

	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}

	int x_dir[4] = { 0, 1, 0, -1 };
	int y_dir[4] = { 1, 0, -1, 0 };

	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int count = 0;
			for (int k = 0; k < 4; k++) {
				int dx = i + x_dir[k];
				int dy = j + y_dir[k];

				if (process(dx, dy) && v[dx][dy] == 1) {
					count++;
				}
			}
			if (count >= 3) {
				result++;
			}
		}
	}

	cout << result;
}