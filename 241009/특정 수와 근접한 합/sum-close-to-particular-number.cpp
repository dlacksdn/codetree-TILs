#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, S;
	cin >> N >> S;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int sum = 0;
	int result = 100;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (k == i || k == j) 
					continue;

				sum += v[k];
			}

			result = min(result, abs(S - sum));
			sum = 0;
		}
	}

	cout << result;
}