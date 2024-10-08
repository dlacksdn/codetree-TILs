#include <iostream>
#include <vector>
using namespace std;

bool in_range(int x, int y, int N, int M) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int x_dir[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	int y_dir[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };


	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] != 'L') {
				continue;
			}

			for (int k = 0; k < 8; k++) {
				int cnt = 1;
				int x_Lo = i;
				int y_Lo = j;

				while (true) {
					int dx = x_Lo + x_dir[k];
					int dy = y_Lo + y_dir[k];

					if (!in_range(dx, dy, N, M))
						break;
					if (v[dx][dy] != 'E')
						break;

					x_Lo = dx;
					y_Lo = dy;
					cnt++;
				}

				if (cnt >= 3)
					count++;
			}
		}
	}

	cout << count;
}

/*
L을 찾아내면 전 방향으로 탐색한다.
1. 범위를 벗어나는지 확인하는 함수 작성
방향을 저장해야하니 dx dy 테크닉을 쓰자
2. 방향 배열 생성
*/