#include <iostream>
#include <vector>
using namespace std;

int find_corner(int N, int K) {
	int corner = 1;
	for (int i = N; i <= N * 4; i += N) { // 몇 번 모서리에서 시작하는지 구하는 process
		if (K <= i) {
			break;
		}
		corner++;
	}
	return corner;
}

int main() {
	int N;
	cin >> N;

	int x_dir[4] = { 0, 1, 0, -1 };
	int y_dir[4] = { 1, 0, -1, 0 };

	vector<vector<char>> v(N + 2, vector<char>(N + 2, ' '));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> v[i][j];
		}
	}

	int K;
	cin >> K;

	int corner = find_corner(N, K); // 몇 번 모서리인지 구하는 함수
	int target = (K - 1) % N; // 모서리에서 몇 번째가 시작좌표인가
	
	int x = 1, y = 1;
	int dir = 0;
	if (corner == 1) {
		x = 0;
		y = target + 1;
		dir = 1;
	}
	else if (corner == 2) {
		x = target + 1;
		y = N + 1;
		dir = 2;
	}
	else if (corner == 3) {
		x = N + 1;
		y = N - target;
		dir = 3;
	}
	else if (corner == 4) {
		x = N - target;
		y = 0;
		dir = 0;
	}

	int count = 0;
	while (true) {
		int before_x = x;
		int before_y = y;
		x += x_dir[dir];
		y += y_dir[dir];
		if (v[x][y] == '/') {
			if (before_x != x) { // x가 변한 상황 -> 위, 아래에서 온 상황 -> 오른쪽으로 돌기
				dir = (dir + 1) % 4;
			}
			else if (before_y != y) { // y가 변한 상황 -> 왼, 오에서 온 상황 -> 왼쪽으로 돌기
				dir = (dir + 3) % 4;
			}
			count++;
		}
		else if (v[x][y] == '\\') {
			if (before_x != x) { // x가 변한 상황 -> 위, 아래에서 온 상황 -> 왼쪽으로 돌기
				dir = (dir + 3) % 4;
			}
			else if (before_y != y) { // y가 변한 상황 -> 왼, 오에서 온 상황 -> 오른쪽으로 돌기
				dir = (dir + 1) % 4;
			}
			count++;
		}
		else {
			break;
		}
	}

	cout << count;
}

/*
/일 때
위에서 들어오면 오른쪽으로 틀기
아래에서 들어오면 오른쪽으로 틀기
왼쪽에서 들어오면 왼쪽으로 틀기
오른쪽에서 들어오면 왼쪽으로 틀기


\일 때
위에서 들어오면 왼쪽으로 틀기
아래에서 들어오면 왼쪽으로 틀기
왼쪽에서 들어오면 오른쪽으로 틀기
오른쪽에서 들어오면 오른쪽으로 틀기
*/