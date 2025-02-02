#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> v(m);

	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) { // i, j : 순서쌍 완전탐색

			int count = 0;
			for (int k = 0; k < m; k++) { // 주어진 순서쌍
				if ((v[k].first == i && v[k].second == j) || (v[k].first == j && v[k].second == i)) {
					count++;
				}
			}

			result = max(result, count);
		}
	}

	cout << result;
}