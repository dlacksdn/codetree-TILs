#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int result = INT_MAX;
	for (int i = 1; i < N - 1; i++) { // 어느 체크포인트를 건너뛸 것인가
		int sum = 0;
		int prev_index = 0;
		for (int j = 1; j < N; j++) {
			if (j == i) {
				continue;
			}
			else {
				sum += abs(v[j].first - v[prev_index].first) + abs(v[j].second - v[prev_index].second);
				prev_index = j;
			}
		}
		result = min(result, sum);
	}

	cout << result;
}