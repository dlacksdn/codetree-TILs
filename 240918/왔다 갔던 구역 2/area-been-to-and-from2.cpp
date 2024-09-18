#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	int n;
	cin >> n;

	map<int, int> m; // 그라운드
	vector<pair<int, char>> v(n); // 거리 방향 저장

	
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int index = 0;
	for (int i = 0; i < n; i++) {

		if (v[i].second == 'R') {
			for (int j = 0; j < v[i].first; j++) {
				m[index++]++;
			}
			m[index]++;
		}

		
		else if (v[i].second == 'L') {
			for (int j = 0; j < v[i].first - 1; j++) {
				m[index--]++;
			}
			m[index]++;
		}
	}

	int count = 0;
	for (auto it = m.begin(); it != m.end(); ++it) {
		const auto& pair = *it; // 현재 요소

		// 현재 요소의 다음 요소에 접근
		auto next_it = next(it);

		// 다음 요소가 존재하는지 확인하고 조건 체크
		if (next_it != m.end()) {
			if (pair.second >= 2 && (*next_it).second >= 2) {
				count++;
			}
		}
	}

	cout << count;

}