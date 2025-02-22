#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	vector<int> test = v;

	sort(test.begin(), test.end());
	int first_min = test[0];

	int second_min = 0;
	for (int i = 1; i < N; i++) {
		if (first_min != test[i]) {
			if (i == N - 1 || test[i] != test[i + 1]) {
				second_min = test[i];
			}
			break;
		}
	}

	if (second_min == 0) {
		cout << -1;
	}
	else {
		auto it = find(v.begin(), v.end(), second_min);
		int index = distance(v.begin(), it);

		cout << index + 1;
	}
}