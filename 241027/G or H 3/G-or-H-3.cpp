#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v(10001, 0);

	for (int i = 1; i <= N; i++) {
		int loc; char c;
		cin >> loc >> c;

		int value = (c == 'G' ? 1 : 2);
		v[loc] = value;
	}

	int maxNum = 0;
	for (int i = 1; i <= 10000; i++) {
		int sum = 0;
		for (int j = i; j <= i + K; j++) {
			if (j > 10000) break;

			sum += v[j];
		}
		maxNum = max(maxNum, sum);
		
	}

	cout << maxNum << "\n";
}