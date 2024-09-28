#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int x_dir[4] = { -1, 0, 1, 0 };
	int y_dir[4] = { 0, 1, 0, -1 };

	vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));

	int r, c;
	while (M--) {
		cin >> r >> c;
		int count = 0;

		v[r][c] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = r + x_dir[i];
			int ny = c + y_dir[i];

			if (v[nx][ny] == 1) {
				count++;
			}
		}

		if (count == 3) {
			cout << 1 << "\n";
		}
		else cout << 0;
	}
}