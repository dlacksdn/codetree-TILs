#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int result = INT_MAX;
	for (int i = 0; i < n; i++) { // 어느 방에서 시작하는지
		int sum = 0;
		for (int j = 0; j < n; j++) { // 목적지
			int distance = (j - i + n) % n;
			sum += v[j] * distance;
		}

		result = min(result, sum);
	}

	cout << result;
}