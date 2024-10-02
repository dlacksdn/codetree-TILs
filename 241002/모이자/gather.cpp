#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	int result = INT_MAX;
	for (int i = 1; i <= n; i++) { // 모이는 집 위치
		int sum = 0;

		for (int j = 1; j <= n; j++) { // 어디 집을 보고 있는가
			sum += abs(j - i) * v[j];
		}

		result = min(result, sum);
	}

	cout << result;
}