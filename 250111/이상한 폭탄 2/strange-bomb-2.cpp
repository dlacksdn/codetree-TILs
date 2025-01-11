#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<vector<int>> v(1001, vector<int>());
	vector<int> list(N);

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < N; i++) {
		v[list[i]].push_back(i);
	}

	int result = 0;
	for (int i = 0; i <= 1000; i++) {
		if (v[i].size() >= 2) {
			bool flag = false;
			for (int j = 0; j < v[i].size() - 1; j++) {
				if (v[i][j + 1] - v[i][j] <= K) {
					flag = true;
					break;
				}
			}

			if (flag) {
				result = max(result, i);
			}
		}
	}

	cout << result;
}