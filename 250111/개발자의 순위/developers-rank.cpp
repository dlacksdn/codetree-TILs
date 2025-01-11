#include <iostream>
#include <vector>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;

	vector<vector<int>> v(K, vector<int>(N + 1));

	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> v[i][j];
		}
	}

	vector<vector<int>> pos(K, vector<int>(N + 1));

	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= N; j++) {
			pos[i][v[i][j]] = j;
		}
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;

			bool flag = true;
			for (int k = 0; k < K; k++) {
				if (pos[k][i] > pos[k][j]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				count++;
			}
		}
	}

	cout << count;
}