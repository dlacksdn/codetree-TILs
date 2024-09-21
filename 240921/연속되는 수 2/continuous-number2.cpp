#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int count = 1;
	int maxNum = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || v[i - 1] != v[i]) {
			maxNum = max(count, maxNum);
			count = 1;
		}
		else {
			count++;
		}
		maxNum = max(count, maxNum);
	}

	cout << maxNum;
}