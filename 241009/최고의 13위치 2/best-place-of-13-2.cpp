#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool in_range(int x, int y, int n) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
	vector<vector<bool>> state(n + 1, vector<bool>(n + 1, false));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int count1 = 0;
			if (!(in_range(i, j + 1, n) && in_range(i, j + 2, n)))
				continue;

			for (int a = 0; a < 3; a++) {
				count1 += v[i][j + a];
			}

			state[i][j] = true;
			state[i][j + 1] = true;
			state[i][j + 2] = true;

			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= n; l++) {
					int count2 = 0;
					bool flag = true;
					for (int a = 0; a < 3; a++) {
						if (!(in_range(k, l + a, n) && state[k][l + a] == false)) {
							flag = false;
							break;
						}
					}
					if (flag) {
						for (int a = 0; a < 3; a++)
							count2 += v[k][l + a];

						result = max(result, count1 + count2);
					}
				}
			}
			state[i][j] = false;
			state[i][j + 1] = false;
			state[i][j + 2] = false;
		}
	}

	cout << result;
}

/*
두 번째 블럭도 처음부터 완전탐색으로 해야 한다. 첫 번째 블럭이 있는 칸에 true를 심어나서 
두 번째 블럭 선정할 때 if문 돌려서 true 뜨면 다음 걸로 넘어가게 해야 한다.
*/