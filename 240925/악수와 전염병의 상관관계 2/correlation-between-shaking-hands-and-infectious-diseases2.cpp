#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValue(pair<int, pair<int, int>> left, pair<int, pair<int, int>> right) {
	return left.first < right.first;
}

int main() {
	int N; // 개발자 수
	int K; // K번의 악수 동안만 전염병을 옮긴다
	int P; // 처음 전염병에 걸려있던 개발자 번호
	int T; // 테스트 케이스

	cin >> N >> K >> P >> T;

	vector<pair<int, pair<int, int>>> v(T); // 악수 기록을 담은 리스트(시간, 개발자x, 개발자y)
	vector<pair<int, bool>> state(N + 1, {0, false}); // 각 개발자의 상태를 담은 리스트(악수 횟수, 감염 여부)
	state[P] = { 0, true };

	for (int i = 0; i < T; i++) {
		cin >> v[i].first >> v[i].second.first >> v[i].second.second;
	}

	sort(v.begin(), v.end(), isValue);

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].second.first;
		int y = v[i].second.second;

		if (state[x].second == true && state[y].second == true) { 
			state[x].first++; state[y].first++;
		}
		else if (state[x].second == true && state[y].second == false) {
			if (++(state[x].first) <= K) {
				state[y].second = true;
			}
		}
		else if (state[x].second == false && state[y].second == true) {
			if (++(state[y].first) <= K) {
				state[x].second = true;
			}
		}
		else { // 감염자가 없다

		}
	}

	for (int i = 1; i < state.size(); i++) {
		cout << state[i].second;
	}
}