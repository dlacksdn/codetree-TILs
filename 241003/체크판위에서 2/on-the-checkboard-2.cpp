#include <iostream>
#include <vector>
using namespace std;

int main() {
	int R, C;
	cin >> R >> C;

	vector<vector<char>> v(R + 1, vector<char>(C + 1, ' '));

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> v[i][j];
		}
	}

	int state = (v[1][1] == 'W' ? 0 : 1); // 처음이 W면 0 / B면 1

	if ((state == 0 && v[R][C] == 'W') || (state == 1 && v[R][C] == 'B')) {
		cout << 0;
		return 0;
	}

	int count = 0;
	for (int i = 2; i < R - 1; i++) { // 1행 1열은 어차피 못쓰니 2부터 시작
		for (int j = 2; j < C - 1; j++) { 
			for (int k = i + 1; k < R; k++) {
				for (int l = j + 1; l < C; l++) {
					if (state == 0) {
						if (v[i][j] == 'B' && v[k][l] == 'W')
							count++;
					}
					else if (state == 1) {
						if (v[i][j] == 'W' && v[k][l] == 'B')
							count++;
					}
				}
			}
		}
	}

	cout << count;
}