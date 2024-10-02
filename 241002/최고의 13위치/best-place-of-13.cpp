#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 2; j++) {
			int sum = 0;
			for (int k = 0; k < 3; k++) {
				sum += v[i][j + k];
			}
			result = max(result, sum);
		}
	}

	cout << result;
}