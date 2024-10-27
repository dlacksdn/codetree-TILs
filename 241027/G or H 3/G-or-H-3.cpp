#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<pair<int, char>> v(10001, {0, ' '});

	for (int i = 1; i <= N; i++) {
		int loc;
		char c;
		cin >> loc >> c;

		v[loc].first = loc;
		v[loc].second = c;
	}

	int maxNum = 0;
	for (int i = 1; i <= 10000; i++) {
		int sum = 0;
		for (int j = i; j <= i + K; j++) {
			if (j > 10000) break;

			if (v[j].first != 0) {
				v[j].second == 'G' ? sum += 1 : sum += 2;
			}
		}
		maxNum = max(maxNum, sum);
		
	}

	cout << maxNum << "\n";
}