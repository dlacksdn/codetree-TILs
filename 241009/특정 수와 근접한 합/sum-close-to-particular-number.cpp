#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int N, S;
	cin >> N >> S;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int all_sum = 0;
	for (int i = 0; i < N; i++) {
		all_sum += v[i];
	}

	int result = INT_MAX;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int diff = all_sum - v[i] - v[j];

			result = min(result, abs(S - diff));
		}
	}

	cout << result;
}