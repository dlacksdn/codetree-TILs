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

	int result = -1;
	for (int i = 1000; i >= 0; i--) {
		if (v[i].size() >= 2) {
			for (int j = 0; j < v[i].size() - 1; j++) {
				if (v[i][j + 1] - v[i][j] <= K) {
					result = i;
					break;
				}
			}

			if (result == i) {
				break;
			}
		}
	}

	cout << result;
}