#include <iostream>	
#include <vector>
#include <climits>
using namespace std;

int main() {
	int N; // 밭의 높낮이 개수
	int H; // 목표 높이
	int T; // 최소 연속 횟수

	cin >> N >> H >> T;

	vector<int> v(N, 0);
	
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int result = INT_MAX;
	for (int i = 0; i < N - T + 1; i++) {
		int sum = 0;
		for (int j = i; j < i + T; j++) {
			int num = abs(v[j] - H);
			sum += num;
		}

		result = min(result, sum);
	}

	cout << result << "\n";
}