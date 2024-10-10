#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int result = 0;
	for (int i = 0; i <= n - k; i++) {
		int sum = 0;

		for (int j = i; j < i + k; j++) {
			sum += v[j];
		}

		result = max(result, sum);
	}

	cout << result;
}