#include <iostream>
#include <vector>
using namespace std;

bool in_range(int x, int y) {
	return 1 <= x && x <= 19 && 1 <= y && y <= 19;
}

bool check_win(vector<vector<int>> v, int x, int y, int x_dir, int y_dir, int target) {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		x += x_dir;
		y += y_dir;

		if (!in_range(x, y) || !(v[x][y] == target)) {
			return false;
		}
	}

	return true;
}
// 벡터, 초기 x, 초기 y, 방향 x, 방향 y, 어떤 돌이 놓여있는지

int main() {
	vector<vector<int>> v(20, vector<int>(20, 0));

	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> v[i][j];
		}
	}

	int x_dir[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	int y_dir[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if (v[i][j] != 0) {
				for (int k = 0; k < 8; k++) {
					int x_loc = i + x_dir[k];
					int y_loc = +y_dir[k];
					if (in_range(x_loc, y_loc) && v[i + x_dir[k]][j + y_dir[k]] == v[i][j]) {
						if (check_win(v, i, j, x_dir[k], y_dir[k], v[i][j])) {
							cout << v[i][j] << "\n";
							cout << i + 2 * x_dir[k] << " " << j + 2 * y_dir[k];
							return 0;
						}
					}
				}
			}
		}
	}

	cout << 0;
}

/*
처음부터 쭉 탐색하다보면 0이 아닌 원소가 나오겠지
그 위치를 중심으로 바로 옆에 같은 숫자가 있는지 확인하는거지
이거는 dx/dy 테크닉을 활용해서 근처에 숫자가 있던 방향을 저장해두는게 맞겠다.
범위에 벗어나는지 확인하는 함수도 필요하다.
방향대로 쭉 있는지 확인하는건 따로 함수를 만드는게 맞겠다.
근방에 같은 숫자가 2개 이상 있을 수도 있으니까

1. 방향 배열 만들기
2. in_range함수 만들기
3. 일자로 쭉 있는지 확인하는 함수 만들기
*/