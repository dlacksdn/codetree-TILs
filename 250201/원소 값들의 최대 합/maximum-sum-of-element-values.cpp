#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	int result = 0;
	for (int i = 1; i <= n; i++) { // i : 시작 위치

		int sum = 0;
		int location = i;
		for (int j = 0; j < m; j++) { // m번의 움직임
			sum += v[location];
			location = v[location];
		}

		result = max(result, sum);
	}

	cout << result;
}