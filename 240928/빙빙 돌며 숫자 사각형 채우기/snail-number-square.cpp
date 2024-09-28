#include <iostream>
#include <vector>
using namespace std;

bool is_range(int x, int y, int n, int m) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool is_overlap(int x, int y, vector<vector<int>> v) {
	return v[x][y] == 0;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m, 0));

	int x_dir[4] = { 0, 1, 0, -1 };
	int y_dir[4] = { 1, 0, -1, 0 };

	int number = 1;
	int dir = 0;
	int x_index = 0, y_index = 0;
	while (true) {
		if (is_range(x_index, y_index, n, m) && is_overlap(x_index, y_index, v)) { // 현재 인덱스가 범위 안에 있다
			v[x_index][y_index] = number++; // 있으니 값을 할당
			if (is_range(x_index + x_dir[dir], y_index + y_dir[dir], n, m) && is_overlap(x_index + x_dir[dir], y_index + y_dir[dir], v)) { // 다음 인덱스도 범위 안에 있다
				x_index += x_dir[dir]; y_index += y_dir[dir]; // 있으니 다음 인덱스로 가자
			}
			else { // 다음 인덱스가 범위를 벗어난다
				dir = (dir + 1) % 4; // 방향을 바꾸자
				x_index += x_dir[dir]; y_index += y_dir[dir];
			}
		}
		else {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}