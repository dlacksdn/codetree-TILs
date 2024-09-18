#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	map<pair<int, int>, int> m; // 그라운드
	vector<pair<int, char>> v(n); // 거리 방향 저장

	
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].first; j++) {
			int start = index;

			if (v[i].second == 'R') {
				index++;
			}
			else if (v[i].second == 'L') {
				index--;
			}

			int end = index;

			int startNum = min(start, end);
			int endNum = max(start, end);

			m[{startNum, endNum}]++;
		}
	}

	int count = 0;
	for (auto pair : m) {
		if (pair.second >= 2) {
			count++;
		}
	}

	cout << count;

}