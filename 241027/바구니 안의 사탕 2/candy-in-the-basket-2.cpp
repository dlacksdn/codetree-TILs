#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool in_range(int num) {
	return 0 <= num && num <= 100;
}

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> v(101, 0); // 0 <= 바구니 위치 <= 100
	for (int i = 0; i < N; i++) {
		int num, loc;
		cin >> num >> loc;

		v[loc] += num;
	}

	int maxNum = 0;
	for (int i = 0; i <= 100; i++) {
		int sum = 0;
		for (int j = i; j < i + (2 * K + 1); j++) {
			if (in_range(j)) {
				sum += v[j];
			}
			else break;
		}

		maxNum = max(maxNum, sum);
	}

	cout << maxNum << "\n";
}