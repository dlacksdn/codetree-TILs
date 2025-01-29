#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int result = INT_MAX;
	
	for (int i = 0; i < n; i++) { // 2배 인덱스
		v[i] *= 2;
		
		for (int j = 0; j < n; j++) { // 제거 인덱스
			int count = 0;
			int prev = -1;

			for (int k = 0; k < n; k++) {
				if (k == j) {
					continue;
				}
				
				if (prev != -1) {
					count += abs(v[k] - prev);
				}

				prev = v[k];
			}
			result = min(result, count);
		}

		v[i] /= 2;
	}

	cout << result;
}