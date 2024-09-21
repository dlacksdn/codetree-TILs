#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, T;
	cin >> n >> T;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int count = 0;
	int maxNum = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] > T) {
			count++;
		}
		else {
			maxNum = max(count, maxNum);
			count = 0;
		}
		maxNum = max(count, maxNum);
	}

	cout << maxNum;
}